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
			NYX_LOG_INFO(Platform, "Creating GLFW window: {}x{}, title: '{}', fullscreen: {}, resizable: {}",
				info.Width, info.Height, info.Title, info.FullScreen, info.Resizable);

			if (!glfwInit())
			{
				NYX_LOG_CRITICAL(Platform, "Failed to initialize GLFW");
				throw std::runtime_error("Failed to initialize GLFW");
			}

			glfwWindowHint(GLFW_RESIZABLE, info.Resizable ? GLFW_TRUE : GLFW_FALSE);
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

			GLFWmonitor* monitor = nullptr;
			int width = static_cast<int>(info.Width);
			int height = static_cast<int>(info.Height);

			if (info.FullScreen)
			{
				monitor = glfwGetPrimaryMonitor();
				const GLFWvidmode* mode = glfwGetVideoMode(monitor);
				width = mode->width;
				height = mode->height;
				NYX_LOG_DEBUG(Platform, "Fullscreen mode: {}x{}", width, height);
			}

			Window = glfwCreateWindow(width, height, info.Title, monitor, nullptr);

			if (!Window)
			{
				NYX_LOG_CRITICAL(Platform, "Failed to create GLFW window");
				glfwTerminate();
				throw std::runtime_error("Failed to create GLFW window");
			}

			glfwMakeContextCurrent(Window);
			NYX_LOG_INFO(Platform, "GLFW window created and context initialized");
		}

		~GLFWWindow() override
		{
			NYX_TRACE_FUNCTION(Platform);
			NYX_LOG_INFO(Platform, "Destroying GLFW window");

			glfwDestroyWindow(Window);
			glfwTerminate();
		}

		void PollEvents() override
		{
			glfwPollEvents();
		}

		void SwapBuffers() override
		{
			glfwSwapBuffers(Window);
		}

		bool ShouldClose() const override
		{
			return glfwWindowShouldClose(Window);
		}

	private:
		GLFWwindow* Window;
	};

	Window* CreateGLFWWindow(const WindowCreateInfo& info)
	{
		NYX_TRACE_FUNCTION(Platform);
		return new GLFWWindow(info);
	}
}
