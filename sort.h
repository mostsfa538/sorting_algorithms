#ifndef SORT
#define SORT


#include <stdlib.h>
#include <stdio.h>



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void int_swap(int *a, int *b);
void list_swap(listint_t *a, listint_t *b, listint_t **head);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void quick_sort_rec(int *array, int lower, int higher, size_t size);
int lomuto_partition(int *array, int lower, int higher, size_t size);

void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);
void buildHeap(int *array, size_t size);
void heapify(int *array, size_t size, size_t i);

void radix_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int exp);
int find_max(int *array, size_t size);
#endif
