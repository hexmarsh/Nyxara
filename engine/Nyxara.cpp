#include "nyxara/logging/logger.h"

NYX_DEFINE_LOG_CATEGORY(renderer);

int main() {
	nyxara::logging::logger::init();
	NYX_SET_LOG_LEVEL(renderer, nyxara::logging::verbosity::error);

	NYX_LOG_ERROR(renderer, "This will show up.");
	NYX_LOG_INFO(renderer, "This will not show up.");
	return 0;
}
