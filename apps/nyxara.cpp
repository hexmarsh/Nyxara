#include <iostream>
#include <cstdlib>
#include "nyxara/nyxara.h"
#include "vulkan/vulkan_raii.hpp"

class VulkanApplication
{
public:
	void run()
	{
		InitWindow();
		InitVulkan();
		MainLoop();
		CleanUp();
	}

private:
	nyxara::platform::Window* Window;

	void InitWindow()
	{
		nyxara::platform::WindowCreateInfo info{};
		info.Title = "Vulkan";

		Window = nyxara::platform::Window::Create(info);
	}

	void InitVulkan()
	{

	}

	void MainLoop()
	{
		while (!Window->ShouldClose())
		{
			Window->PollEvents();
		}
	}

	void CleanUp()
	{
		delete Window;
	}
};

void *operator new(size_t size)
{
  std::cout << "Allocating " << size << " bytes.\n";
  return malloc(size);
}

int main()
{
  NYX_SET_LOG_LEVEL(Platform, nyxara::logging::Verbosity::Trace);
  NYX_SET_LOG_LEVEL(Core, nyxara::logging::Verbosity::Trace);
  NYX_LOG_ENABLE_CALL_DEPTH();

  try
  {
	  VulkanApplication app{};
	  app.run();
  }
  catch (const std::exception& e)
  {
	  NYX_LOG_CRITICAL(Core, "{}", e.what());
	  return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
