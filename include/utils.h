// Include Guard, prevents compilation errors
#ifndef UTILS_H
#define UTILS_H

// Standard Library
#include <stddef.h>

/**
 * @brief Allocates memory safely.
 *
 * Wraps malloc() and exits the program if allocation fails, such as when size is 0.
 *
 * @param size Number of bytes to allocate. Must be a valid positive integer.
 * @return Pointer to allocated memory.
 */
void* safe_malloc(size_t size);

/**
 * @brief Reallocates memory safely.
 *
 * Wraps realloc() and exits the program if reallocation fails, such as when size is 0.
 *
 * @param ptr Pointer to memory that needs to be reallocated.
 * @param size Number of bytes to allocate. Must be a valid positive integer.
 */
void* safe_realloc(void* ptr, size_t size);

// TODO: Math utilities


// TODO: Logging/debugging


// TODO: Byte manipulation


#endif // Closes UTILS_H include guard
