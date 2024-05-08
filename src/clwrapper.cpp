
#include <cassert>
#include <clwrapper.h>
#include <dlfcn.h>
#include <stdio.h>

cl_int(CL_API_CALL *CL_PROC_NAME(clGetPlatformIDs))(cl_uint num_entries, cl_platform_id *platforms,
                                                    cl_uint *num_platforms) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetPlatformInfo))(cl_platform_id platform, cl_platform_info param_name,
                                                     size_t param_value_size, void *param_value,
                                                     size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetDeviceIDs))(cl_platform_id platform, cl_device_type device_type,
                                                  cl_uint num_entries, cl_device_id *devices,
                                                  cl_uint *num_devices) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetDeviceInfo))(cl_device_id device, cl_device_info param_name,
                                                   size_t param_value_size, void *param_value,
                                                   size_t *param_value_size_ret) = NULL;
cl_context(CL_API_CALL *CL_PROC_NAME(clCreateContext))(const cl_context_properties *properties, cl_uint num_devices,
                                                       const cl_device_id *devices,
                                                       void(CL_CALLBACK *pfn_notify)(const char *, const void *, size_t,
                                                                                     void *),
                                                       void *user_data, cl_int *errcode_ret) = NULL;
cl_context(CL_API_CALL *CL_PROC_NAME(clCreateContextFromType))(const cl_context_properties *properties,
                                                               cl_device_type device_type,
                                                               void(CL_CALLBACK *pfn_notify)(const char *, const void *,
                                                                                             size_t, void *),
                                                               void *user_data, cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainContext))(cl_context context) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseContext))(cl_context context) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetContextInfo))(cl_context context, cl_context_info param_name,
                                                    size_t param_value_size, void *param_value,
                                                    size_t *param_value_size_ret) = NULL;
cl_command_queue(CL_API_CALL *CL_PROC_NAME(clCreateCommandQueue))(cl_context context, cl_device_id device,
                                                                  cl_command_queue_properties properties,
                                                                  cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainCommandQueue))(cl_command_queue command_queue) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseCommandQueue))(cl_command_queue command_queue) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetCommandQueueInfo))(cl_command_queue command_queue,
                                                         cl_command_queue_info param_name, size_t param_value_size,
                                                         void *param_value, size_t *param_value_size_ret) = NULL;
cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateBuffer))(cl_context context, cl_mem_flags flags, size_t size, void *host_ptr,
                                                  cl_int *errcode_ret) = NULL;
cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateSubBuffer))(cl_mem buffer, cl_mem_flags flags,
                                                     cl_buffer_create_type buffer_create_type,
                                                     const void *buffer_create_info, cl_int *errcode_ret) = NULL;
cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateImage2D))(cl_context context, cl_mem_flags flags,
                                                   const cl_image_format *image_format, size_t image_width,
                                                   size_t image_height, size_t image_row_pitch, void *host_ptr,
                                                   cl_int *errcode_ret) = NULL;
cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateImage3D))(cl_context context, cl_mem_flags flags,
                                                   const cl_image_format *image_format, size_t image_width,
                                                   size_t image_height, size_t image_depth, size_t image_row_pitch,
                                                   size_t image_slice_pitch, void *host_ptr,
                                                   cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainMemObject))(cl_mem memobj) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseMemObject))(cl_mem memobj) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetSupportedImageFormats))(cl_context context, cl_mem_flags flags,
                                                              cl_mem_object_type image_type, cl_uint num_entries,
                                                              cl_image_format *image_formats,
                                                              cl_uint *num_image_formats) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetMemObjectInfo))(cl_mem memobj, cl_mem_info param_name, size_t param_value_size,
                                                      void *param_value, size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetImageInfo))(cl_mem image, cl_image_info param_name, size_t param_value_size,
                                                  void *param_value, size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clSetMemObjectDestructorCallback))(
    cl_mem memobj, void(CL_CALLBACK *pfn_notify)(cl_mem memobj, void *user_data), void *user_data) = NULL;
cl_sampler(CL_API_CALL *CL_PROC_NAME(clCreateSampler))(cl_context context, cl_bool normalized_coords,
                                                       cl_addressing_mode addressing_mode, cl_filter_mode filter_mode,
                                                       cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainSampler))(cl_sampler sampler) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseSampler))(cl_sampler sampler) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetSamplerInfo))(cl_sampler sampler, cl_sampler_info param_name,
                                                    size_t param_value_size, void *param_value,
                                                    size_t *param_value_size_ret) = NULL;
cl_program(CL_API_CALL *CL_PROC_NAME(clCreateProgramWithSource))(cl_context context, cl_uint count,
                                                                 const char **strings, const size_t *lengths,
                                                                 cl_int *errcode_ret) = NULL;
cl_program(CL_API_CALL *CL_PROC_NAME(clCreateProgramWithBinary))(cl_context context, cl_uint num_devices,
                                                                 const cl_device_id *device_list, const size_t *lengths,
                                                                 const unsigned char **binaries, cl_int *binary_status,
                                                                 cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainProgram))(cl_program program) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseProgram))(cl_program program) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clBuildProgram))(cl_program program, cl_uint num_devices,
                                                  const cl_device_id *device_list, const char *options,
                                                  void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
                                                  void *user_data) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clUnloadCompiler))(void) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetProgramInfo))(cl_program program, cl_program_info param_name,
                                                    size_t param_value_size, void *param_value,
                                                    size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetProgramBuildInfo))(cl_program program, cl_device_id device,
                                                         cl_program_build_info param_name, size_t param_value_size,
                                                         void *param_value, size_t *param_value_size_ret) = NULL;
cl_kernel(CL_API_CALL *CL_PROC_NAME(clCreateKernel))(cl_program program, const char *kernel_name,
                                                     cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clCreateKernelsInProgram))(cl_program program, cl_uint num_kernels, cl_kernel *kernels,
                                                            cl_uint *num_kernels_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainKernel))(cl_kernel kernel) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseKernel))(cl_kernel kernel) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clSetKernelArg))(cl_kernel kernel, cl_uint arg_index, size_t arg_size,
                                                  const void *arg_value) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetKernelInfo))(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size,
                                                   void *param_value, size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetKernelWorkGroupInfo))(cl_kernel kernel, cl_device_id device,
                                                            cl_kernel_work_group_info param_name,
                                                            size_t param_value_size, void *param_value,
                                                            size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clWaitForEvents))(cl_uint num_events, const cl_event *event_list) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetEventInfo))(cl_event event, cl_event_info param_name, size_t param_value_size,
                                                  void *param_value, size_t *param_value_size_ret) = NULL;
cl_event(CL_API_CALL *CL_PROC_NAME(clCreateUserEvent))(cl_context context, cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clRetainEvent))(cl_event event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseEvent))(cl_event event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clSetUserEventStatus))(cl_event event, cl_int execution_status) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clSetEventCallback))(cl_event event, cl_int command_exec_callback_type,
                                                      void(CL_CALLBACK *pfn_notify)(cl_event, cl_int, void *),
                                                      void *user_data) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clGetEventProfilingInfo))(cl_event event, cl_profiling_info param_name,
                                                           size_t param_value_size, void *param_value,
                                                           size_t *param_value_size_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clFlush))(cl_command_queue command_queue) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clFinish))(cl_command_queue command_queue) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueReadBuffer))(cl_command_queue command_queue, cl_mem buffer,
                                                       cl_bool blocking_read, size_t offset, size_t cb, void *ptr,
                                                       cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                                                       cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueReadBufferRect))(cl_command_queue command_queue, cl_mem buffer,
                                                           cl_bool blocking_read, const size_t *buffer_origin,
                                                           const size_t *host_origin, const size_t *region,
                                                           size_t buffer_row_pitch, size_t buffer_slice_pitch,
                                                           size_t host_row_pitch, size_t host_slice_pitch, void *ptr,
                                                           cl_uint num_events_in_wait_list,
                                                           const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWriteBuffer))(cl_command_queue command_queue, cl_mem buffer,
                                                        cl_bool blocking_write, size_t offset, size_t cb,
                                                        const void *ptr, cl_uint num_events_in_wait_list,
                                                        const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWriteBufferRect))(cl_command_queue command_queue, cl_mem buffer,
                                                            cl_bool blocking_write, const size_t *buffer_origin,
                                                            const size_t *host_origin, const size_t *region,
                                                            size_t buffer_row_pitch, size_t buffer_slice_pitch,
                                                            size_t host_row_pitch, size_t host_slice_pitch,
                                                            const void *ptr, cl_uint num_events_in_wait_list,
                                                            const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyBuffer))(cl_command_queue command_queue, cl_mem src_buffer,
                                                       cl_mem dst_buffer, size_t src_offset, size_t dst_offset,
                                                       size_t cb, cl_uint num_events_in_wait_list,
                                                       const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueReadImage))(cl_command_queue command_queue, cl_mem image,
                                                      cl_bool blocking_read, const size_t *origin, const size_t *region,
                                                      size_t row_pitch, size_t slice_pitch, void *ptr,
                                                      cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                                                      cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWriteImage))(cl_command_queue command_queue, cl_mem image,
                                                       cl_bool blocking_write, const size_t *origin,
                                                       const size_t *region, size_t input_row_pitch,
                                                       size_t input_slice_pitch, const void *ptr,
                                                       cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                                                       cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyImage))(cl_command_queue command_queue, cl_mem src_image,
                                                      cl_mem dst_image, const size_t *src_origin,
                                                      const size_t *dst_origin, const size_t *region,
                                                      cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                                                      cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyImageToBuffer))(cl_command_queue command_queue, cl_mem src_image,
                                                              cl_mem dst_buffer, const size_t *src_origin,
                                                              const size_t *region, size_t dst_offset,
                                                              cl_uint num_events_in_wait_list,
                                                              const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyBufferToImage))(cl_command_queue command_queue, cl_mem src_buffer,
                                                              cl_mem dst_image, size_t src_offset,
                                                              const size_t *dst_origin, const size_t *region,
                                                              cl_uint num_events_in_wait_list,
                                                              const cl_event *event_wait_list, cl_event *event) = NULL;
void *(CL_API_CALL *CL_PROC_NAME(clEnqueueMapBuffer))(cl_command_queue command_queue, cl_mem buffer,
                                                      cl_bool blocking_map, cl_map_flags map_flags, size_t offset,
                                                      size_t cb, cl_uint num_events_in_wait_list,
                                                      const cl_event *event_wait_list, cl_event *event,
                                                      cl_int *errcode_ret) = NULL;
void *(CL_API_CALL *CL_PROC_NAME(clEnqueueMapImage))(cl_command_queue command_queue, cl_mem image, cl_bool blocking_map,
                                                     cl_map_flags map_flags, const size_t *origin, const size_t *region,
                                                     size_t *image_row_pitch, size_t *image_slice_pitch,
                                                     cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                                                     cl_event *event, cl_int *errcode_ret) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueUnmapMemObject))(cl_command_queue command_queue, cl_mem memobj,
                                                           void *mapped_ptr, cl_uint num_events_in_wait_list,
                                                           const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueNDRangeKernel))(cl_command_queue command_queue, cl_kernel kernel,
                                                          cl_uint work_dim, const size_t *global_work_offset,
                                                          const size_t *global_work_size, const size_t *local_work_size,
                                                          cl_uint num_events_in_wait_list,
                                                          const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueTask))(cl_command_queue command_queue, cl_kernel kernel,
                                                 cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
                                                 cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueNativeKernel))(cl_command_queue command_queue, void (*user_func)(void *),
                                                         void *args, size_t cb_args, cl_uint num_mem_objects,
                                                         const cl_mem *mem_list, const void **args_mem_loc,
                                                         cl_uint num_events_in_wait_list,
                                                         const cl_event *event_wait_list, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueMarker))(cl_command_queue command_queue, cl_event *event) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWaitForEvents))(cl_command_queue command_queue, cl_uint num_events,
                                                          const cl_event *event_list) = NULL;
cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueBarrier))(cl_command_queue command_queue) = NULL;
void *(CL_API_CALL *CL_PROC_NAME(clGetExtensionFunctionAddress))(const char *func_name) = NULL;

#ifdef __APPLE__
static const char *cl_name = "/System/Library/Frameworks/OpenCL.framework/OpenCL";
static void *cl_handle = NULL;
#else
static const char *cl_name = "libOpenCL.so.1";
static void *cl_handle = NULL;
#endif

CLWrapper::CLWrapper()
{
}

int CLWrapper::init()
{
    assert(cl_handle == NULL && "CLWrapper::init(): is already initialized");

    // printf("[DEBUG] Loading \"%s\"...\n", cl_name);

#ifdef EMSCRIPTEN
    // No need to dlopen in emscripten
    return 1;
#elif __APPLE__
    cl_handle = dlopen(cl_name, RTLD_LAZY);
#else
    cl_handle = dlopen(cl_name, RTLD_LAZY | RTLD_DEEPBIND);
#endif
    if (cl_handle == NULL)
    {
        printf("[ERROR] CLWrapper::init(): can't load \"%s\" library\n%s\n", cl_name, dlerror());
        return 0;
    }
#define GET_PROC_ADDRESS(NAME)                                                                                         \
    {                                                                                                                  \
        void *address = dlsym(cl_handle, #NAME);                                                                       \
        if (address == NULL)                                                                                           \
            printf("[WARN] CLWrapper::init(): can't find \"%s\" function in \"%s\" library\n", #NAME, cl_name);        \
        *((unsigned char **)&cl_##NAME) = (unsigned char *)address;                                                    \
    }

#define GET_EXT_PROC_ADDRESS(NAME)                                                                                     \
    {                                                                                                                  \
        if (cl_clGetExtensionFunctionAddress != NULL)                                                                  \
        {                                                                                                              \
            void *address = cl_clGetExtensionFunctionAddress(#NAME);                                                   \
            if (address == NULL)                                                                                       \
                address = cl_clGetExtensionFunctionAddress(#NAME "KHR");                                               \
            if (address == NULL)                                                                                       \
                address = cl_clGetExtensionFunctionAddress(#NAME "NV");                                                \
            *((unsigned char **)&cl_##NAME) = (unsigned char *)address;                                                \
        }                                                                                                              \
    }

    GET_PROC_ADDRESS(clGetPlatformIDs)
    GET_PROC_ADDRESS(clGetPlatformInfo)
    GET_PROC_ADDRESS(clGetDeviceIDs)
    GET_PROC_ADDRESS(clGetDeviceInfo)
    GET_PROC_ADDRESS(clCreateContext)
    GET_PROC_ADDRESS(clCreateContextFromType)
    GET_PROC_ADDRESS(clRetainContext)
    GET_PROC_ADDRESS(clReleaseContext)
    GET_PROC_ADDRESS(clGetContextInfo)
    GET_PROC_ADDRESS(clCreateCommandQueue)
    GET_PROC_ADDRESS(clRetainCommandQueue)
    GET_PROC_ADDRESS(clReleaseCommandQueue)
    GET_PROC_ADDRESS(clGetCommandQueueInfo)
    GET_PROC_ADDRESS(clCreateBuffer)
    GET_PROC_ADDRESS(clCreateSubBuffer)
    GET_PROC_ADDRESS(clCreateImage2D)
    GET_PROC_ADDRESS(clCreateImage3D)
    GET_PROC_ADDRESS(clRetainMemObject)
    GET_PROC_ADDRESS(clReleaseMemObject)
    GET_PROC_ADDRESS(clGetSupportedImageFormats)
    GET_PROC_ADDRESS(clGetMemObjectInfo)
    GET_PROC_ADDRESS(clGetImageInfo)
    GET_PROC_ADDRESS(clSetMemObjectDestructorCallback)
    GET_PROC_ADDRESS(clCreateSampler)
    GET_PROC_ADDRESS(clRetainSampler)
    GET_PROC_ADDRESS(clReleaseSampler)
    GET_PROC_ADDRESS(clGetSamplerInfo)
    GET_PROC_ADDRESS(clCreateProgramWithSource)
    GET_PROC_ADDRESS(clCreateProgramWithBinary)
    GET_PROC_ADDRESS(clRetainProgram)
    GET_PROC_ADDRESS(clReleaseProgram)
    GET_PROC_ADDRESS(clBuildProgram)
    GET_PROC_ADDRESS(clUnloadCompiler)
    GET_PROC_ADDRESS(clGetProgramInfo)
    GET_PROC_ADDRESS(clGetProgramBuildInfo)
    GET_PROC_ADDRESS(clCreateKernel)
    GET_PROC_ADDRESS(clCreateKernelsInProgram)
    GET_PROC_ADDRESS(clRetainKernel)
    GET_PROC_ADDRESS(clReleaseKernel)
    GET_PROC_ADDRESS(clSetKernelArg)
    GET_PROC_ADDRESS(clGetKernelInfo)
    GET_PROC_ADDRESS(clGetKernelWorkGroupInfo)
    GET_PROC_ADDRESS(clWaitForEvents)
    GET_PROC_ADDRESS(clGetEventInfo)
    GET_PROC_ADDRESS(clCreateUserEvent)
    GET_PROC_ADDRESS(clRetainEvent)
    GET_PROC_ADDRESS(clReleaseEvent)
    GET_PROC_ADDRESS(clSetUserEventStatus)
    GET_PROC_ADDRESS(clSetEventCallback)
    GET_PROC_ADDRESS(clGetEventProfilingInfo)
    GET_PROC_ADDRESS(clFlush)
    GET_PROC_ADDRESS(clFinish)
    GET_PROC_ADDRESS(clEnqueueReadBuffer)
    GET_PROC_ADDRESS(clEnqueueReadBufferRect)
    GET_PROC_ADDRESS(clEnqueueWriteBuffer)
    GET_PROC_ADDRESS(clEnqueueWriteBufferRect)
    GET_PROC_ADDRESS(clEnqueueCopyBuffer)
    GET_PROC_ADDRESS(clEnqueueReadImage)
    GET_PROC_ADDRESS(clEnqueueWriteImage)
    GET_PROC_ADDRESS(clEnqueueCopyImage)
    GET_PROC_ADDRESS(clEnqueueCopyImageToBuffer)
    GET_PROC_ADDRESS(clEnqueueCopyBufferToImage)
    GET_PROC_ADDRESS(clEnqueueMapBuffer)
    GET_PROC_ADDRESS(clEnqueueMapImage)
    GET_PROC_ADDRESS(clEnqueueUnmapMemObject)
    GET_PROC_ADDRESS(clEnqueueNDRangeKernel)
    GET_PROC_ADDRESS(clEnqueueTask)
    GET_PROC_ADDRESS(clEnqueueNativeKernel)
    GET_PROC_ADDRESS(clEnqueueMarker)
    GET_PROC_ADDRESS(clEnqueueWaitForEvents)
    GET_PROC_ADDRESS(clEnqueueBarrier)
    GET_PROC_ADDRESS(clGetExtensionFunctionAddress)

#undef GET_PROC_ADDRESS
#undef GET_EXT_PROC_ADDRESS

    return 1;
}

int CLWrapper::shutdown()
{
#ifndef EMSCRIPTEN
    if (cl_handle != NULL)
    {
        // printf("[DEBUG] Close \"%s\"\n", cl_name);
        dlclose(cl_handle);
        cl_handle = NULL;
    }
#endif
    return 1;
}

int CLWrapper::isInitialized()
{
#ifndef EMSCRIPTEN
    return (cl_handle != NULL);
#endif
    return 1;
}
