#pragma once

class CLWrapper
{
  public:
    static int init();
    static int shutdown();
    static int isInitialized();

  private:
    CLWrapper();
};

#include <CL/cl.h>

//////////////////////////////////////////////////////////////////////////
// OpenCL functions
//////////////////////////////////////////////////////////////////////////

#ifndef CL_PROC_NAME
#define CL_PROC_NAME(NAME) cl_##NAME
#endif

extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetPlatformIDs))(cl_uint num_entries, cl_platform_id *platforms,
                                                           cl_uint *num_platforms);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetPlatformInfo))(cl_platform_id platform, cl_platform_info param_name,
                                                            size_t param_value_size, void *param_value,
                                                            size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetDeviceIDs))(cl_platform_id platform, cl_device_type device_type,
                                                         cl_uint num_entries, cl_device_id *devices,
                                                         cl_uint *num_devices);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetDeviceInfo))(cl_device_id device, cl_device_info param_name,
                                                          size_t param_value_size, void *param_value,
                                                          size_t *param_value_size_ret);
extern cl_context(CL_API_CALL *CL_PROC_NAME(clCreateContext))(
    const cl_context_properties *properties, cl_uint num_devices, const cl_device_id *devices,
    void(CL_CALLBACK *pfn_notify)(const char *, const void *, size_t, void *), void *user_data, cl_int *errcode_ret);
extern cl_context(CL_API_CALL *CL_PROC_NAME(clCreateContextFromType))(
    const cl_context_properties *properties, cl_device_type device_type,
    void(CL_CALLBACK *pfn_notify)(const char *, const void *, size_t, void *), void *user_data, cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainContext))(cl_context context);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseContext))(cl_context context);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetContextInfo))(cl_context context, cl_context_info param_name,
                                                           size_t param_value_size, void *param_value,
                                                           size_t *param_value_size_ret);
extern cl_command_queue(CL_API_CALL *CL_PROC_NAME(clCreateCommandQueue))(cl_context context, cl_device_id device,
                                                                         cl_command_queue_properties properties,
                                                                         cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainCommandQueue))(cl_command_queue command_queue);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseCommandQueue))(cl_command_queue command_queue);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetCommandQueueInfo))(cl_command_queue command_queue,
                                                                cl_command_queue_info param_name,
                                                                size_t param_value_size, void *param_value,
                                                                size_t *param_value_size_ret);
extern cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateBuffer))(cl_context context, cl_mem_flags flags, size_t size,
                                                         void *host_ptr, cl_int *errcode_ret);
extern cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateSubBuffer))(cl_mem buffer, cl_mem_flags flags,
                                                            cl_buffer_create_type buffer_create_type,
                                                            const void *buffer_create_info, cl_int *errcode_ret);
extern cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateImage2D))(cl_context context, cl_mem_flags flags,
                                                          const cl_image_format *image_format, size_t image_width,
                                                          size_t image_height, size_t image_row_pitch, void *host_ptr,
                                                          cl_int *errcode_ret);
extern cl_mem(CL_API_CALL *CL_PROC_NAME(clCreateImage3D))(cl_context context, cl_mem_flags flags,
                                                          const cl_image_format *image_format, size_t image_width,
                                                          size_t image_height, size_t image_depth,
                                                          size_t image_row_pitch, size_t image_slice_pitch,
                                                          void *host_ptr, cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainMemObject))(cl_mem memobj);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseMemObject))(cl_mem memobj);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetSupportedImageFormats))(cl_context context, cl_mem_flags flags,
                                                                     cl_mem_object_type image_type, cl_uint num_entries,
                                                                     cl_image_format *image_formats,
                                                                     cl_uint *num_image_formats);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetMemObjectInfo))(cl_mem memobj, cl_mem_info param_name,
                                                             size_t param_value_size, void *param_value,
                                                             size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetImageInfo))(cl_mem image, cl_image_info param_name,
                                                         size_t param_value_size, void *param_value,
                                                         size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clSetMemObjectDestructorCallback))(
    cl_mem memobj, void(CL_CALLBACK *pfn_notify)(cl_mem memobj, void *user_data), void *user_data);
extern cl_sampler(CL_API_CALL *CL_PROC_NAME(clCreateSampler))(cl_context context, cl_bool normalized_coords,
                                                              cl_addressing_mode addressing_mode,
                                                              cl_filter_mode filter_mode, cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainSampler))(cl_sampler sampler);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseSampler))(cl_sampler sampler);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetSamplerInfo))(cl_sampler sampler, cl_sampler_info param_name,
                                                           size_t param_value_size, void *param_value,
                                                           size_t *param_value_size_ret);
extern cl_program(CL_API_CALL *CL_PROC_NAME(clCreateProgramWithSource))(cl_context context, cl_uint count,
                                                                        const char **strings, const size_t *lengths,
                                                                        cl_int *errcode_ret);
extern cl_program(CL_API_CALL *CL_PROC_NAME(clCreateProgramWithBinary))(cl_context context, cl_uint num_devices,
                                                                        const cl_device_id *device_list,
                                                                        const size_t *lengths,
                                                                        const unsigned char **binaries,
                                                                        cl_int *binary_status, cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainProgram))(cl_program program);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseProgram))(cl_program program);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clBuildProgram))(
    cl_program program, cl_uint num_devices, const cl_device_id *device_list, const char *options,
    void(CL_CALLBACK *pfn_notify)(cl_program program, void *user_data), void *user_data);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clUnloadCompiler))(void);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetProgramInfo))(cl_program program, cl_program_info param_name,
                                                           size_t param_value_size, void *param_value,
                                                           size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetProgramBuildInfo))(cl_program program, cl_device_id device,
                                                                cl_program_build_info param_name,
                                                                size_t param_value_size, void *param_value,
                                                                size_t *param_value_size_ret);
extern cl_kernel(CL_API_CALL *CL_PROC_NAME(clCreateKernel))(cl_program program, const char *kernel_name,
                                                            cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clCreateKernelsInProgram))(cl_program program, cl_uint num_kernels,
                                                                   cl_kernel *kernels, cl_uint *num_kernels_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainKernel))(cl_kernel kernel);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseKernel))(cl_kernel kernel);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clSetKernelArg))(cl_kernel kernel, cl_uint arg_index, size_t arg_size,
                                                         const void *arg_value);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetKernelInfo))(cl_kernel kernel, cl_kernel_info param_name,
                                                          size_t param_value_size, void *param_value,
                                                          size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetKernelWorkGroupInfo))(cl_kernel kernel, cl_device_id device,
                                                                   cl_kernel_work_group_info param_name,
                                                                   size_t param_value_size, void *param_value,
                                                                   size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clWaitForEvents))(cl_uint num_events, const cl_event *event_list);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetEventInfo))(cl_event event, cl_event_info param_name,
                                                         size_t param_value_size, void *param_value,
                                                         size_t *param_value_size_ret);
extern cl_event(CL_API_CALL *CL_PROC_NAME(clCreateUserEvent))(cl_context context, cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clRetainEvent))(cl_event event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clReleaseEvent))(cl_event event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clSetUserEventStatus))(cl_event event, cl_int execution_status);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clSetEventCallback))(cl_event event, cl_int command_exec_callback_type,
                                                             void(CL_CALLBACK *pfn_notify)(cl_event, cl_int, void *),
                                                             void *user_data);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clGetEventProfilingInfo))(cl_event event, cl_profiling_info param_name,
                                                                  size_t param_value_size, void *param_value,
                                                                  size_t *param_value_size_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clFlush))(cl_command_queue command_queue);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clFinish))(cl_command_queue command_queue);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueReadBuffer))(cl_command_queue command_queue, cl_mem buffer,
                                                              cl_bool blocking_read, size_t offset, size_t cb,
                                                              void *ptr, cl_uint num_events_in_wait_list,
                                                              const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueReadBufferRect))(cl_command_queue command_queue, cl_mem buffer,
                                                                  cl_bool blocking_read, const size_t *buffer_origin,
                                                                  const size_t *host_origin, const size_t *region,
                                                                  size_t buffer_row_pitch, size_t buffer_slice_pitch,
                                                                  size_t host_row_pitch, size_t host_slice_pitch,
                                                                  void *ptr, cl_uint num_events_in_wait_list,
                                                                  const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWriteBuffer))(cl_command_queue command_queue, cl_mem buffer,
                                                               cl_bool blocking_write, size_t offset, size_t cb,
                                                               const void *ptr, cl_uint num_events_in_wait_list,
                                                               const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWriteBufferRect))(cl_command_queue command_queue, cl_mem buffer,
                                                                   cl_bool blocking_write, const size_t *buffer_origin,
                                                                   const size_t *host_origin, const size_t *region,
                                                                   size_t buffer_row_pitch, size_t buffer_slice_pitch,
                                                                   size_t host_row_pitch, size_t host_slice_pitch,
                                                                   const void *ptr, cl_uint num_events_in_wait_list,
                                                                   const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyBuffer))(cl_command_queue command_queue, cl_mem src_buffer,
                                                              cl_mem dst_buffer, size_t src_offset, size_t dst_offset,
                                                              size_t cb, cl_uint num_events_in_wait_list,
                                                              const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueReadImage))(cl_command_queue command_queue, cl_mem image,
                                                             cl_bool blocking_read, const size_t *origin,
                                                             const size_t *region, size_t row_pitch, size_t slice_pitch,
                                                             void *ptr, cl_uint num_events_in_wait_list,
                                                             const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWriteImage))(cl_command_queue command_queue, cl_mem image,
                                                              cl_bool blocking_write, const size_t *origin,
                                                              const size_t *region, size_t input_row_pitch,
                                                              size_t input_slice_pitch, const void *ptr,
                                                              cl_uint num_events_in_wait_list,
                                                              const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyImage))(cl_command_queue command_queue, cl_mem src_image,
                                                             cl_mem dst_image, const size_t *src_origin,
                                                             const size_t *dst_origin, const size_t *region,
                                                             cl_uint num_events_in_wait_list,
                                                             const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyImageToBuffer))(cl_command_queue command_queue, cl_mem src_image,
                                                                     cl_mem dst_buffer, const size_t *src_origin,
                                                                     const size_t *region, size_t dst_offset,
                                                                     cl_uint num_events_in_wait_list,
                                                                     const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueCopyBufferToImage))(cl_command_queue command_queue, cl_mem src_buffer,
                                                                     cl_mem dst_image, size_t src_offset,
                                                                     const size_t *dst_origin, const size_t *region,
                                                                     cl_uint num_events_in_wait_list,
                                                                     const cl_event *event_wait_list, cl_event *event);
extern void *(CL_API_CALL *CL_PROC_NAME(clEnqueueMapBuffer))(cl_command_queue command_queue, cl_mem buffer,
                                                             cl_bool blocking_map, cl_map_flags map_flags,
                                                             size_t offset, size_t cb, cl_uint num_events_in_wait_list,
                                                             const cl_event *event_wait_list, cl_event *event,
                                                             cl_int *errcode_ret);
extern void *(CL_API_CALL *CL_PROC_NAME(clEnqueueMapImage))(
    cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, cl_map_flags map_flags, const size_t *origin,
    const size_t *region, size_t *image_row_pitch, size_t *image_slice_pitch, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event, cl_int *errcode_ret);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueUnmapMemObject))(cl_command_queue command_queue, cl_mem memobj,
                                                                  void *mapped_ptr, cl_uint num_events_in_wait_list,
                                                                  const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueNDRangeKernel))(cl_command_queue command_queue, cl_kernel kernel,
                                                                 cl_uint work_dim, const size_t *global_work_offset,
                                                                 const size_t *global_work_size,
                                                                 const size_t *local_work_size,
                                                                 cl_uint num_events_in_wait_list,
                                                                 const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueTask))(cl_command_queue command_queue, cl_kernel kernel,
                                                        cl_uint num_events_in_wait_list,
                                                        const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueNativeKernel))(cl_command_queue command_queue,
                                                                void (*user_func)(void *), void *args, size_t cb_args,
                                                                cl_uint num_mem_objects, const cl_mem *mem_list,
                                                                const void **args_mem_loc,
                                                                cl_uint num_events_in_wait_list,
                                                                const cl_event *event_wait_list, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueMarker))(cl_command_queue command_queue, cl_event *event);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueWaitForEvents))(cl_command_queue command_queue, cl_uint num_events,
                                                                 const cl_event *event_list);
extern cl_int(CL_API_CALL *CL_PROC_NAME(clEnqueueBarrier))(cl_command_queue command_queue);
extern void *(CL_API_CALL *CL_PROC_NAME(clGetExtensionFunctionAddress))(const char *func_name);

//////////////////////////////////////////////////////////////////////////
// OpenCL wrapper
//////////////////////////////////////////////////////////////////////////

#define clGetPlatformIDs CL_PROC_NAME(clGetPlatformIDs)
#define clGetPlatformInfo CL_PROC_NAME(clGetPlatformInfo)
#define clGetDeviceIDs CL_PROC_NAME(clGetDeviceIDs)
#define clGetDeviceInfo CL_PROC_NAME(clGetDeviceInfo)
#define clCreateContext CL_PROC_NAME(clCreateContext)
#define clCreateContextFromType CL_PROC_NAME(clCreateContextFromType)
#define clRetainContext CL_PROC_NAME(clRetainContext)
#define clReleaseContext CL_PROC_NAME(clReleaseContext)
#define clGetContextInfo CL_PROC_NAME(clGetContextInfo)
#define clCreateCommandQueue CL_PROC_NAME(clCreateCommandQueue)
#define clRetainCommandQueue CL_PROC_NAME(clRetainCommandQueue)
#define clReleaseCommandQueue CL_PROC_NAME(clReleaseCommandQueue)
#define clGetCommandQueueInfo CL_PROC_NAME(clGetCommandQueueInfo)
#define clCreateBuffer CL_PROC_NAME(clCreateBuffer)
#define clCreateSubBuffer CL_PROC_NAME(clCreateSubBuffer)
#define clCreateImage2D CL_PROC_NAME(clCreateImage2D)
#define clCreateImage3D CL_PROC_NAME(clCreateImage3D)
#define clRetainMemObject CL_PROC_NAME(clRetainMemObject)
#define clReleaseMemObject CL_PROC_NAME(clReleaseMemObject)
#define clGetSupportedImageFormats CL_PROC_NAME(clGetSupportedImageFormats)
#define clGetMemObjectInfo CL_PROC_NAME(clGetMemObjectInfo)
#define clGetImageInfo CL_PROC_NAME(clGetImageInfo)
#define clSetMemObjectDestructorCallback CL_PROC_NAME(clSetMemObjectDestructorCallback)
#define clCreateSampler CL_PROC_NAME(clCreateSampler)
#define clRetainSampler CL_PROC_NAME(clRetainSampler)
#define clReleaseSampler CL_PROC_NAME(clReleaseSampler)
#define clGetSamplerInfo CL_PROC_NAME(clGetSamplerInfo)
#define clCreateProgramWithSource CL_PROC_NAME(clCreateProgramWithSource)
#define clCreateProgramWithBinary CL_PROC_NAME(clCreateProgramWithBinary)
#define clRetainProgram CL_PROC_NAME(clRetainProgram)
#define clReleaseProgram CL_PROC_NAME(clReleaseProgram)
#define clBuildProgram CL_PROC_NAME(clBuildProgram)
#define clUnloadCompiler CL_PROC_NAME(clUnloadCompiler)
#define clGetProgramInfo CL_PROC_NAME(clGetProgramInfo)
#define clGetProgramBuildInfo CL_PROC_NAME(clGetProgramBuildInfo)
#define clCreateKernel CL_PROC_NAME(clCreateKernel)
#define clCreateKernelsInProgram CL_PROC_NAME(clCreateKernelsInProgram)
#define clRetainKernel CL_PROC_NAME(clRetainKernel)
#define clReleaseKernel CL_PROC_NAME(clReleaseKernel)
#define clSetKernelArg CL_PROC_NAME(clSetKernelArg)
#define clGetKernelInfo CL_PROC_NAME(clGetKernelInfo)
#define clGetKernelWorkGroupInfo CL_PROC_NAME(clGetKernelWorkGroupInfo)
#define clWaitForEvents CL_PROC_NAME(clWaitForEvents)
#define clGetEventInfo CL_PROC_NAME(clGetEventInfo)
#define clCreateUserEvent CL_PROC_NAME(clCreateUserEvent)
#define clRetainEvent CL_PROC_NAME(clRetainEvent)
#define clReleaseEvent CL_PROC_NAME(clReleaseEvent)
#define clSetUserEventStatus CL_PROC_NAME(clSetUserEventStatus)
#define clSetEventCallback CL_PROC_NAME(clSetEventCallback)
#define clGetEventProfilingInfo CL_PROC_NAME(clGetEventProfilingInfo)
#define clFlush CL_PROC_NAME(clFlush)
#define clFinish CL_PROC_NAME(clFinish)
#define clEnqueueReadBuffer CL_PROC_NAME(clEnqueueReadBuffer)
#define clEnqueueReadBufferRect CL_PROC_NAME(clEnqueueReadBufferRect)
#define clEnqueueWriteBuffer CL_PROC_NAME(clEnqueueWriteBuffer)
#define clEnqueueWriteBufferRect CL_PROC_NAME(clEnqueueWriteBufferRect)
#define clEnqueueCopyBuffer CL_PROC_NAME(clEnqueueCopyBuffer)
#define clEnqueueReadImage CL_PROC_NAME(clEnqueueReadImage)
#define clEnqueueWriteImage CL_PROC_NAME(clEnqueueWriteImage)
#define clEnqueueCopyImage CL_PROC_NAME(clEnqueueCopyImage)
#define clEnqueueCopyImageToBuffer CL_PROC_NAME(clEnqueueCopyImageToBuffer)
#define clEnqueueCopyBufferToImage CL_PROC_NAME(clEnqueueCopyBufferToImage)
#define clEnqueueMapBuffer CL_PROC_NAME(clEnqueueMapBuffer)
#define clEnqueueMapImage CL_PROC_NAME(clEnqueueMapImage)
#define clEnqueueUnmapMemObject CL_PROC_NAME(clEnqueueUnmapMemObject)
#define clEnqueueNDRangeKernel CL_PROC_NAME(clEnqueueNDRangeKernel)
#define clEnqueueTask CL_PROC_NAME(clEnqueueTask)
#define clEnqueueNativeKernel CL_PROC_NAME(clEnqueueNativeKernel)
#define clEnqueueMarker CL_PROC_NAME(clEnqueueMarker)
#define clEnqueueWaitForEvents CL_PROC_NAME(clEnqueueWaitForEvents)
#define clEnqueueBarrier CL_PROC_NAME(clEnqueueBarrier)
#define clGetExtensionFunctionAddress CL_PROC_NAME(clGetExtensionFunctionAddress)
