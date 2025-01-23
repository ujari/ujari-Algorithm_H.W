#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "���.h"


//�ε��� ��ȣ�� ���� �����ϴ� �Լ�
void swap(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


//����	����
void selection_sort(int arr[], int n)
{
	int least; //���� ���� ���� �ε���
	for (int i = 0; i < n - 1; i++) //������ ��Ҵ� �ڵ����� ���ĵǹǷ� n-1������ �ݺ�
	{
		least = i; //���� ���� ���� �ε����� i�� �ʱ�ȭ
		for (int j = i + 1; j < n; j++) 
		{
			if (arr[j] < arr[least])least = j; //���� ���� ���� �ε����� ã��
		}
		swap(arr, i, least); //���� ���� ���� i��° ���� ��ȯ
	}
}

//���� ����
void insert_sort(int arr[], int n)
{
	int key, j;

	for (int i = 1; i < n; i++) { //ù��° ��Ҵ� �ڵ����� ���ĵǹǷ� 1���� ����
		key = arr[i]; //key�� i��° ���� ����
		for (j = i - 1; j >= 0 && arr[j] > key; j--) //key���� ū ���� ã�� ������ �ݺ�
		{
			arr[j + 1] = arr[j];	//key���� ū ���� �� ĭ�� �ڷ� �̵�
		}
		arr[j + 1] = key; //key���� ����

	}
}

//������ �̿��� ���� ����
void inc_insert_sort(int arr[], int fir, int last, int gap)
{
	int key; int j; 

	for (int i = fir + gap; i <= last; i += gap)  //������ �뷡 ���� ����
	{
		key = arr[i]; //key�� i��° ���� ����
		for (j = i - gap; j >= fir && arr[j] > key; j -= gap)  //key���� ū ���� ã�� ������ �ݺ�
		{
			arr[j + gap] = arr[j];//key���� ū ���� �� ĭ�� �ڷ� �̵�
		}
		arr[j + gap] = key;//key���� ����
	}
}

//�� ����
void shell_sort(int arr[], int n)
{
	int gap; //����
	for (gap = n / 2; gap > 0; gap /= 2) //������ ���ݾ� �ٿ����� �ݺ�
	{
		if (gap % 2 == 0)gap++;//������ ¦���� ��� Ȧ���� �������

		for (int i = 0; i < gap; i++)//���ݸ�ŭ �ݺ�
		{
			inc_insert_sort(arr, i, n - 1, gap);//������ �̿��� ���� ����
		}
	}
}

//���� ����
void bubble_sort(int arr[], int n)
{
	for (int i = n - 1; i > 0; i--)//������ ��Ҵ� �ڵ����� ���ĵǹǷ� n-1������ �ݺ�
	{
		for (int j = 0; j < i; j++)//������ ��Ҵ� �ڵ����� ���ĵǹǷ� i������ �ݺ�
		{
			if (arr[j] > arr[j + 1])//j��° ���� j+1��° ������ ũ��
			{
				swap(arr, j, j + 1);//�� ���� ����
			}
		}
	}
}

//�պ� ����
void merge(int sorted[],int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left; //i�� ���� �迭�� ����, j�� ������ �迭�� ����, k�� ���ĵ� �迭�� ����
	int l; //�ݺ����� ���� ����

	while (i <= mid && j <= right) { //���� �迭�� ������ �迭�� ���ϸ鼭 ����
		if (arr[i] <= arr[j]) //���� �迭�� ���� ������ �迭�� ������ �۰ų� ������
			sorted[k++] = arr[i++];
		else //������ �迭�� ���� ���� �迭�� ������ ������
			sorted[k++] = arr[j++];
	}

	if (i > mid) { //���� �迭�� ���� ���� ���
		for (l = j; l <= right; l++)//������ �迭�� ���� ������ �ϰ� ����
			sorted[k++] = arr[l];
	}
	else { //������ �迭�� ���� ���� ���
		for (l = i; l <= mid; l++)//���� �迭�� ���� ������ �ϰ� ����
			sorted[k++] = arr[l];
	}

	//���ĵ� �迭�� ���� �迭�� ����
	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];

}

//�պ� ����
void merge_sort(int sorted[],int arr[], int left, int right)
{

	if (left < right) {
		int mid = (left + right) / 2; //�߰����� ����
		merge_sort(sorted, arr, left, mid);//���� �迭�� ����
		merge_sort(sorted, arr, mid + 1, right);//������ �迭�� ����
		merge(sorted, arr, left, mid, right);//���ĵ� �� �迭�� �պ�
	}
}

//�� ����
int partition(int arr[], int left, int right)
{
	int pivot, low, high; //�ǹ�, low, high
	low = left; //low�� ���� ��
	high = right + 1; //high�� ������ ��
	pivot = arr[left];//�ǹ��� ���� ���� ��

	do {//low�� high�� ������ ������ �ݺ�
		do {//low�� �ǹ����� ū ���� ã�� ������ �ݺ�
			low++;

		} while (low <= right && arr[low] < pivot);
		do//high�� �ǹ����� ���� ���� ã�� ������ �ݺ�
		{
			high--;
		} while (high >= left && arr[high] > pivot);
		if (low < high)swap(arr, low, high);//low�� high�� �������� �ʾҴٸ� low�� high�� ����
	} while (low < high);
	swap(arr, left, high);//low�� high�� �����ϸ� �ǹ��� high�� ����

	return high;
}

//�� ����
void quick_sort(int  arr[], int left, int right)
{
	if (left < right)
	{
		int q = partition(arr, left, right);//�ǹ��� �������� ������ q�� ����
		quick_sort(arr, left, q - 1);//���� �κ������� ������
		quick_sort(arr, q + 1, right);//������ �κ������� ������
	}
}

// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h, int n)
{
	h->heap_size = 0;
	h->heap = (HeapType*)malloc(sizeof(HeapType) * n);
}

// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}

// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;// ������ ����� ��ġ�� ������ ��带 ����
	return item;
}

// �� ����
void heap_sort(element arr[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h, n);
	for (i = 0; i < n; i++) {//���� ��ҵ��� ����
		insert_max_heap(h, arr[i]);
	}
	for (i = (n - 1); i >= 0; i--) {//������ ��ҵ��� ����
		arr[i] = delete_max_heap(h);//������ ��ҵ��� �迭�� ����
	}
	free(h);
}