#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array in ascending order
 * using the counting sort algorithm
 * @array: the array to sort
 * @size: array size
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
    size_t i, max = 0;
    int *count, *answer;

    if (size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (max < (size_t)array[i])
            max = array[i];
    }

    count = (int *)malloc(sizeof(int) * (max + 1));
    if (!count)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;
    
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    print_array(count, max + 1);

    answer = (int *)malloc(sizeof(int) * size);
    if (!answer) {
        free(count);
        return;
    }
    for (i = size; i > 0; i--)
        answer[--count[array[i - 1]]] = array[i - 1];
    for (i = 0; i < size; i++)
        array[i] = answer[i];
    free(count);
    free(answer);
}
