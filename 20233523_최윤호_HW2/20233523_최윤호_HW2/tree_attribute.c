/*
트리의 노드 개수, 단말 노드의 개수, 트리의 높이를 구하는 코드를 구현한 소스 파일
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree_data.h"

//전체 노드 개수 구하기
int count_node(node* root)//노드 개수를 구하는 함수
{
    int re = 0;//리턴값을 저장할 변수
    if (root != NULL)//루트노드가 비어있지 않을 경우
    {
        re = 1 + count_node(root->left) + count_node(root->right);//노드 개수를 구하는 재귀함수
    }
    return re;
}


//단말 노드 개수 구하기
int count_leaf(node* root)//단말 노드 개수를 구하는 함수
{
    int re = 0;//리턴값을 저장할 변수
    if (root != NULL)//루트노드가 비어있지 않을 경우
    {
        if (root->left == NULL && root->right == NULL)//왼쪽과 오른쪽 자식노드가 모두 비어있을 경우
        {
            return 1;//단말노드이므로 1을 반환
        }
        else//왼쪽과 오른쪽 자식노드가 모두 비어있지 않을 경우
        {
            re = count_leaf(root->left) + count_leaf(root->right);//단말 노드 개수를 구하는 재귀함수
        }
    }
    return re;//단말 노드 개수 반환
}

//트리 높이 구하기
int tree_height(node* root) 
{
    
    if (root == NULL) { // 루트 노드가 비어있을 경우
        return 0; 
    }

    int l_height = tree_height(root->left);//왼쪽 서브트리의 높이
    int r_height = tree_height(root->right);//오른쪽 서브트리의 높이

    // 더 큰 높이에 1을 더하여 현재 노드의 높이를 반환
    return 1 + (l_height > r_height ? l_height : r_height);
}
