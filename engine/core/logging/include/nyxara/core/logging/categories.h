#pragma once

#include "nyxara/core/logging/macros.h"

/**
 * @file categories.h
 * @brief Defines global logging categories for use throughout the Nyxara engine.
 *
 * Logging categories group related log messages and allow independent verbosity control.
 * Each category defined here can be used in any part of the engine via NYX_LOG macros.
 *
 * Categories declared here are intended to be used globally.
 *
 * @note If you want to access these categories in other translation units,
 *       use @ref NYX_DECLARE_LOG_CATEGORY instead of redefining them.
 */

 /**
  * @brief Core systems logging category.
  * Used for logs related to engine internals, startup, shutdown, and other central systems.
  */
NYX_DEFINE_LOG_CATEGORY(Core);

/**
 * @brief Renderer subsystem logging category.
 * Used for logs from graphics, shaders, and rendering-related code.
 */
NYX_DEFINE_LOG_CATEGORY(Renderer);

