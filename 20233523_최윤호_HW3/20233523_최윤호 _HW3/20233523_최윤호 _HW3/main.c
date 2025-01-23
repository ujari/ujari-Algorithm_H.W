#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "헤더.h"

//배열 출력 함수
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n-------------------------\n");
}

//난수 추출 함수
long long random()
{
	return (long long)rand() << 32 | rand();//64비트 난수 생성
}

//데이터 생성 함수
void create_dataset(float ratio, int n)
{
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)arr[i] = i;//순차적으로 데이터 생성
	
	//부분적으로 정렬 진행
	srand(time(NULL));
	for (int i = 0; i < n * ratio; i++) {//데이터의 개수에 비례한 횟수만큼 반복
		//두 인덱스를 랜덤하게 선택하여 스왑
		int idx1 = random() % n;
		int idx2 = random() % n;
		int temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}

	FILE* fp = fopen("data.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", arr[i]);

	}
	free(arr);
	fclose(fp);

}

//각 정렬 시간 비교 함수
void sort(int n)
{	int* original = (int*)malloc(sizeof(int) * n);//원본 데이터
	FILE* fp = fopen("data.txt", "r");
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &original[i]);
	}
	fclose(fp);
	
	int* copy = (int*)malloc(sizeof(int) * n); //복사본 데이터

	//선택정렬
	memcpy(copy, original, sizeof(int) * n);
	clock_t start = clock();
	selection_sort(copy, n);
	clock_t end = clock();
	printf("선택 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	//삽입정렬
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	insert_sort(copy, n);
	end = clock();
	printf("삽입 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	//버블정렬
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	bubble_sort(copy, n);
	end = clock();
	printf("버블 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);


	//쉘 정렬
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	shell_sort(copy, n);
	end = clock();
	printf("쉘 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	//합병 정렬
	memcpy(copy, original, sizeof(int) * n);
	int* sorted = (int*)malloc(sizeof(int) * n);
	start = clock();
	merge_sort(sorted,copy, 0, n - 1, n);
	end = clock();
	free(sorted);
	printf("합병 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	//퀵 정렬
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	quick_sort(copy, 0, n-1);
	end = clock();
	printf("퀵 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	//힙정렬
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	heap_sort(copy, n);
	end = clock();
	printf("힙 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	//파일에 정렬된 데이터	 저장
	fp = fopen("data.txt", "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%d ", copy[i]);
	}

	fclose(fp);
	free(original);
	free(copy);

}



int main()
{
	
	int n = 30;//데이터의 개수
	create_dataset(1, n); //데이터 생성

	int* original = (int*)malloc(sizeof(int) * n);
	int* copy = (int*)malloc(sizeof(int) * n);

	FILE* fp = fopen("data.txt", "r");
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &original[i]);
	}
	fclose(fp);

	printf("정렬 전 데이터\n");
	print(original, n);
///////////////////실제 데이터 정렬 확인///////////////////////////////
	//선택정렬
	memcpy(copy, original,sizeof(int)* n);
	printf("선택 정렬\n");
	selection_sort(copy, n);
	print(copy,n);

	//삽입정렬
	memcpy(copy, original, sizeof(int) * n);
	printf("삽입 정렬\n");
	insert_sort(copy, n);
	print(copy, n);

	//버블정렬
	memcpy(copy, original, sizeof(int) * n);
	printf("버블 정렬\n");
	bubble_sort(copy, n);
	print(copy, n);

	//쉘정렬
	memcpy(copy, original, sizeof(int) * n);
	printf("쉘 정렬\n");
	shell_sort(copy, n);
	print(copy, n);

	//합병 정렬
	memcpy(copy, original, sizeof(int) * n);
	int* sorted = (int*)malloc(sizeof(int) * n); //정렬된 데이터 저장
	printf("합병 정렬\n");
	merge_sort(sorted,copy,0,n-1,n);
	free(sorted);
	print(copy, n);

	//퀵 정렬
	memcpy(copy, original, sizeof(int) * n);
	printf("퀵 정렬\n");
	quick_sort(copy ,0, n-1);
	print(copy, n);

	//힙 정렬
	memcpy(copy, original, sizeof(int) * n);
	printf("힙 정렬\n");
	heap_sort(copy,n);
	print(copy, n);

	free(original);
	free(copy);

//////////////////////////////정렬 상태별 수행 시간 비교//////////////////////////////


	n = 2000000;//데이터의 개수

	printf("데이터 개수 : %d\n", n);
	printf("======================================================\n");
	printf("0%% 정렬된 데이터에 대한 시간 비교\n");
	printf("======================================================\n");
	create_dataset(1, n);
	sort(n);

	printf("======================================================\n");
	printf("50%% 정렬된 데이터에 대한 시간 비교\n");
	printf("======================================================\n");
	create_dataset(0.5, n);
	sort(n);

	printf("======================================================\n");
	printf("80%% 정렬된 데이터에 대한 시간 비교\n");
	printf("======================================================\n");
	create_dataset(0.2, n);
	sort(n);


	printf("======================================================\n");
	printf("95%% 정렬된 데이터에 대한 시간 비교\n");
	printf("======================================================\n");
	create_dataset(0.05, n);
	sort(n);

	return 0;

}