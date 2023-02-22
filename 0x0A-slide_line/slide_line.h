#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
void swap(int *line, int source, int dest);
int add(int *line, int src, int dest, size_t size, int findNext);
int find_number(int idx, int size, int *line);
int *reverse(int *line, int size);

#endif /*SLIDE_LINE_H*/
