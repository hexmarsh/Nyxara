#include <iostream>
#include <cstdlib>
#include "nyxara/nyxara.h"

void *operator new(size_t size)
{
  std::cout << "Allocating " << size << " bytes.\n";
  return malloc(size);
}

int main()
{
  NYX_SET_LOG_LEVEL(Platform, nyxara::logging::Verbosity::Trace);
  NYX_LOG_ENABLE_CALL_DEPTH();

  nyxara::platform::WindowCreateInfo info{};
  info.FullScreen = false;

  nyxara::platform::Window* window = nyxara::platform::Window::Create(info);

  while (!window->ShouldClose())
  {
	  window->PollEvents();
	  window->SwapBuffers();
  }

  delete window;
}
