#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

// Memory allocation wrapper
void* safe_malloc(size_t size) {
	void* ptr = malloc(size);
	if (ptr != NULL) {
		return ptr;
	} else {
		fprintf(stderr, "safe_malloc: failed to allocate %zu bytes\n", size);
		exit(EXIT_FAILURE);
	}
}

// Memory reallocation wrapper
void* safe_realloc(void* ptr, size_t size) {
	void* ptr2 = realloc(ptr, size);
	if (ptr2 != NULL) {
		return ptr2;
	} else {
		fprintf(stderr, "safe_realloc: failed to reallocate %zu bytes\n", size);
		exit(EXIT_FAILURE);
	}
}
