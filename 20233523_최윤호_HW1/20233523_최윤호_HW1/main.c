/*
�ۼ��� : 2024_09_25
�ۼ��� : ����ȣ
���α׷� �� : �л����� ���� ���α׷�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�л������� ���� ������ ����ü
typedef struct element {
	int stu_num;
	int score;
	char* name;
}element;

//��� ����ü
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;


ListNode* insert_first(ListNode* head,element data)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = data;
	p->link = head;	
	head = p;
	return head;	
}

//���Ḯ��Ʈ�� ��� ������ ��ȯ�ϴ� �Լ�
int Count_Node(ListNode* head)
{
	ListNode* temp = head;
	int count = 1;
	for (int i = 0; temp->link != NULL; i++)
	{
		temp = temp->link;
		count++;
	}

	return count;
}

void print_list(ListNode* head)
{
	printf("%s\t%12s%24s\n\n", "�й�","�̸�","����");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d\t%-20s%7d\n", p->data.stu_num, p->data.name, p->data.score);
}

//�й� �� �������� �Լ�
ListNode* Sort_Stunum(ListNode* head,int Count)
{
	ListNode* p;//���� �����͸� ����Ű�� ������
	ListNode* prev;//���� �������� �� �ε����� ����Ű�� ������
	ListNode* fir = head;//��� ������ �°� head�����͸� ���ΰ�ħ�ϱ� ���� ������
	
	//������������ ���� (~�Ĺ�(�й��� ����))
	for (int i = 0; i < Count - 1 ; i++)//������ n-1���ݺ�
	{
		p = fir->link;//���� �����͸� �� ó�� �������� ���� �����ͷ� ����
		prev = fir;//���� �������� �� �ε��� �����͸� ����
		for (int j = 0; j < Count - i-1; j++)//n-i-1�� �ݺ�
		{

			//ù��° ����ΰ��
			if (j == 0)
			{
				//ù��° ����� ��� �������� ù ���� prev�� �й��̹Ƿ� prev�� ���� �й����� ��
				if ((prev)->data.stu_num > (p)->data.stu_num)//prev�� �й��� �������� 2��° �ε��� p�� �й����� ������
				{
					prev->link = p->link; //3��° ��带 ù��° ����� prev�� ��ũ�� ����
					p->link = prev;//2��° ����� p�� ù��° ���� ����� ���� 1��° ����� prev������ ������ ����
					prev = p;//prev�� 1��° ���� �ٲ� p�� ����
					p = p->link;//2��° ��带 ����Ű�� �ϱ����� 1��° ���� �ٲ� p�� ��ũ�� �̵�
					fir = prev;//���� �� 1��° ����� prev�� fir�� ����;
				}
			}
			else
			{
				if (p->data.stu_num > p->link->data.stu_num)
				{
					prev->link = p->link;//p����� �� ��带 p����� ������� �ٷ� ���� ������ ����
					p->link = p->link->link;//p��尡 p->link ��忡 ��ġ�ؾ� �ϱ⶧���� p��带 p->link->link �ٷ� ���� ������ ����
					prev->link->link = p;//���� p�� ������忴�� ��带 p�� �ٷ� ���� ����
					prev = prev->link;//p�� ��ĭ �̵� �߱� ������ prev ��嵵 ��ĭ ������ �̵�
				}
				else
				{
					p = p->link;//p���� ��尡 p���� ū ����̱� ������ ���� �����͸� p->link�� ����
					prev = prev->link;//p�� ��ĭ �̵� �߱� ������ prev ��嵵 ��ĭ ������ �̵�
				}
			}
		}
	}

	return fir;//�������� head��带 ��ȯ
}


//������ �������� �Լ�
ListNode* Sort_Score(ListNode* head, int Count)
{
	ListNode* p;//���� �����͸� ����Ű�� ������
	ListNode* prev;//���� �������� �� �ε����� ����Ű�� ������
	ListNode* fir = head;//��� ������ �°� head�����͸� ���ΰ�ħ�ϱ� ���� ������

	//������������ ���� (~���� ����)
	for (int i = 0; i < Count - 1; i++)//������ n-1���ݺ�
	{
		p = fir->link;//���� �����͸� �� ó�� �������� ���� �����ͷ� ����
		prev = fir;//���� �������� �� �ε��� �����͸� ����

		for (int j = 0; j < Count - i-1; j++)//n-i-1�� �ݺ�
		{

			//ù��° ����ΰ��
			if (j == 0)
			{
				//ù��° ����� ��� �������� ù ���� prev�� ����� �����̹Ƿ� prev�� ����� �������� ��
				if (prev->data.score < p->data.score)
				{
					prev->link = p->link; //3��° ��带 ù��° ����� prev�� ��ũ�� ����
					p->link = prev;//2��° ����� p�� ù��° ���� ����� ���� 1��° ����� prev������ ������ ����
					prev = p;//prev�� 1��° ���� �ٲ� p�� ����
					p = p->link;//2��° ��带 ����Ű�� �ϱ����� 1��° ���� �ٲ� p�� ��ũ�� �̵�
					fir = prev;//���� �� 1��° ����� prev�� fir�� ����;
				}
			}
			else
			{
				if ( p->data.score < p->link->data.score)//���� �����͸� ����ִ� ��� p�� ������ ���� ����� �й����� ���� ���
				{

					prev->link = p->link;//p����� �� ��带 p����� ������� �ٷ� ���� ������ ����
					p->link = p->link->link;//p��尡 p->link ��忡 ��ġ�ؾ� �ϱ⶧���� p��带 p->link->link �ٷ� ���� ������ ����
					prev->link->link = p;//���� p�� ������忴�� ��带 p�� �ٷ� ���� ����
					prev = prev->link;//p�� ��ĭ �̵� �߱� ������ prev ��嵵 ��ĭ ������ �̵�
				}
				else
				{
					p = p->link;//p���� ����� �й��� p�� ���� ���� ���� ����̱� ������ ���� �����͸� p->link�� ����
					prev = prev->link;//p�� ��ĭ �̵� �߱� ������ prev ��嵵 ��ĭ ������ �̵�
				}
			}
		}
	}

	return fir;//�������� head��带 ��ȯ
}

//�̸� �� �������� �Լ�
ListNode* Sort_Name(ListNode* head, int Count)
{
	ListNode* p;//���� �����͸� ����Ű�� ������
	ListNode* prev;//���� �������� �� �ε����� ����Ű�� ������
	ListNode* fir = head;//��� ������ �°� head�����͸� ���ΰ�ħ�ϱ� ���� ������

	//�������� (~��) ���� ����  
	for (int i = 0; i < Count - 1; i++)//������ n-1���ݺ�
	{
		p = fir->link;//���� �����͸� �� ó�� �������� ���� �����ͷ� ����
		prev = fir;//���� �������� �� �ε��� �����͸� ����
		for (int j = 0; j < Count - i-1; j++)//n-i-1�� �ݺ�
		{

			//ù��° ����ΰ��
			if (j == 0)
			{
				//ù��° ����� ��� �������� ù ���� prev�����̹Ƿ� prev�� ����� ���� ��
				if (strcmp((prev)->data.name , (p)->data.name)>0)//strcmp�Լ��� �̿��� prev�� ���� �������� 2��° �ε��� p���� ũ�� 
				{
					prev->link = p->link; //3��° ��带 ù��° ����� prev�� ��ũ�� ����
					p->link = prev;//2��° ����� p�� ù��° ���� ����� ���� 1��° ����� prev������ ������ ����
					prev = p;//prev�� 1��° ���� �ٲ� p�� ����
					p = p->link;//2��° ��带 ����Ű�� �ϱ����� 1��° ���� �ٲ� p�� ��ũ�� �̵�
					fir = prev;//���� �� 1��° ����� prev�� fir�� ����;
				}
			}
			else
			{
				if ((strcmp(p->data.name , p->link->data.name) >0))//���� �����͸� ����ִ� ��� p�� ���� ��庸�� ū ���
				{
					prev->link = p->link;//p����� �� ��带 p����� ������� �ٷ� ���� ������ ����
					p->link = p->link->link;//p��尡 p->link ��忡 ��ġ�ؾ� �ϱ⶧���� p��带 p->link->link �ٷ� ���� ������ ����
					prev->link->link = p;//���� p�� ������忴�� ��带 p�� �ٷ� ���� ����
					prev = prev->link;//p�� ��ĭ �̵� �߱� ������ prev ��嵵 ��ĭ ������ �̵�
				}
				else//�׷��� �������
				{
					p = p->link;//p���� ��尡 p���� ū ����̱� ������ ���� �����͸� p->link�� ����
					prev = prev->link;//p�� ��ĭ �̵� �߱� ������ prev ��嵵 ��ĭ ������ �̵�
				}
			}
		}
	}

	return fir;//�������� head��带 ��ȯ
}

//�����Ҵ� ���� �Լ�
void node_free(ListNode* head)
{
	while (head!=NULL)
	{
		ListNode* remove=head;
		head = head->link;
		free(remove->data.name);
		free(remove);
	}
}


// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;

	FILE* fp;
	fp=fopen("data.txt", "r");
	while (!feof(fp))
	{
		element data;
		char name[100];
		fscanf(fp,"%d %s %d", &data.stu_num, name, &data.score);
		data.name = (char*)malloc(strlen(name) + 1);
		strcpy(data.name, name);
		//���Ḯ��Ʈ�� �߰�
		head=insert_first(head,data);
	}

	//node���� Ž��
	int Count = Count_Node(head);
	//�й��� ���� �� ���
	head = Sort_Stunum(head, Count);
	printf("===========================================================\n\t\t�й��� ���� (��������)\n===========================================================\n\n");
	print_list(head);

	//�̸��� ���� �� ���
	head = Sort_Name(head, Count);
	printf("\n===========================================================\n\t\t�̸��� ���� (�� ~ ��)\n===========================================================\n\n");
	print_list(head);


	//������ ���� �� ���
	head = Sort_Score(head, Count);
	printf("\n===========================================================\n\t\t������ ���� (��������)\n===========================================================\n\n");
	print_list(head);

	//�����Ҵ� �޸� ����
	node_free(head);

	return 0;
}