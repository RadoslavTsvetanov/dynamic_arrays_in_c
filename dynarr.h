#ifndef DYNARR_H
#define DYNARR_H

typedef struct
{
    int *buffer;
    unsigned int capacity;
    unsigned int size;
} DynamicArray;

DynamicArray init(unsigned int capacity);

double getel(DynamicArray *arr, int index);

void setel(DynamicArray *arr, int index, double value);

void pushback(DynamicArray *arr, double value);

int popback(DynamicArray *arr);

void push(DynamicArray *arr, int index, double value);

void pushfront(DynamicArray *arr, double value);

// For homework
void pop(DynamicArray *arr, int index);

// For homework
void popfront(DynamicArray *arr);

void releasedynarr(DynamicArray *arr);

int find_index_of_element(DynamicArray *arr, double value);

#endif