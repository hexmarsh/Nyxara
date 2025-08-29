#include <GLFW/glfw3.h>
#include <stdexcept>
#include "window_impl.h"
#include "nyxara/core/logging/categories.h"

namespace nyxara::platform
{
	class GLFWWindow : public Window
	{
	public:
		explicit GLFWWindow(const WindowCreateInfo& info)
		{
			NYX_TRACE_FUNCTION(Platform);
			NYX_LOG_INFO(Platform, "Initializing GLFW window: {}x{}, title: '{}', fullscreen: {}, resizable: {}", 
				info.Width, info.Height, info.Title, info.FullScreen, info.Resizable);

			if (!glfwInit())
			{
				NYX_LOG_CRITICAL(Platform, "Failed to initialize GLFW");
				throw std::runtime_error("Failed to initialize GLFW");
			}

			NYX_LOG_DEBUG(Platform, "GLFW initialized successfully");

			glfwWindowHint(GLFW_RESIZABLE, info.Resizable ? GLFW_TRUE : GLFW_FALSE);

			GLFWmonitor* monitor = nullptr;
			int width = static_cast<int>(info.Width);
			int height = static_cast<int>(info.Height);

			if (info.FullScreen)
			{
				monitor = glfwGetPrimaryMonitor();
				const GLFWvidmode* mode = glfwGetVideoMode(monitor);
				width = mode->width;
				height = mode->height;
				NYX_LOG_DEBUG(Platform, "Using fullscreen mode: {}x{}", width, height);
			}

			Window = glfwCreateWindow(width, height, info.Title, monitor, nullptr);

			if (!Window)
			{
				NYX_LOG_CRITICAL(Platform, "Failed to create GLFW window");
				glfwTerminate();
				throw std::runtime_error("Failed to create GLFW window");
			}

			NYX_LOG_INFO(Platform, "GLFW window created successfully");
			glfwMakeContextCurrent(Window);
			NYX_LOG_DEBUG(Platform, "GLFW window context made current");
		}

		~GLFWWindow() override
		{
			NYX_TRACE_FUNCTION(Platform);
			NYX_LOG_INFO(Platform, "Destroying GLFW window");
			
			glfwDestroyWindow(Window);
			NYX_LOG_DEBUG(Platform, "GLFW window destroyed");
			
			glfwTerminate();
			NYX_LOG_DEBUG(Platform, "GLFW terminated");
		}

		void PollEvents() override
		{
			NYX_LOG_TRACE(Platform, "Polling GLFW events");
			glfwPollEvents();
		}

		void SwapBuffers() override
		{
			NYX_LOG_TRACE(Platform, "Swapping GLFW buffers");
			glfwSwapBuffers(Window);
		}

		bool ShouldClose() const override
		{
			bool shouldClose = glfwWindowShouldClose(Window);
			if (shouldClose)
			{
				NYX_LOG_INFO(Platform, "Window close requested");
			}
			return shouldClose;
		}

	private:
		GLFWwindow* Window;
	};

	Window* CreateGLFWWindow(const WindowCreateInfo& info)
	{
		NYX_TRACE_FUNCTION(Platform);
		NYX_LOG_DEBUG(Platform, "Creating GLFW window instance");
		return new GLFWWindow(info);
	}
}