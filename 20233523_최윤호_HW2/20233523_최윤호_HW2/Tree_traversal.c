/*
Ʈ�� ��ȸ�� ������ �ҽ� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "tree_data.h"


//��ȯ�� �̿��� ��ȸ

//���� ��ȸ
void preorder(node* root, FILE* output)
{
	if (root == NULL)
	{
		return;
	}

	fprintf(output, "%d ", root->data);//��Ʈ��� ���
	preorder(root->left, output);//���� ����Ʈ�� ��ȸ
	preorder(root->right, output);//������ ����Ʈ�� ��ȸ

}

//���� ��ȸ
void inorder(node* root, FILE* output)
{
	if (root == NULL)
	{
		return;
	}

	inorder(root->left,output);//���� ����Ʈ�� ��ȸ
	fprintf(output, "%d ", root->data);//��Ʈ��� ���
	inorder(root->right, output);//������ ����Ʈ�� ��ȸ

}

//���� ��ȸ
void postorder(node* root, FILE* output)
{
	if (root == NULL)
	{
		return;
	}

	postorder(root->left, output);//���� ����Ʈ�� ��ȸ
	postorder(root->right, output);//������ ����Ʈ�� ��ȸ
	fprintf(output, "%d ", root->data);//��Ʈ��� ���
}

//�ݺ��� �̿��� ��ȸ
int top = -1;//������ top�� -1�� �ʱ�ȭ

void push(node* stack[], node* p, int n)//���ÿ� ��带 Ǫ���ϴ� �Լ�
{
	if (top < n - 1)
	{
		stack[++top] = p;
	}
}


node* pop(node* stack[]) 
{
	if (top >= 0) { // top�� -1���� ũ�ų� ���� ��
		return stack[top--];
	}
	else
	{
		return NULL; // ������ ������� ��� NULL ��ȯ
	}
}


//�ݺ��� �̿��� ��ȸ
void preorder_by_repetition(node* stack[], node* root, int n, FILE* output)
{
	while (1) 
	{	
		// ���� �ڽ� ���� �������鼭 ��带 ���ÿ� Ǫ��
		for (; root; root = root->left) {
			fprintf(output, "%d ", root->data); // ���� ��� ���
			push(stack, root, n); // ���ÿ� ���� ��� Ǫ��
		}

		// ���ÿ��� ��带 ��
		root = pop(stack);
		if (!root) {
			break; // ������ ��������� ����
		}

		// ������ �ڽ� ���� �̵�
		root = root->right;
	}
}

//���� ��ȸ
void inorder_by_repetition(node* stack[], node* root, int n, FILE* output)
{
	while (1)
	{
		for (; root; root = root->left)//���ʼ���Ʈ���� �̵��ϸ鼭 ���ÿ� Ǫ��
		{
			push(stack, root, n);
		}

		root = pop(stack);//���ÿ��� ��
		if (!root) {
			break;
		}

		fprintf(output, "%d ", root->data);//���� ��� ���
		root = root->right;//������ ����Ʈ���� �̵�
	}
}


void postorder_by_repetition(node* stack[], node* root, int n, FILE* output)//���� ��ȸ
{
	node* temp = NULL;//�ӽ� ���

	while (1) {

		// ���� �ڽ����� �������鼭 ���ÿ� Ǫ��
		for (; root; root = root->left) {
			push(stack, root, n);
		}

		while (1)//���ÿ��� ���ϸ鼭 ���� ��ȸ
		{
			root = pop(stack);//���ÿ��� ��
			if (!root)
			{
				return;
			}

			if (!root->right || temp == root->right)//������ �ڽ��� ���ų� ������ �ڽ��� �湮�� ����� ���
			{
				fprintf(output, "%d ", root->data);//���� ��� ���
				temp = root;//�ӽ� ��忡 ���� ��� ����
			}
			else//������ �ڽ��� ���� ���
			{
				push(stack, root, n);//���ÿ� ���� ��� Ǫ��
				root = root->right;//������ ����Ʈ���� �̵�
				break;//�ݺ��� ����
			}
		}
		
	}
}
