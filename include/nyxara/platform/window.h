#pragma once

#include <cstdint>

/**
 * @file window.h
 * @brief Declares platform-agnostic window interface for Nyxara.
 */

namespace nyxara::platform
{
    /**
     * @enum WindowBackend
     * @brief Specifies the underlying windowing system backend.
     */
    enum class WindowBackend
    {
        /**
         * @brief Use the GLFW library as the backend.
         */
        GLFW
    };

    /**
     * @struct WindowCreateInfo
     * @brief Describes parameters for creating a window.
     *
     * This structure holds configuration options passed to the Window::Create function.
     */
    struct WindowCreateInfo
    {
        /**
         * @brief Initial width of the window in pixels.
         */
        uint32_t Width = 800;

        /**
         * @brief Initial height of the window in pixels.
         */
        uint32_t Height = 600;

        /**
         * @brief Title text shown in the window's title bar.
         */
        const char* Title = "Nyxara Window";

        /**
         * @brief Backend to use for window creation.
         */
        WindowBackend Backend = WindowBackend::GLFW;

        /**
         * @brief If true, the window can be resized by the user.
         */
        bool Resizable = true;

        /**
         * @brief If true, the window will be created in full-screen mode.
         */
        bool FullScreen = false;
    };

    /**
     * @class Window
     * @brief Abstract base class for platform windows.
     *
     * Provides an interface for window operations like event polling and buffer swapping.
     * Implementations will vary depending on the underlying platform/backend.
     */
    class Window
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Window() = default;

        /**
         * @brief Polls and processes window events (e.g., input, resize).
         */
        virtual void PollEvents() = 0;

        /**
         * @brief Swaps the front and back buffers, displaying the rendered frame.
         */
        virtual void SwapBuffers() = 0;

        /**
         * @brief Checks whether the window should close (e.g., user clicked "X").
         * @return True if the window should close, false otherwise.
         */
        virtual bool ShouldClose() const = 0;

        /**
         * @brief Creates a platform-specific window instance.
         *
         * This static function chooses the appropriate implementation based on the
         * backend specified in the WindowCreateInfo.
         *
         * @param info Configuration used to create the window.
         * @return Pointer to a newly created Window instance. Ownership must be managed by the caller.
         */
        static Window* Create(const WindowCreateInfo& info);
    };

} // namespace nyxara::platform
