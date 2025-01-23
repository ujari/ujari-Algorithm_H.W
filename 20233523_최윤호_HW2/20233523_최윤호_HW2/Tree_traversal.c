/*
트리 순회를 구현한 소스 파일
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "tree_data.h"


//순환을 이용한 순회

//전위 순회
void preorder(node* root, FILE* output)
{
	if (root == NULL)
	{
		return;
	}

	fprintf(output, "%d ", root->data);//루트노드 출력
	preorder(root->left, output);//왼쪽 서브트리 순회
	preorder(root->right, output);//오른쪽 서브트리 순회

}

//중위 순회
void inorder(node* root, FILE* output)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->left,output);//왼쪽 서브트리 순회
	fprintf(output, "%d ", root->data);//루트노드 출력
	inorder(root->right, output);//오른쪽 서브트리 순회

}

//후위 순회
void postorder(node* root, FILE* output)
{
	if (root == NULL)
	{
		return;
	}

	postorder(root->left, output);//왼쪽 서브트리 순회
	postorder(root->right, output);//오른쪽 서브트리 순회
	fprintf(output, "%d ", root->data);//루트노드 출력
}

//반복을 이용한 순회
int top = -1;//스택의 top을 -1로 초기화

void push(node* stack[], node* p, int n)//스택에 노드를 푸시하는 함수
{
	if (top < n - 1)
	{
		stack[++top] = p;
	}
}


node* pop(node* stack[]) 
{
	if (top >= 0) { // top이 -1보다 크거나 같을 때
		return stack[top--];
	}
	else
	{
		return NULL; // 스택이 비어있을 경우 NULL 반환
	}
}


//반복을 이용한 순회
void preorder_by_repetition(node* stack[], node* root, int n, FILE* output)
{
	while (1) 
	{	
		// 왼쪽 자식 노드로 내려가면서 노드를 스택에 푸시
		for (; root; root = root->left) {
			fprintf(output, "%d ", root->data); // 현재 노드 출력
			push(stack, root, n); // 스택에 현재 노드 푸시
		}

		// 스택에서 노드를 팝
		root = pop(stack);
		if (!root) {
			break; // 스택이 비어있으면 종료
		}

		// 오른쪽 자식 노드로 이동
		root = root->right;
	}
}

//중위 순회
void inorder_by_repetition(node* stack[], node* root, int n, FILE* output)
{
	while (1)
	{
		for (; root; root = root->left)//왼쪽서브트리로 이동하면서 스택에 푸시
		{
			push(stack, root, n);
		}

		root = pop(stack);//스택에서 팝
		if (!root) {
			break;
		}

		fprintf(output, "%d ", root->data);//현재 노드 출력
		root = root->right;//오른쪽 서브트리로 이동
	}
}


void postorder_by_repetition(node* stack[], node* root, int n, FILE* output)//후위 순회
{
	node* temp = NULL;//임시 노드

	while (1) {

		// 왼쪽 자식으로 내려가면서 스택에 푸시
		for (; root; root = root->left) {
			push(stack, root, n);
		}

		while (1)//스택에서 팝하면서 후위 순회
		{
			root = pop(stack);//스택에서 팝
			if (!root)
			{
				return;
			}

			if (!root->right || temp == root->right)//오른쪽 자식이 없거나 오른쪽 자식이 방문한 노드일 경우
			{
				fprintf(output, "%d ", root->data);//현재 노드 출력
				temp = root;//임시 노드에 현재 노드 대입
			}
			else//오른쪽 자식이 있을 경우
			{
				push(stack, root, n);//스택에 현재 노드 푸시
				root = root->right;//오른쪽 서브트리로 이동
				break;//반복문 종료
			}
		}
		
	}
}
