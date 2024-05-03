#include <clwrapper.h>
#include <cstdlib>
#include <stdio.h>

int main(int argc, char **argv)
{
    // OPENCL CONTEXT
    if (!CLWrapper::init())
    {
        printf("[ERROR] Failed creating OpenCL Wrapper.\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("[DEBUG] OpenCL Wrapper created:\n");
        printf("[DEBUG] \n");
        int i, j;
        char *value;
        size_t valueSize;
        cl_uint platformCount;
        cl_platform_id *platforms;
        cl_uint deviceCount;
        cl_device_id *devices;
        cl_uint maxComputeUnits;
        // get all platforms
        clGetPlatformIDs(0, NULL, &platformCount);
        platforms = (cl_platform_id *)malloc(sizeof(cl_platform_id) * platformCount);
        clGetPlatformIDs(platformCount, platforms, NULL);
        for (i = 0; i < platformCount; i++)
        {
            // get all devices
            clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &deviceCount);
            devices = (cl_device_id *)malloc(sizeof(cl_device_id) * deviceCount);
            clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, deviceCount, devices, NULL);
            // for each device print critical attributes
            for (j = 0; j < deviceCount; j++)
            {
                // print device name
                clGetDeviceInfo(devices[j], CL_DEVICE_NAME, 0, NULL, &valueSize);
                value = (char *)malloc(valueSize);
                clGetDeviceInfo(devices[j], CL_DEVICE_NAME, valueSize, value, NULL);
                printf("[DEBUG] %d. Device: %s\n", j + 1, value);
                free(value);
                // print hardware device version
                clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, 0, NULL, &valueSize);
                value = (char *)malloc(valueSize);
                clGetDeviceInfo(devices[j], CL_DEVICE_VERSION, valueSize, value, NULL);
                printf("[DEBUG]  %d.%d Hardware version: %s\n", j + 1, 1, value);
                free(value);
                // print software driver version
                clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, 0, NULL, &valueSize);
                value = (char *)malloc(valueSize);
                clGetDeviceInfo(devices[j], CL_DRIVER_VERSION, valueSize, value, NULL);
                printf("[DEBUG]  %d.%d Software version: %s\n", j + 1, 2, value);
                free(value);
                // print c version supported by compiler for device
                clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, 0, NULL, &valueSize);
                value = (char *)malloc(valueSize);
                clGetDeviceInfo(devices[j], CL_DEVICE_OPENCL_C_VERSION, valueSize, value, NULL);
                printf("[DEBUG]  %d.%d OpenCL C version: %s\n", j + 1, 3, value);
                free(value);
                // print parallel compute units
                clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(maxComputeUnits), &maxComputeUnits,
                                NULL);
                printf("[DEBUG]  %d.%d Parallel compute units: %d\n", j + 1, 4, maxComputeUnits);
            }
            free(devices);
        }
        free(platforms);
        printf("[DEBUG] \n");
    }

    return EXIT_SUCCESS;
}
