/*
�ۼ��� : 2024_10_10
�ۼ��� : ����ȣ
���α׷� �� : ����Ʈ�� ���� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include "tree_data.h"

//tree�� �Ҵ��� �޸� ����
void delete_tree(node* root)
{
	if (root == NULL)
	{
		return;
	}

	delete_tree(root->left);//���� ����Ʈ�� ����
	delete_tree(root->right);//������ ����Ʈ�� ����
	free(root);
}

int main()
{

	FILE* fp;
	fp = fopen("data.txt", "r");
	//��Ʈ ��� ����
	node* root_in_circulation_Tree = (node*)malloc(sizeof(node));
	element data;

	//���� ���
	FILE* output;
	output = fopen("output.txt", "w");

	///////////////////////////////////////��� ����///////////////////////////////////////
	printf("========================================================================\n");
	printf("��� ������ �ҿ�ð�\n");
	printf("========================================================================\n\n");
	//��ȯ�� �̿��� ���Կ���
	clock_t start = clock();
	fscanf(fp, "%d", &data);//��Ʈ ��� ����
	root_in_circulation_Tree->data = data;//��Ʈ ��� ����
	root_in_circulation_Tree->left = root_in_circulation_Tree->right = NULL;//��Ʈ ��� ����
	while (!feof(fp))//������ ������ �о����
	{
		fscanf(fp, "%d", &data);//���Ͽ��� �����͸� �о����
		insert_node_by_circulation(root_in_circulation_Tree, data);//���Կ���
	}
	clock_t end = clock();

	printf("��ȯ�� �̿��� ������ �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//���������͸� �� ó������
	rewind(fp);

	node* root_in_repetition_Tree = (node*)malloc(sizeof(node));//��Ʈ ��� ����

	//�ݺ��� �̿��� ���Կ���
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
	printf("�ݺ��� �̿��� ������ �ҿ� �ð�: %lf\n\n", (double)(end - start) / CLOCKS_PER_SEC);

	
	printf("========================================================================\n");
	printf("Ʈ�� �Ӽ�\n");
	printf("========================================================================\n\n");
	//Ʈ���� ��� ���, �ܸ� ��� ���� , ����
	int height = tree_height(root_in_circulation_Tree);//Ʈ���� ����
	int n = count_node(root_in_circulation_Tree);//Ʈ���� ��ü ��� ����
	printf("Ʈ���� ��ü ��� ���� : %d\n",n);
	printf("Ʈ���� ���� : %d\n", height);
	printf("Ʈ���� �ܸ� ��� ���� : %d\n", count_leaf(root_in_circulation_Tree));



	///////////////////////////////////////Ʈ�� ��ȸ///////////////////////////////////////
	printf("\n========================================================================\n");
	printf("��ȸ �ð� ��\n");
	printf("========================================================================\n");
	//��ȯ�� �̿��� Ʈ�� ��ȸ
	printf("\n��ȯ�� �̿��� ��ȸ�� �ҿ�ð�\n\n");
	fprintf(output, "��ȯ�� �̿��� ��ȸ\n\n");
	//���� ��ȸ
	fprintf(output, "���� ��ȸ\n");
	start = clock();
	preorder(root_in_repetition_Tree, output);
	end = clock();
	fprintf(output, "\n");
	printf("���� ��ȸ�� �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//���� ��ȸ
	fprintf(output, "���� ��ȸ\n");
	start = clock();
	inorder(root_in_repetition_Tree, output);
	end = clock();
	fprintf(output, "\n");
	printf("���� ��ȸ�� �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//���� ��ȸ
	fprintf(output, "���� ��ȸ\n");
	start = clock();
	postorder(root_in_repetition_Tree, output);
	end = clock();
	printf("���� ��ȸ�� �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	///////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////
	
	//�ݺ�(����)�� �̿��� Ʈ�� ��ȸ
	node** stack = (node**)malloc(sizeof(node*) * n);//���� ����
	printf("\n�ݺ��� �̿��� ��ȸ�� �ҿ�ð�\n\n");
	fprintf(output, "\n\n�ݺ��� �̿��� ��ȸ\n\n");
	//���� ��ȸ
	fprintf(output, "���� ��ȸ\n");
	start = clock();
	preorder_by_repetition(stack,root_in_repetition_Tree, n,output);
	end = clock();
	fprintf(output, "\n");
	printf("���� ��ȸ�� �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//���� ��ȸ
	fprintf(output, "���� ��ȸ\n");
	start = clock();
	inorder_by_repetition(stack, root_in_repetition_Tree, n, output);
	end = clock();
	fprintf(output, "\n");
	printf("���� ��ȸ�� �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	//���� ��ȸ
	fprintf(output, "���� ��ȸ\n");
	start = clock();
	postorder_by_repetition(stack, root_in_repetition_Tree, n, output);
	end = clock();
	printf("���� ��ȸ�� �ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("========================================================================\n");



	//������ ����Ʈ�� �޸� ����
	delete_tree(root_in_circulation_Tree);
	delete_tree(root_in_repetition_Tree);

	//���� �ݱ�
	fclose(fp);
	fclose(output);
	

	return 0;
}