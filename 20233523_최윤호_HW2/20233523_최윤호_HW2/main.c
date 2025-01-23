/*
작성일 : 2024_10_10
작성자 : 최윤호
프로그램 명 : 이진트리 구현 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "tree_data.h"

//tree에 할당한 메모리 해제
void delete_tree(node* root)
{
	if (root == NULL)
	{
		return;
	}

	delete_tree(root->left);//왼쪽 서브트리 삭제
	delete_tree(root->right);//오른쪽 서브트리 삭제
	free(root);
}

int main()
{

	FILE* fp;
	fp = fopen("data.txt", "r");
	//루트 노드 생성
	node* root_in_circulation_Tree = (node*)malloc(sizeof(node));
	element data;

	//파일 출력
	FILE* output;
	output = fopen("output.txt", "w");

	///////////////////////////////////////노드 삽입///////////////////////////////////////
	printf("========================================================================\n");
	printf("노드 삽입의 소요시간\n");
	printf("========================================================================\n\n");
	//순환을 이용한 삽입연산
	clock_t start = clock();
	fscanf(fp, "%d", &data);//루트 노드 생성
	root_in_circulation_Tree->data = data;//루트 노드 생성
	root_in_circulation_Tree->left = root_in_circulation_Tree->right = NULL;//루트 노드 생성
	while (!feof(fp))//파일의 끝까지 읽어들임
	{
		fscanf(fp, "%d", &data);//파일에서 데이터를 읽어들임
		insert_node_by_circulation(root_in_circulation_Tree, data);//삽입연산
	}
	clock_t end = clock();

	printf("순환을 이용한 삽입의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//파일포인터를 맨 처음으로
	rewind(fp);

	node* root_in_repetition_Tree = (node*)malloc(sizeof(node));//루트 노드 생성

	//반복을 이용한 삽입연산
	start = clock();
	fscanf(fp, "%d", &data);
	root_in_repetition_Tree->data = data;
	root_in_repetition_Tree->left = root_in_repetition_Tree->right = NULL;
	while (!feof(fp))
	{
		fscanf(fp, "%d", &data);
		insert_node_by_repetition(&root_in_repetition_Tree, data);
	}
	end = clock();
	printf("반복을 이용한 삽입의 소요 시간: %lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);

	
	printf("========================================================================\n");
	printf("트리 속성\n");
	printf("========================================================================\n\n");
	//트리의 노드 대수, 단말 노드 개수 , 높이
	int height = tree_height(root_in_circulation_Tree);//트리의 높이
	int n = count_node(root_in_circulation_Tree);//트리의 전체 노드 개수
	printf("트리의 전체 노드 개수 : %d\n",n);
	printf("트리의 높이 : %d\n", height);
	printf("트리의 단말 노드 개수 : %d\n", count_leaf(root_in_circulation_Tree));



	///////////////////////////////////////트리 순회///////////////////////////////////////
	printf("\n========================================================================\n");
	printf("순회 시간 비교\n");
	printf("========================================================================\n");
	//순환을 이용한 트리 순회
	printf("\n순환을 이용한 순회의 소요시간\n\n");
	fprintf(output, "순환을 이용한 순회\n\n");
	//전위 순회
	fprintf(output, "전위 순회\n");
	start = clock();
	preorder(root_in_repetition_Tree, output);
	end = clock();
	fprintf(output, "\n");
	printf("전위 순회의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//중위 순회
	fprintf(output, "중위 순회\n");
	start = clock();
	inorder(root_in_repetition_Tree, output);
	end = clock();
	fprintf(output, "\n");
	printf("중위 순회의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//후위 순회
	fprintf(output, "후위 순회\n");
	start = clock();
	postorder(root_in_repetition_Tree, output);
	end = clock();
	printf("후위 순회의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	///////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////
	
	//반복(스택)을 이용한 트리 순회
	node** stack = (node**)malloc(sizeof(node*) * n);//스택 생성
	printf("\n반복을 이용한 순회의 소요시간\n\n");
	fprintf(output, "\n\n반복을 이용한 순회\n\n");
	//전위 순회
	fprintf(output, "전위 순회\n");
	start = clock();
	preorder_by_repetition(stack,root_in_repetition_Tree, n,output);
	end = clock();
	fprintf(output, "\n");
	printf("전위 순회의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//중위 순회
	fprintf(output, "중위 순회\n");
	start = clock();
	inorder_by_repetition(stack, root_in_repetition_Tree, n, output);
	end = clock();
	fprintf(output, "\n");
	printf("중위 순회의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//후위 순회
	fprintf(output, "후위 순회\n");
	start = clock();
	postorder_by_repetition(stack, root_in_repetition_Tree, n, output);
	end = clock();
	printf("후위 순회의 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("========================================================================\n");



	//생성된 이진트리 메모리 해제
	delete_tree(root_in_circulation_Tree);
	delete_tree(root_in_repetition_Tree);

	//파일 닫기
	fclose(fp);
	fclose(output);
	

	return 0;
}