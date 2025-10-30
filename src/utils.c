#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

/**
 * @brief Allocates memory safely.
 *
 * Wraps malloc() and exits the program if allocation fails, such as when size is 0.
 *
 * @param size Number of bytes to allocate. Must be a valid positive integer.
 * @return Pointer to allocated memory.
 */
void* safe_malloc(size_t size) {
	void* ptr = malloc(size);
	if (ptr != NULL) {
		return ptr;
	} else {
		fprintf(stderr, "safe_malloc: failed to allocate %zu bytes\n", size);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Reallocates memory safely.
 *
 * Wraps realloc() and exits the program if reallocation fails, such as when size is 0.
 *
 * @param ptr Pointer to memory that needs to be reallocated.
 * @param size Number of bytes to allocate. Must be a valid positive integer.
 */
void* safe_realloc(void* ptr, size_t size) {
	void* ptr2 = realloc(ptr, size);
	if (ptr2 != NULL) {
		return ptr2;
	} else {
		fprintf(stderr, "safe_realloc: failed to reallocate %zu bytes\n", size);
		exit(EXIT_FAILURE);
	}
}
