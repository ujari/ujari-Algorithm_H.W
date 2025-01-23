#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "헤더.h"


//인덱스 번호를 통해 스왑하는 함수
void swap(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


//선택	정렬
void selection_sort(int arr[], int n)
{
	int least; //가장 작은 값의 인덱스
	for (int i = 0; i < n - 1; i++) //마지막 요소는 자동으로 정렬되므로 n-1까지만 반복
	{
		least = i; //가장 작은 값의 인덱스를 i로 초기화
		for (int j = i + 1; j < n; j++) 
		{
			if (arr[j] < arr[least])least = j; //가장 작은 값의 인덱스를 찾음
		}
		swap(arr, i, least); //가장 작은 값과 i번째 값을 교환
	}
}

//삽입 정렬
void insert_sort(int arr[], int n)
{
	int key, j;

	for (int i = 1; i < n; i++) { //첫번째 요소는 자동으로 정렬되므로 1부터 시작
		key = arr[i]; //key에 i번째 값을 저장
		for (j = i - 1; j >= 0 && arr[j] > key; j--) //key보다 큰 값을 찾을 때까지 반복
		{
			arr[j + 1] = arr[j];	//key보다 큰 값을 한 칸씩 뒤로 이동
		}
		arr[j + 1] = key; //key값을 삽입

	}
}

//간격을 이용한 삽입 정렬
void inc_insert_sort(int arr[], int fir, int last, int gap)
{
	int key; int j; 

	for (int i = fir + gap; i <= last; i += gap)  //간격을 통래 삽입 정렬
	{
		key = arr[i]; //key에 i번째 값을 저장
		for (j = i - gap; j >= fir && arr[j] > key; j -= gap)  //key보다 큰 값을 찾을 때까지 반복
		{
			arr[j + gap] = arr[j];//key보다 큰 값을 한 칸씩 뒤로 이동
		}
		arr[j + gap] = key;//key값을 삽입
	}
}

//쉘 정렬
void shell_sort(int arr[], int n)
{
	int gap; //간격
	for (gap = n / 2; gap > 0; gap /= 2) //간격을 절반씩 줄여가며 반복
	{
		if (gap % 2 == 0)gap++;//간격이 짝수일 경우 홀수로 만들어줌

		for (int i = 0; i < gap; i++)//간격만큼 반복
		{
			inc_insert_sort(arr, i, n - 1, gap);//간격을 이용한 삽입 정렬
		}
	}
}

//버블 정렬
void bubble_sort(int arr[], int n)
{
	for (int i = n - 1; i > 0; i--)//마지막 요소는 자동으로 정렬되므로 n-1까지만 반복
	{
		for (int j = 0; j < i; j++)//마지막 요소는 자동으로 정렬되므로 i까지만 반복
		{
			if (arr[j] > arr[j + 1])//j번째 값이 j+1번째 값보다 크면
			{
				swap(arr, j, j + 1);//두 값을 스왑
			}
		}
	}
}

//합병 정렬
void merge(int sorted[],int arr[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left; //i는 왼쪽 배열의 시작, j는 오른쪽 배열의 시작, k는 정렬된 배열의 시작
	int l; //반복문을 위한 변수

	while (i <= mid && j <= right) { //왼쪽 배열과 오른쪽 배열을 비교하면서 정렬
		if (arr[i] <= arr[j]) //왼쪽 배열의 값이 오른쪽 배열의 값보다 작거나 같으면
			sorted[k++] = arr[i++];
		else //오른쪽 배열의 값이 왼쪽 배열의 값보다 작으면
			sorted[k++] = arr[j++];
	}

	if (i > mid) { //왼쪽 배열이 먼저 끝난 경우
		for (l = j; l <= right; l++)//오른쪽 배열의 남은 값들을 일괄 복사
			sorted[k++] = arr[l];
	}
	else { //오른쪽 배열이 먼저 끝난 경우
		for (l = i; l <= mid; l++)//왼쪽 배열의 남은 값들을 일괄 복사
			sorted[k++] = arr[l];
	}

	//정렬된 배열을 원래 배열에 복사
	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];

}

//합병 정렬
void merge_sort(int sorted[],int arr[], int left, int right)
{

	if (left < right) {
		int mid = (left + right) / 2; //중간값을 구함
		merge_sort(sorted, arr, left, mid);//왼쪽 배열을 정렬
		merge_sort(sorted, arr, mid + 1, right);//오른쪽 배열을 정렬
		merge(sorted, arr, left, mid, right);//정렬된 두 배열을 합병
	}
}

//퀵 정렬
int partition(int arr[], int left, int right)
{
	int pivot, low, high; //피벗, low, high
	low = left; //low는 왼쪽 끝
	high = right + 1; //high는 오른쪽 끝
	pivot = arr[left];//피벗은 가장 왼쪽 값

	do {//low와 high가 교차할 때까지 반복
		do {//low가 피벗보다 큰 값을 찾을 때까지 반복
			low++;

		} while (low <= right && arr[low] < pivot);
		do//high가 피벗보다 작은 값을 찾을 때까지 반복
		{
			high--;
		} while (high >= left && arr[high] > pivot);
		if (low < high)swap(arr, low, high);//low와 high가 교차하지 않았다면 low와 high를 스왑
	} while (low < high);
	swap(arr, left, high);//low와 high가 교차하면 피벗과 high를 스왑

	return high;
}

//퀵 정렬
void quick_sort(int  arr[], int left, int right)
{
	if (left < right)
	{
		int q = partition(arr, left, right);//피벗을 기준으로 나누어 q에 저장
		quick_sort(arr, left, q - 1);//왼쪽 부분집합을 퀵정렬
		quick_sort(arr, q + 1, right);//오른쪽 부분집합을 퀵정렬
	}
}

// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h, int n)
{
	h->heap_size = 0;
	h->heap = (HeapType*)malloc(sizeof(HeapType) * n);
}

// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;// 삭제된 노드의 위치에 마지막 노드를 삽입
	return item;
}

// 힙 정렬
void heap_sort(element arr[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h, n);
	for (i = 0; i < n; i++) {//힙에 요소들을 삽입
		insert_max_heap(h, arr[i]);
	}
	for (i = (n - 1); i >= 0; i--) {//힙에서 요소들을 삭제
		arr[i] = delete_max_heap(h);//삭제된 요소들을 배열에 저장
	}
	free(h);
}