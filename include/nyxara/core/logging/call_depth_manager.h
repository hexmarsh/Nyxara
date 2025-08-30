#pragma once

/**
 * @file call_depth_manager.h
 * @brief Per-thread call depth tracking for structured logging in Nyxara.
 *
 * This file defines the ::nyxara::logging::CallDepthManager class, which manages
 * per-thread call depth tracking to enhance log output with indentation or
 * hierarchy information. This is particularly useful for tracing nested function
 * calls or recursive logic within complex systems.
 *
 * @details
 * Call depth tracking is integrated with the logging system and is automatically
 * used by ::nyxara::logging::FunctionTracer. It can also be manually enabled or
 * disabled via ::nyxara::logging::CallDepthManager::SetEnabled().
 *
 * When enabled, the current call depth is prepended to log messages (usually at
 * Verbosity::Trace level) to reflect the structure of the call stack, aiding in
 * debugging and performance tracing.
 *
 * @note All call depth state is maintained per-thread using `thread_local` variables.
 *
 * @see nyxara::logging::FunctionTracer
 */

namespace nyxara::logging
{
	/**
	 * @brief Manages logging depth based on call depth (per thread).
	 * 
	 * Used internally by the logging system to add call depth information to logs for nested function calls.
	 * This helps track call hierarchy in complex systems. Call depth is tracked per-thread.
	 * 
	 * CallDepthManager is used automatically by the FunctionTracer class, but can also be manually
	 * enabled or disabled via SetEnabled().
	 */
	class CallDepthManager
	{
	public:
		/**
		 * @brief Gets the current call depth.
		 * 
		 * @return The number of nested scopes currently being traced.
		 */
		static int GetDepth() noexcept { return CallDepth; }

		/**
		 * @brief Increments the current call depth (e.g., on function entry).
		 */
		static void Increment() noexcept { ++CallDepth; }

		/**
		 * @brief Decrements the current call depth (e.g., on function exit).
		 */
		static void Decrement() noexcept { --CallDepth; }

		/**
		 * @brief Enables or disables call depth information tracking.
		 * 
		 * When disabled, logs will be emitted without call depth information, regardless of depth.
		 * 
		 * @param isEnabled True to enable, false to disable.
		 */
		static void SetEnabled(bool isEnabled) noexcept { bIsEnabled = isEnabled; }

		/**
		 * @brief Checks whether the call depth information is enabled.
		 * 
		 * @return True if enabled, false otherwise.
		 */
		static bool IsEnabled() noexcept { return bIsEnabled; }

	private:
		static thread_local int CallDepth;		///< Per-thread call depth counter.
		static thread_local bool bIsEnabled;	///< Whether the call depth tracking is enabled.
	};

	inline thread_local int CallDepthManager::CallDepth = 0;
	inline thread_local bool CallDepthManager::bIsEnabled = false;
} // namespace nyxara::logging