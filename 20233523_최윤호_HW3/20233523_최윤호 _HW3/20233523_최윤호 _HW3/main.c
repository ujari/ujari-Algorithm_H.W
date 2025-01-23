#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "���.h"

//�迭 ��� �Լ�
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n-------------------------\n");
}

//���� ���� �Լ�
long long random()
{
	return (long long)rand() << 32 | rand();//64��Ʈ ���� ����
}

//������ ���� �Լ�
void create_dataset(float ratio, int n)
{
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)arr[i] = i;//���������� ������ ����
	
	//�κ������� ���� ����
	srand(time(NULL));
	for (int i = 0; i < n * ratio; i++) {//�������� ������ ����� Ƚ����ŭ �ݺ�
		//�� �ε����� �����ϰ� �����Ͽ� ����
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

//�� ���� �ð� �� �Լ�
void sort(int n)
{	int* original = (int*)malloc(sizeof(int) * n);//���� ������
	FILE* fp = fopen("data.txt", "r");
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &original[i]);
	}
	fclose(fp);
	
	int* copy = (int*)malloc(sizeof(int) * n); //���纻 ������

	//��������
	memcpy(copy, original, sizeof(int) * n);
	clock_t start = clock();
	selection_sort(copy, n);
	clock_t end = clock();
	printf("���� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

	//��������
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	insert_sort(copy, n);
	end = clock();
	printf("���� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

	//��������
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	bubble_sort(copy, n);
	end = clock();
	printf("���� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);


	//�� ����
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	shell_sort(copy, n);
	end = clock();
	printf("�� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

	//�պ� ����
	memcpy(copy, original, sizeof(int) * n);
	int* sorted = (int*)malloc(sizeof(int) * n);
	start = clock();
	merge_sort(sorted,copy, 0, n - 1, n);
	end = clock();
	free(sorted);
	printf("�պ� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

	//�� ����
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	quick_sort(copy, 0, n-1);
	end = clock();
	printf("�� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

	//������
	memcpy(copy, original, sizeof(int) * n);
	start = clock();
	heap_sort(copy, n);
	end = clock();
	printf("�� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

	//���Ͽ� ���ĵ� ������	 ����
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
	
	int n = 30;//�������� ����
	create_dataset(1, n); //������ ����

	int* original = (int*)malloc(sizeof(int) * n);
	int* copy = (int*)malloc(sizeof(int) * n);

	FILE* fp = fopen("data.txt", "r");
	for (int i = 0; i < n; i++)
	{
		fscanf(fp, "%d", &original[i]);
	}
	fclose(fp);

	printf("���� �� ������\n");
	print(original, n);
///////////////////���� ������ ���� Ȯ��///////////////////////////////
	//��������
	memcpy(copy, original,sizeof(int)* n);
	printf("���� ����\n");
	selection_sort(copy, n);
	print(copy,n);

	//��������
	memcpy(copy, original, sizeof(int) * n);
	printf("���� ����\n");
	insert_sort(copy, n);
	print(copy, n);

	//��������
	memcpy(copy, original, sizeof(int) * n);
	printf("���� ����\n");
	bubble_sort(copy, n);
	print(copy, n);

	//������
	memcpy(copy, original, sizeof(int) * n);
	printf("�� ����\n");
	shell_sort(copy, n);
	print(copy, n);

	//�պ� ����
	memcpy(copy, original, sizeof(int) * n);
	int* sorted = (int*)malloc(sizeof(int) * n); //���ĵ� ������ ����
	printf("�պ� ����\n");
	merge_sort(sorted,copy,0,n-1,n);
	free(sorted);
	print(copy, n);

	//�� ����
	memcpy(copy, original, sizeof(int) * n);
	printf("�� ����\n");
	quick_sort(copy ,0, n-1);
	print(copy, n);

	//�� ����
	memcpy(copy, original, sizeof(int) * n);
	printf("�� ����\n");
	heap_sort(copy,n);
	print(copy, n);

	free(original);
	free(copy);

//////////////////////////////���� ���º� ���� �ð� ��//////////////////////////////


	n = 2000000;//�������� ����

	printf("������ ���� : %d\n", n);
	printf("======================================================\n");
	printf("0%% ���ĵ� �����Ϳ� ���� �ð� ��\n");
	printf("======================================================\n");
	create_dataset(1, n);
	sort(n);

	printf("======================================================\n");
	printf("50%% ���ĵ� �����Ϳ� ���� �ð� ��\n");
	printf("======================================================\n");
	create_dataset(0.5, n);
	sort(n);

	printf("======================================================\n");
	printf("80%% ���ĵ� �����Ϳ� ���� �ð� ��\n");
	printf("======================================================\n");
	create_dataset(0.2, n);
	sort(n);


	printf("======================================================\n");
	printf("95%% ���ĵ� �����Ϳ� ���� �ð� ��\n");
	printf("======================================================\n");
	create_dataset(0.05, n);
	sort(n);

	return 0;

}