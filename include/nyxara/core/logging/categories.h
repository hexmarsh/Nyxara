#pragma once

#include "nyxara/core/logging/macros.h"

/**
 * @file categories.h
 * @brief Defines global logging categories used throughout the Nyxara engine.
 *
 * Logging categories group related log messages and allow independent verbosity control.
 * Each category declared here can be used anywhere in the engine via NYX_LOG macros.
 *
 * Categories declared here are intended for global/shared use across subsystems.
 */

 /**
 * @brief Core systems logging category.
 *
 * Used for logs related to engine internals, startup, shutdown, configuration,
 * and other central/core systems.
 */
NYX_DECLARE_LOG_CATEGORY(Core);

/**
* @brief Platform abstraction logging category.
*
* Covers platform-specific functionality such as window management,
* input handling, and OS integration.
*/
NYX_DECLARE_LOG_CATEGORY(Platform);
