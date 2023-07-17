#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *array, size_t size);
void copy_array(int *array, int start, int end, int *tmp);
void swap_array(int *array, size_t left, size_t right);
void print_array(const int *array, size_t size);

#endif
