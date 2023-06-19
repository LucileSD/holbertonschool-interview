#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursion(int *array, int *arr_tmp, size_t left, size_t right);
void merge_sorted_arrays(int *array, int *arr_tmp, size_t left,
size_t middle, size_t right);

#endif /*SORT_H*/
