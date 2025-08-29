#pragma once

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