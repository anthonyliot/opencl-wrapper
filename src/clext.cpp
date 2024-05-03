#include <cassert>
#include <clext.h>
#include <clwrapper.h>
#include <string>

static cl_platform_id cl_ext_platform = NULL;
static cl_device_id cl_ext_device = NULL;
static cl_context cl_ext_context = 0;
static cl_command_queue cl_ext_command_queue = NULL;
static char cl_ext_name[256] = {
    0,
};
static char cl_ext_vendor[256] = {
    0,
};
static char cl_ext_version[256] = {
    0,
};
static char cl_ext_extensions[1024] = {
    0,
};

CLExt::CLExt()
{
}

static int cl_ext_init(cl_context_properties *properties, cl_platform_id platform = NULL, cl_device_id device = NULL)
{
    assert(cl_ext_context == 0 && "CLExt::init(): is already initialized");

    cl_int result = 0;
    char vendor[1024];

    // get platform
    cl_uint num_platforms = 0;
    cl_platform_id platforms[1024] = {
        NULL,
    };
    if (platform == NULL)
    {
        // get platforms
        result = clGetPlatformIDs(sizeof(platforms) / sizeof(cl_platform_id), platforms, &num_platforms);
        if (result != CL_SUCCESS || num_platforms == 0)
        {
            printf("[ERROR] CLExt::init(): can't get platform identifiers\n");
            CLExt::error(result);
            return 0;
        }

        // select best platform
        for (cl_uint i = 0; i < num_platforms; i++)
        {
            clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(vendor), vendor, NULL);
            std::string strvendor(vendor);
            std::transform(strvendor.begin(), strvendor.end(), strvendor.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (strvendor.find("nvidia") != std::string::npos)
                cl_ext_platform = platforms[i];
        }
        if (cl_ext_platform == NULL)
        {
            for (cl_uint i = 0; i < num_platforms; i++)
            {
                clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, sizeof(vendor), vendor, NULL);
                std::string strvendor(vendor);
                std::transform(strvendor.begin(), strvendor.end(), strvendor.begin(),
                               [](unsigned char c) { return std::tolower(c); });
                if (strvendor.find("amd") != std::string::npos)
                    cl_ext_platform = platforms[i];
            }
            if (cl_ext_platform == NULL)
                cl_ext_platform = platforms[0];
        }
    }

    // explicit platform specification
    else
        cl_ext_platform = platform;

    // get device
    cl_uint num_devices = 0;
    cl_device_id devices[1024] = {
        NULL,
    };
    if (device == NULL)
    {
        // get platform devices
        result = clGetDeviceIDs(cl_ext_platform, CL_DEVICE_TYPE_GPU, sizeof(devices) / sizeof(cl_device_id), devices,
                                &num_devices);
        if (result != CL_SUCCESS || num_devices == 0)
        {
            result = clGetDeviceIDs(cl_ext_platform, CL_DEVICE_TYPE_CPU, sizeof(devices) / sizeof(cl_device_id),
                                    devices, &num_devices);
            if (result != CL_SUCCESS || num_devices == 0)
            {
                result = clGetDeviceIDs(cl_ext_platform, CL_DEVICE_TYPE_ALL, sizeof(devices) / sizeof(cl_device_id),
                                        devices, &num_devices);
                if (result != CL_SUCCESS || num_devices == 0)
                {
                    printf("[ERROR] CLExt::init(): can't get device identifiers\n");
                    CLExt::error(result);
                    return 0;
                }
            }
        }

        // select best device
        cl_uint flops = 0;
        cl_uint units, freequency;
        for (cl_uint i = 0; i < num_devices; i++)
        {
            if (clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR, sizeof(vendor), vendor, NULL) != CL_SUCCESS)
                continue;
            if (clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &units, NULL) != CL_SUCCESS)
                continue;
            if (clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_uint), &freequency, NULL) !=
                CL_SUCCESS)
                continue;

            std::string strvendor(vendor);
            std::transform(strvendor.begin(), strvendor.end(), strvendor.begin(),
                           [](unsigned char c) { return std::tolower(c); });
            if (flops <= units * freequency && strvendor.find("intel") == -1)
            {
                flops = units * freequency;
                cl_ext_device = devices[i];
            }
        }
        if (cl_ext_device == NULL)
        {
            for (cl_uint i = 0; i < num_devices; i++)
            {
                if (clGetDeviceInfo(devices[i], CL_DEVICE_VENDOR, sizeof(vendor), vendor, NULL) != CL_SUCCESS)
                    continue;
                if (clGetDeviceInfo(devices[i], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &units, NULL) !=
                    CL_SUCCESS)
                    continue;
                if (clGetDeviceInfo(devices[i], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(cl_uint), &freequency, NULL) !=
                    CL_SUCCESS)
                    continue;
                if (flops <= units * freequency)
                {
                    flops = units * freequency;
                    cl_ext_device = devices[i];
                }
            }
            if (cl_ext_device == NULL)
                cl_ext_device = devices[0];
        }
    }

    // explicit device specification
    else
        cl_ext_device = device;

    // context platform
    cl_context_properties *prop = properties;
    while (*prop != 0 && *prop != CL_CONTEXT_PLATFORM)
        prop++;
    *prop++ = CL_CONTEXT_PLATFORM;
    *prop++ = (cl_context_properties)cl_ext_platform;

    // create context
    cl_ext_context = clCreateContext(properties, 1, &cl_ext_device, NULL, NULL, &result);
    if (result != CL_SUCCESS)
    {
        if (platform != NULL && device == NULL)
        {
            for (cl_uint i = 0; i < num_devices; i++)
            {
                if (cl_ext_init(properties, platform, devices[i]))
                    return 1;
            }
        }
        else if (platform == NULL)
        {
            for (cl_uint i = 0; i < num_platforms; i++)
            {
                if (cl_ext_init(properties, platforms[i]))
                    return 1;
            }
            printf("[ERROR] CLExt::init(): can't create context\n");
            CLExt::error(result);
        }
        cl_ext_platform = NULL;
        cl_ext_device = NULL;
        cl_ext_context = NULL;
        return 0;
    }

    // create command queue
    cl_ext_command_queue = clCreateCommandQueue(cl_ext_context, cl_ext_device, 0, &result);
    if (result != CL_SUCCESS)
    {
        printf("[ERROR] CLExt::init(): can't create command queue\n");
        clReleaseContext(cl_ext_context);
        CLExt::error(result);
        cl_ext_platform = NULL;
        cl_ext_device = NULL;
        cl_ext_context = NULL;
        return 0;
    }

    // get device info
    clGetDeviceInfo(cl_ext_device, CL_DEVICE_NAME, sizeof(cl_ext_name), cl_ext_name, NULL);
    clGetDeviceInfo(cl_ext_device, CL_DEVICE_VENDOR, sizeof(cl_ext_vendor), cl_ext_vendor, NULL);
    clGetDeviceInfo(cl_ext_device, CL_DEVICE_VERSION, sizeof(cl_ext_version), cl_ext_version, NULL);
    clGetDeviceInfo(cl_ext_device, CL_DEVICE_EXTENSIONS, sizeof(cl_ext_extensions), cl_ext_extensions, NULL);

    return 1;
}

int CLExt::init()
{
    assert(cl_ext_context == 0 && "CLExt::init(): is already initialized");

    if (CLWrapper::init() == 0)
        return 0;

    cl_context_properties properties[128];
    memset(properties, 0, sizeof(properties));

    return cl_ext_init(properties, NULL);
}

int CLExt::shutdown()
{
    if (cl_ext_context)
    {
        clReleaseCommandQueue(cl_ext_command_queue);
        clReleaseContext(cl_ext_context);
    }

    cl_ext_platform = NULL;
    cl_ext_device = NULL;
    cl_ext_context = 0;
    cl_ext_command_queue = NULL;
    memset(cl_ext_name, 0, sizeof(cl_ext_name));
    memset(cl_ext_vendor, 0, sizeof(cl_ext_vendor));
    memset(cl_ext_version, 0, sizeof(cl_ext_version));
    memset(cl_ext_extensions, 0, sizeof(cl_ext_extensions));

    CLWrapper::shutdown();

    return 1;
}

int CLExt::isInitialized()
{
    return (cl_ext_context != 0);
}

cl_platform_id CLExt::getPlatform()
{
    assert(cl_ext_context != 0 && "CLExt::getPlatform(): context is NULL");
    return cl_ext_platform;
}

cl_device_id CLExt::getDevice()
{
    assert(cl_ext_context != 0 && "CLExt::getDevice(): context is NULL");
    return cl_ext_device;
}

cl_context CLExt::getContext()
{
    assert(cl_ext_context != 0 && "CLExt::getContext(): context is NULL");
    return cl_ext_context;
}

cl_command_queue CLExt::getQueue()
{
    assert(cl_ext_context != 0 && "CLExt::getQueue(): context is NULL");
    return cl_ext_command_queue;
}

const char *CLExt::getName()
{
    return cl_ext_name;
}

const char *CLExt::getVendor()
{
    return cl_ext_vendor;
}

const char *CLExt::getVersion()
{
    return cl_ext_version;
}

const char *CLExt::getExtensions()
{
    return cl_ext_extensions;
}

int CLExt::error(cl_int result)
{
    if (result == CL_SUCCESS)
        return 0;
    if (result == CL_DEVICE_NOT_FOUND)
        printf("[ERROR] OpenCL error: device not found\n");
    else if (result == CL_DEVICE_NOT_AVAILABLE)
        printf("[ERROR] OpenCL error: device not available\n");
    else if (result == CL_COMPILER_NOT_AVAILABLE)
        printf("[ERROR] OpenCL error: compiler not available\n");
    else if (result == CL_MEM_OBJECT_ALLOCATION_FAILURE)
        printf("[ERROR] OpenCL error: mem object allocation failure\n");
    else if (result == CL_OUT_OF_RESOURCES)
        printf("[ERROR] OpenCL error: out of resources\n");
    else if (result == CL_OUT_OF_HOST_MEMORY)
        printf("[ERROR] OpenCL error: out of host memory\n");
    else if (result == CL_PROFILING_INFO_NOT_AVAILABLE)
        printf("[ERROR] OpenCL error: profiling info not available\n");
    else if (result == CL_MEM_COPY_OVERLAP)
        printf("[ERROR] OpenCL error: mem copy overlap\n");
    else if (result == CL_IMAGE_FORMAT_MISMATCH)
        printf("[ERROR] OpenCL error: image format mismatch\n");
    else if (result == CL_IMAGE_FORMAT_NOT_SUPPORTED)
        printf("[ERROR] OpenCL error: image format not supported\n");
    else if (result == CL_BUILD_PROGRAM_FAILURE)
        printf("[ERROR] OpenCL error: build program failure\n");
    else if (result == CL_MAP_FAILURE)
        printf("[ERROR] OpenCL error: map failure\n");
    else if (result == CL_MISALIGNED_SUB_BUFFER_OFFSET)
        printf("[ERROR] OpenCL error: misaligned sub buffer offset\n");
    else if (result == CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST)
        printf("[ERROR] OpenCL error: exec status error for events in wait list\n");
    else if (result == CL_INVALID_VALUE)
        printf("[ERROR] OpenCL error: invalid value\n");
    else if (result == CL_INVALID_DEVICE_TYPE)
        printf("[ERROR] OpenCL error: invalid device type\n");
    else if (result == CL_INVALID_PLATFORM)
        printf("[ERROR] OpenCL error: invalid platform\n");
    else if (result == CL_INVALID_DEVICE)
        printf("[ERROR] OpenCL error: invalid device\n");
    else if (result == CL_INVALID_CONTEXT)
        printf("[ERROR] OpenCL error: invalid context\n");
    else if (result == CL_INVALID_QUEUE_PROPERTIES)
        printf("[ERROR] OpenCL error: invalid queue properties\n");
    else if (result == CL_INVALID_COMMAND_QUEUE)
        printf("[ERROR] OpenCL error: invalid command queue\n");
    else if (result == CL_INVALID_HOST_PTR)
        printf("[ERROR] OpenCL error: invalid host ptr\n");
    else if (result == CL_INVALID_MEM_OBJECT)
        printf("[ERROR] OpenCL error: invalid mem object\n");
    else if (result == CL_INVALID_IMAGE_FORMAT_DESCRIPTOR)
        printf("[ERROR] OpenCL error: invalid image format descriptor\n");
    else if (result == CL_INVALID_IMAGE_SIZE)
        printf("[ERROR] OpenCL error: invalid image size\n");
    else if (result == CL_INVALID_SAMPLER)
        printf("[ERROR] OpenCL error: invalid sampler\n");
    else if (result == CL_INVALID_BINARY)
        printf("[ERROR] OpenCL error: invalid binary\n");
    else if (result == CL_INVALID_BUILD_OPTIONS)
        printf("[ERROR] OpenCL error: invalid build options\n");
    else if (result == CL_INVALID_PROGRAM)
        printf("[ERROR] OpenCL error: invalid program\n");
    else if (result == CL_INVALID_PROGRAM_EXECUTABLE)
        printf("[ERROR] OpenCL error: invalid program executable\n");
    else if (result == CL_INVALID_KERNEL_NAME)
        printf("[ERROR] OpenCL error: invalid kernel name\n");
    else if (result == CL_INVALID_KERNEL_DEFINITION)
        printf("[ERROR] OpenCL error: invalid kernel definition\n");
    else if (result == CL_INVALID_KERNEL)
        printf("[ERROR] OpenCL error: invalid kernel\n");
    else if (result == CL_INVALID_ARG_INDEX)
        printf("[ERROR] OpenCL error: invalid arg index\n");
    else if (result == CL_INVALID_ARG_VALUE)
        printf("[ERROR] OpenCL error: invalid arg value\n");
    else if (result == CL_INVALID_ARG_SIZE)
        printf("[ERROR] OpenCL error: invalid arg size\n");
    else if (result == CL_INVALID_KERNEL_ARGS)
        printf("[ERROR] OpenCL error: invalid kernel args\n");
    else if (result == CL_INVALID_WORK_DIMENSION)
        printf("[ERROR] OpenCL error: invalid work dimension\n");
    else if (result == CL_INVALID_WORK_GROUP_SIZE)
        printf("[ERROR] OpenCL error: invalid work group size\n");
    else if (result == CL_INVALID_WORK_ITEM_SIZE)
        printf("[ERROR] OpenCL error: invalid work item size\n");
    else if (result == CL_INVALID_GLOBAL_OFFSET)
        printf("[ERROR] OpenCL error: invalid global offset\n");
    else if (result == CL_INVALID_EVENT_WAIT_LIST)
        printf("[ERROR] OpenCL error: invalid event wait list\n");
    else if (result == CL_INVALID_EVENT)
        printf("[ERROR] OpenCL error: invalid event\n");
    else if (result == CL_INVALID_OPERATION)
        printf("[ERROR] OpenCL error: invalid operation\n");
    else if (result == CL_INVALID_GL_OBJECT)
        printf("[ERROR] OpenCL error: invalid gl object\n");
    else if (result == CL_INVALID_BUFFER_SIZE)
        printf("[ERROR] OpenCL error: invalid buffer size\n");
    else if (result == CL_INVALID_MIP_LEVEL)
        printf("[ERROR] OpenCL error: invalid mip level\n");
    else if (result == CL_INVALID_GLOBAL_WORK_SIZE)
        printf("[ERROR] OpenCL error: invalid global work size\n");
    else if (result == CL_INVALID_PROPERTY)
        printf("[ERROR] OpenCL error: invalid property\n");
    else
        printf("[ERROR] OpenCL error: 0x%04X\n", result);
    return 1;
}
