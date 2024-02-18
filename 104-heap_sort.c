#include "sort.h"

/**
 * heapify - ....
 * @array: ....
 * @size: ....
 * @i: ....
 *
 * Return: void
 */
void heapify(int *array, size_t size, size_t i) {
    size_t largest = i, l = 2 * i + 1, r = 2 * i + 2;

    if (l < size && array[l] > array[largest])
        largest = l;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        int_swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: ....
 * @size: .....
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    for (i = size / 2; i > 0; i--)
    {
        heapify(array, size, i - 1);
        print_array(array, size);

    }

    for (i = size - 1; i > 0; i--)
    {
        int_swap(&array[0], &array[i]);
        heapify(array, i, 0);
        print_array(array, size);
    }
}

/**
 * int_swap - swaps between two variables
 * @a: first var
 * @b: second var
 *
 * Return: void
 */
void int_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
