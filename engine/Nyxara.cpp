#include "nyxara/logging/categories.h"
#include "nyxara/logging/logger.h"
#include "nyxara/logging/macros.h"
#include "nyxara/math/vec3.h"
#include <iostream>

void *operator new(size_t size)
{
  std::cout << "Allocating " << size << " bytes.\n";
  return malloc(size);
}

void nested_log_test()
{
  NYX_TRACE_FUNCTION(renderer);
  NYX_LOG_CRITICAL(renderer, "This is critical");
  NYX_LOG_ERROR(renderer, "This is an error");
}

void log_test()
{
  NYX_TRACE_FUNCTION(renderer);
  NYX_LOG_WARN(renderer, "This is a warning");
  nested_log_test();
}

int main()
{
  nyxara::logging::logger::init();

  NYX_SET_LOG_LEVEL(renderer, nyxara::logging::verbosity::trace);
  NYX_LOG_ENABLE_CALL_DEPTH();

  using vec3 = nyxara::math::vec3<glm::vec3>;

  vec3 myvec1(1.0f, 1.0f, 1.0f);
  vec3 myvec2(1.0f, 1.0f, 1.0f);
  vec3 summed = myvec1 + myvec2;

  log_test();
}
