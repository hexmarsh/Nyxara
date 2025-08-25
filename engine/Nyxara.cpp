#include "nyxara/logging/logger.h"
#include "nyxara/logging/macros.h"
#include <iostream>

NYX_DEFINE_LOG_CATEGORY(renderer);

void* operator new(size_t size)
{
	std::cout << "Allocating " << size << " bytes.\n";
	return malloc(size);
}

void nested_log_test()
{
	NYX_TRACE_FUNCTION(renderer);
	NYX_LOG_CRITICAL(renderer, "This is critical");
	NYX_LOG_ERROR(renderer, "This is an error");
}

void log_test()
{
	NYX_TRACE_FUNCTION(renderer);
	NYX_LOG_WARN(renderer, "This is a warning");
	nested_log_test();
}

int main() {
	NYX_SET_LOG_LEVEL(renderer, nyxara::logging::verbosity::trace);
	NYX_ENABLE_CALL_DEPTH();

	log_test();

	nyxara::logging::logger::init();

	//return 0;
}
