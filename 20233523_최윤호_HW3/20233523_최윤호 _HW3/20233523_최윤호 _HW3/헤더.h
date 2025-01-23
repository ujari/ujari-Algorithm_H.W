#pragma once
typedef struct {
	int key;
} element;
typedef struct {
	element* heap;
	int heap_size;
} HeapType;

void swap(int arr[], int i, int j);
void print(int arr[], int n);
void selection_sort(int arr[], int n);
void insert_sort(int arr[], int n);
void inc_insert_sort(int arr[], int fir, int last, int gap);
void shell_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void merge(int sorted[],int arr[], int left, int mid, int right, int n);
void merge_sort(int sorted[],int arr[], int left, int right, int n);
int partition(int arr[], int left, int right);
void quick_sort(int arr[], int left, int right);
HeapType* create();
void init(HeapType* h, int n);
void insert_max_heap(HeapType* h, element item);
element delete_max_heap(HeapType* h);
void heap_sort(element arr[], int n);
