#pragma once

#include <CL/cl.h>

class CLExt
{
  public:
    static int init();
    static int shutdown();
    static int isInitialized();
    static cl_platform_id getPlatform();
    static cl_device_id getDevice();
    static cl_context getContext();
    static cl_command_queue getQueue();
    static const char *getName();
    static const char *getVendor();
    static const char *getVersion();
    static const char *getExtensions();
    static int error(cl_int result);

  private:
    CLExt();
};
