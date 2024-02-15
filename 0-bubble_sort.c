#include "sort.h"

/**
* bubble_sort - sorts an array of integers using Bubble sort algorithm
* @array: the array
* @size: the size of the array
*
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
    size_t i;
    size_t n = 1;

    if (!array || size < 2)
        return;
    while (n != 0) {
        n = 0;

        for (i = 0; i < size; i++) {
            if (array[i - 1] > array[i]) {
                int_swap(&array[i - 1], &array[i];
                print_array(array, size);
                n++;
            }
        }
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
