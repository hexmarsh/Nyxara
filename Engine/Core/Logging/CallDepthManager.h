#pragma once

namespace Nyxara::Logging
{
	class CallDepthManager
	{
	public:
		static int GetDepth() noexcept { return CallDepth; }
		static void Increment() noexcept { ++CallDepth; }
		static void Decrement() noexcept { --CallDepth; }

		static int GetIndentationCount() noexcept { return CallDepth * 2; }

		static void SetEnabled(bool isEnabled) noexcept { bIsEnabled = isEnabled; }
		static bool IsEnabled() noexcept { return bIsEnabled; }

	private:
		static thread_local int CallDepth;
		static thread_local bool bIsEnabled;
	};

	inline thread_local int CallDepthManager::CallDepth = 0;
	inline thread_local bool CallDepthManager::bIsEnabled = false;
} // namespace nyx::logging