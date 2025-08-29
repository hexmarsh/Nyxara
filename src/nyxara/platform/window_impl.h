#pragma once

#include "nyxara/platform/window.h"

namespace nyxara::platform
{
	Window* CreateGLFWWindow(const WindowCreateInfo& info);
}