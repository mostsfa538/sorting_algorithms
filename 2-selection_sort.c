#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

/**
* selection_sort -  sorts an array of integers in ascending order 
* using the Selection sort algorithm
* @array: the array
* @size: the size of array
*
* Return: void
*/

void selection_sort(int *array, size_t size)
{
    size_t i = 0, j = 1, min = 0, temp, limit = size - 1;

    if (size < 2)
        return;

    while (i < limit)
	{
		if (j == size)
		{
			if (i != min)
			{
				temp = array[i];
				array[i] = array[min];
				array[min] = temp;
				print_array(array, size);
			}

			++i;
			min = i;
			j = i + 1;
			continue;
		}

		if (array[min] > array[j])
			min = j;

		++j;
	}
}
