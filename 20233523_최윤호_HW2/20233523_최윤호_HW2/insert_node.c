/*
��带 �����ϴ� �ڵ带 ������ �ҽ� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>.
#include "tree_data.h"

//��� ����
node* create_node(element data)
{
	node* new_node = (node*)malloc(sizeof(node));//��� ����
	new_node->data = data;
	new_node->left = new_node->right = NULL;

	return new_node;//������ ��� ��ȯ
}

//��ȯ(���)�� �̿��� ����Ʈ�� ����
node* insert_node_by_circulation(node* root, element data)
{
	if (root == NULL)//��Ʈ��尡 ������� ���
	{
		root = create_node(data);//���ο� ��� ����
		return root;//������ ��� ��ȯ
	}

	if (root->data < data)//���ο� ����� �����Ͱ� ��Ʈ����� ������ ���� ū(������)�� ���
	{
		root->right = insert_node_by_circulation(root->right, data);//������ ����Ʈ���� ����
	}
	else if (root->data > data)//���ο� ����� �����Ͱ� ��Ʈ����� ������ ���� ����(����)�� ���
	{
		root->left = insert_node_by_circulation(root->left, data);//���� ����Ʈ���� ����
	}

	return root;//���Ե� ��Ʈ��� ��ȯ
}

//�ݺ��� �̿��� ����Ʈ�� ����
void insert_node_by_repetition(node** root, element data)//���������͸� ����ϴ� ������ ��Ʈ��尡 ����� �� �ֱ� ����
{

	node* p, * t;//p�� �θ�, t�� �ڽ�

	t = *root;//��Ʈ��带 ����Ű�� ������
	p = NULL;//�θ��带 ����Ű�� ������

	//�����ؾ��� ��ġ Ž��
	while (t != NULL)//t�� NULL�� �ƴҶ����� �ݺ�
	{
		p = t;//�θ��带 ����Ű�� �����Ϳ� �ڽĳ�带 ����Ű�� �����͸� ����
		if (t->data > data)//���ο� ����� �����Ͱ� ��Ʈ����� ������ ���� ���� (����)�� ���
		{
			t = t->left;//���� ����Ʈ���� �̵�
		}
		else if (t->data < data)//���ο� ����� �����Ͱ� ��Ʈ����� ������ ���� ū (������)�� ���
		{
			t = t->right;//������ ����Ʈ���� �̵�
		}
		else//�ߺ��� ���� ���� ���
		{
			return;//�Լ� ����
		}
	}

	//��� �߰�
	node* new_node = create_node(data);//���ο� ��� ����
	if (p == NULL)//�θ��尡 ������� ���
	{
		*root = new_node;//��Ʈ��忡 ���ο� ��� ����
	}
	else//�θ��尡 ������� ���� ���
	{
		if (p->data > data)//������ ��ġ�� �θ��庸�� ����(����)�� ���
		{
			p->left = new_node;//���� ����Ʈ���� ����
		}
		else {
			p->right = new_node;//������ ����Ʈ���� ����
		}
	}
}

