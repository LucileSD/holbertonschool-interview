#ifndef _SEARCH_ALGOS_H
#define _SEARCH_ALGOS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int advanced_binary(int *array, size_t size, int value);
int advanced_binary_recurse(int *array, size_t low, size_t high, int value);

#endif /*_SEARCH_ALGOS_H*/
