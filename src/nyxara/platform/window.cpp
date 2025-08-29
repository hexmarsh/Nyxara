#include "window_impl.h"
#include "nyxara/core/logging/categories.h"
#include <stdexcept>

namespace nyxara::platform
{
	Window* Window::Create(const WindowCreateInfo& info)
	{
		NYX_TRACE_FUNCTION(Platform);

		switch (info.Backend)
		{
		case WindowBackend::GLFW:
			NYX_LOG_INFO(Platform, "Creating window with GLFW backend");
			return CreateGLFWWindow(info);
		default:
			NYX_LOG_CRITICAL(Platform, "Unsupported window backend: {}", static_cast<int>(info.Backend));
			throw std::runtime_error("Unsupported window backend");
		}
	}
}