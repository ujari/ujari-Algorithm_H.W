/*
노드를 삽입하는 코드를 구현한 소스 파일
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>.
#include "tree_data.h"

//노드 생성
node* create_node(element data)
{
	node* new_node = (node*)malloc(sizeof(node));//노드 생성
	new_node->data = data;
	new_node->left = new_node->right = NULL;

	return new_node;//생성된 노드 반환
}

//순환(재귀)를 이용한 이진트리 삽입
node* insert_node_by_circulation(node* root, element data)
{
	if (root == NULL)//루트노드가 비어있을 경우
	{
		root = create_node(data);//새로운 노드 생성
		return root;//생성된 노드 반환
	}

	if (root->data < data)//새로운 노드의 데이터가 루트노드의 데이터 보다 큰(오른쪽)일 경우
	{
		root->right = insert_node_by_circulation(root->right, data);//오른쪽 서브트리에 삽입
	}
	else if (root->data > data)//새로운 노드의 데이터가 루트노드의 데이터 보다 작은(왼쪽)일 경우
	{
		root->left = insert_node_by_circulation(root->left, data);//왼쪽 서브트리에 삽입
	}

	return root;//삽입된 루트노드 반환
}

//반복을 이용한 이진트리 삽입
void insert_node_by_repetition(node** root, element data)//이중포인터를 사용하는 이유는 루트노드가 변경될 수 있기 때문
{

	node* p, * t;//p는 부모, t는 자식

	t = *root;//루트노드를 가리키는 포인터
	p = NULL;//부모노드를 가리키는 포인터

	//삽입해야할 위치 탐색
	while (t != NULL)//t가 NULL이 아닐때까지 반복
	{
		p = t;//부모노드를 가리키는 포인터에 자식노드를 가리키는 포인터를 대입
		if (t->data > data)//새로운 노드의 데이터가 루트노드의 데이터 보다 작은 (왼쪽)일 경우
		{
			t = t->left;//왼쪽 서브트리로 이동
		}
		else if (t->data < data)//새로운 노드의 데이터가 루트노드의 데이터 보다 큰 (오른쪽)일 경우
		{
			t = t->right;//오른쪽 서브트리로 이동
		}
		else//중복된 값이 있을 경우
		{
			return;//함수 종료
		}
	}

	//노드 추가
	node* new_node = create_node(data);//새로운 노드 생성
	if (p == NULL)//부모노드가 비어있을 경우
	{
		*root = new_node;//루트노드에 새로운 노드 대입
	}
	else//부모노드가 비어있지 않을 경우
	{
		if (p->data > data)//삽입할 위치의 부모노드보다 작은(왼쪽)의 경우
		{
			p->left = new_node;//왼쪽 서브트리에 삽입
		}
		else {
			p->right = new_node;//오른쪽 서브트리에 삽입
		}
	}
}

