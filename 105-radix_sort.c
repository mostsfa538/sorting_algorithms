#include "sort.h"
#include <stdlib.h>



/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: the array
 * @size: the size of the array
 *
 * Rrturn: void
 */
void radix_sort(int *array, size_t size) {
    int max = find_max(array, size), exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(array, size, exp);
        print_array(array, size);
    }
}

/**
* find_max - get the max element in the array
* @array: the array
* @size: the size of the array
*
* Return: the max element
*/
int find_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;
    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];

    return (max);
}

void count_sort(int *array, size_t size, int exp)
{
    size_t i;
    int *output, *count;

    output = (int *)malloc(size * sizeof(int));
    if (!output)
    {
        exit(EXIT_FAILURE);
    }

    count = (int *)malloc(sizeof(int) * 10);

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size; i > 0; i--) {
        output[--count[(array[i - 1] / exp) % 10]] = array[i - 1];
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];
}
