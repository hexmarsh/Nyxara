#include "Engine/Core/Logging/Logger.h"
#include "Engine/Core/Logging/Macros.h"
#include "Engine/Core/Logging/Categories.h"
#include <iostream>
#include <cstdlib>

void *operator new(size_t size)
{
  std::cout << "Allocating " << size << " bytes.\n";
  return malloc(size);
}

void nested_log_test()
{
  NYX_TRACE_FUNCTION(Renderer);
  NYX_LOG_CRITICAL(Renderer, "This is critical");
  NYX_LOG_ERROR(Renderer, "This is an error");
}

void log_test()
{
  NYX_TRACE_FUNCTION(Renderer);
  NYX_LOG_WARN(Renderer, "This is a warning");
  nested_log_test();
}

int main()
{
  NYX_SET_LOG_LEVEL(Renderer, Nyxara::Logging::Verbosity::Trace);
  NYX_LOG_ENABLE_CALL_DEPTH();

  log_test();
}
