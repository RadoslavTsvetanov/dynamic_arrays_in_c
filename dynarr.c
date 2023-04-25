#include "dynarr.h"
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_MEMORY_ALLOC(PTR)              \
    if ((PTR) == NULL)                        \
    {                                         \
        printf("Error allocating memory \n"); \
        exit(1);                              \
    }

static void resize(DynamicArray *arr, int newsize)
{
    if (newsize > arr->capacity)
    {
        arr->capacity *= 2;
        arr->buffer = (int *)realloc(arr->buffer, sizeof(int) * arr->capacity);
        ASSERT_MEMORY_ALLOC(arr->buffer);
    }
    else if (newsize <= arr->capacity / 2)
    {
        arr->capacity /= 2;
        arr->buffer = (int *)realloc(arr->buffer, sizeof(int) * arr->capacity);
        ASSERT_MEMORY_ALLOC(arr->buffer);
    }
    arr->size = newsize;
}

DynamicArray init(unsigned int capacity)
{
    DynamicArray arr = {
        capacity : capacity,
        size : 0,
        buffer : NULL
    };

    arr.buffer = (int *)calloc(arr.capacity, sizeof(int));
    ASSERT_MEMORY_ALLOC(arr.buffer);

    return arr;
}

double getel(DynamicArray *arr, int index)
{
    return arr->buffer[index];
}

void setel(DynamicArray *arr, int index, double value)
{
    int newsize = arr->size;
    if (index > newsize - 1)
    {
        newsize = index + 1;
    }
    resize(arr, newsize);

    arr->buffer[index] = value;
}

void pushback(DynamicArray *arr, double value)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    arr->buffer[arr->size - 1] = value;
}

int popback(DynamicArray *arr)
{
    int newsize = arr->size - 1;
    int result = arr->buffer[newsize];

    resize(arr, newsize);
    arr->buffer[arr->size - 1] = 0; // da pitam dali moeto e pravilno
    return result;
}

void push(DynamicArray *arr, int index, double value)
{
    int newsize = arr->size + 1;
    resize(arr, newsize);
    for (int i = arr->size - 1; i > index; i--)
    {
        arr->buffer[i] = arr->buffer[i - 1];
    }
    arr->buffer[index] = value;
}

void pushfront(DynamicArray *arr, double value)
{
    push(arr, 0, value);
}

void pop(DynamicArray *arr, int index)
{
    int newsize = arr->size - 1;
    // index - 6
    for (int i = index; i < arr->size - 1; i++)
    {
        arr->buffer[i] = arr->buffer[i + 1];
    }
    resize(arr, newsize);
}

void popfront(DynamicArray *arr)
{
    pop(arr, 0);
};

void releasedynarr(DynamicArray *arr)
{
    if (arr->buffer != NULL)
    {
        free(arr->buffer);
        arr->buffer = NULL;
    }
    arr->capacity = 0;
    arr->size = 0;
}

int find_index_of_element(DynamicArray *arr, double value)
{
    for (int i = 0; i < arr->size; i++)
    {
        if (arr->buffer[i] == value)
        {
            return i;
        }
    }
    return -1;
}