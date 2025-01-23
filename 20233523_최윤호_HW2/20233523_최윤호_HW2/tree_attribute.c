/*
Ʈ���� ��� ����, �ܸ� ����� ����, Ʈ���� ���̸� ���ϴ� �ڵ带 ������ �ҽ� ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_data.h"

//��ü ��� ���� ���ϱ�
int count_node(node* root)//��� ������ ���ϴ� �Լ�
{
    int re = 0;//���ϰ��� ������ ����
    if (root != NULL)//��Ʈ��尡 ������� ���� ���
    {
        re = 1 + count_node(root->left) + count_node(root->right);//��� ������ ���ϴ� ����Լ�
    }
    return re;
}


//�ܸ� ��� ���� ���ϱ�
int count_leaf(node* root)//�ܸ� ��� ������ ���ϴ� �Լ�
{
    int re = 0;//���ϰ��� ������ ����
    if (root != NULL)//��Ʈ��尡 ������� ���� ���
    {
        if (root->left == NULL && root->right == NULL)//���ʰ� ������ �ڽĳ�尡 ��� ������� ���
        {
            return 1;//�ܸ�����̹Ƿ� 1�� ��ȯ
        }
        else//���ʰ� ������ �ڽĳ�尡 ��� ������� ���� ���
        {
            re = count_leaf(root->left) + count_leaf(root->right);//�ܸ� ��� ������ ���ϴ� ����Լ�
        }
    }
    return re;//�ܸ� ��� ���� ��ȯ
}

//Ʈ�� ���� ���ϱ�
int tree_height(node* root) 
{
    
    if (root == NULL) { // ��Ʈ ��尡 ������� ���
        return 0; 
    }

    int l_height = tree_height(root->left);//���� ����Ʈ���� ����
    int r_height = tree_height(root->right);//������ ����Ʈ���� ����

    // �� ū ���̿� 1�� ���Ͽ� ���� ����� ���̸� ��ȯ
    return 1 + (l_height > r_height ? l_height : r_height);
}
