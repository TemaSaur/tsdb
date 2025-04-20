#pragma once

/**
 * @brief File page size
 */
#define PAGE_SIZE 128 // for testing

/**
 * @brief Path storing the database files
 */
#define BASE_DIR "data"

/**
 * @brief Path separator depending on the OS
 */
#if defined(_WIN32) || defined(_WIN64)
	#define SEP '\\'
#else
	#define SEP '/'
#endif
