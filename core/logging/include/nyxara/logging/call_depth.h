#pragma once

namespace nyxara::logging 
{
    class call_depth_manager
    {
    public:
        static int get_depth() noexcept { return _call_depth; }
        static void increment() noexcept { ++_call_depth; }
        static void decrement() noexcept { --_call_depth; }
        
        static int get_indentation_count() noexcept { return _call_depth * 2; }
        
        static void set_enabled(bool enabled) noexcept { _enabled = enabled; }
        static bool is_enabled() noexcept { return _enabled; }

    private:
        static thread_local int _call_depth;
        static thread_local bool _enabled;
    };

    inline thread_local int call_depth_manager::_call_depth = 0;
    inline thread_local bool call_depth_manager::_enabled = false;
} // namespace nyxara::logging