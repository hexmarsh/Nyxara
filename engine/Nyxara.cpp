#include "nyxara/logging/logger.h"
#include "nyxara/logging/macros.h"

NYX_DEFINE_LOG_CATEGORY(renderer);

int main() {
	NYX_SET_LOG_LEVEL(renderer, nyxara::logging::verbosity::trace);

	NYX_TRACE_FUNCTION(renderer);

	nyxara::logging::logger::init();

	return 0;
}
