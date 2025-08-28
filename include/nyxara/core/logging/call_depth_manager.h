#pragma once

namespace Nyxara::Logging
{
	/**
	 * @brief Manages logging indentation based on call depth (per thread).
	 * 
	 * Used internally by the logging system to visually indent logs for nested function calls.
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
		 * @brief Returns the indentation width in spaces, based on current depth.
		 * 
		 * Each level adds 2 spaces.
		 * 
		 * @return Number of spaces to indent.
		 */
		static int GetIndentationCount() noexcept { return CallDepth * 2; }

		/**
		 * @brief Enables or disables call depth indentation tracking.
		 * 
		 * When disabled, logs will be emitted without indentation, regardless of depth.
		 * 
		 * @param isEnabled True to enable, false to disable.
		 */
		static void SetEnabled(bool isEnabled) noexcept { bIsEnabled = isEnabled; }

		/**
		 * @brief Checks whether the call depth indentation is enabled.
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
} // namespace nyx::logging