#include "sort.h"


#include <stdio.h>
#include <stdlib.h>


/**
 * merge - Merge two subarrays of array[]
 * @array: The array to be sorted
 * @temp: Temporary array to store merged subarrays
 * @left: Starting index of the first subarray
 * @mid: Middle index of the first subarray
 * @right: Ending index of the second subarray
 *
 * Return: void
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1, k = 0;

    printf("[left]: ");
    print_array(array + left, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        array[i] = temp[k];

    printf("[Done]: ");
    print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - Recursive function to sort the array
 * @array: The array to be sorted
 * @temp: Temporary array to store merged subarrays
 * @left: Starting index of the array
 * @right: Ending index of the array
 *
 * Return: void
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    size_t mid;

    if (left < right)
    {
        mid = left + (right - left) / 2;

        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid + 1, right);

        printf("Merging...\n");
        merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (!temp)
        return;

    merge_sort_recursive(array, temp, 0, size - 1);

    free(temp);
}

