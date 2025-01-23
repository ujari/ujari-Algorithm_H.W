/*
작성일 : 2024_09_25
작성자 : 최윤호
프로그램 명 : 학생정보 정렬 프로그램
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//학생정보를 담을 데이터 구조체
typedef struct element {
	int stu_num;
	int score;
	char* name;
}element;

//노드 구조체
typedef struct ListNode { 	// 노드 타입
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

//연결리스트의 노드 개수를 반환하는 함수
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
	printf("%s\t%12s%24s\n\n", "학번","이름","성적");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d\t%-20s%7d\n", p->data.stu_num, p->data.name, p->data.score);
}

//학번 순 버블정렬 함수
ListNode* Sort_Stunum(ListNode* head,int Count)
{
	ListNode* p;//비교할 데이터를 가르키는 포인터
	ListNode* prev;//비교할 데이터의 전 인덱스를 가르키는 포인터
	ListNode* fir = head;//노드 순서에 맞게 head포인터를 새로고침하기 위한 포인터
	
	//내림차순으로 정렬 (~후배(학번이 낮음))
	for (int i = 0; i < Count - 1 ; i++)//데이터 n-1번반복
	{
		p = fir->link;//비교할 데이터를 맨 처음 데이터의 다음 데이터로 지정
		prev = fir;//비교할 데이터의 전 인덱스 데이터를 지정
		for (int j = 0; j < Count - i-1; j++)//n-i-1번 반복
		{

			//첫번째 노드인경우
			if (j == 0)
			{
				//첫번째 노드의 경우 실질적인 첫 노드는 prev의 학번이므로 prev에 저장 학번값을 비교
				if ((prev)->data.stu_num > (p)->data.stu_num)//prev의 학번이 실질적인 2번째 인덱스 p의 학번보다 작으면
				{
					prev->link = p->link; //3번째 노드를 첫번째 노드인 prev의 링크에 연결
					p->link = prev;//2번째 노드인 p를 첫번째 노드로 만들기 위에 1번째 노드인 prev앞으로 오도록 연결
					prev = p;//prev에 1번째 노드로 바뀐 p를 대입
					p = p->link;//2번째 노드를 가르키게 하기위해 1번째 노드로 바뀐 p의 링크로 이동
					fir = prev;//변경 후 1번째 노드인 prev를 fir에 저장;
				}
			}
			else
			{
				if (p->data.stu_num > p->link->data.stu_num)
				{
					prev->link = p->link;//p노드의 전 노드를 p노드의 다음노드 바로 전에 오도록 연결
					p->link = p->link->link;//p노드가 p->link 노드에 위치해야 하기때문에 p노드를 p->link->link 바로 전에 오도록 연걸
					prev->link->link = p;//원래 p의 다음노드였던 노드를 p의 바로 전에 연결
					prev = prev->link;//p가 한칸 이동 했기 때문에 prev 노드도 한칸 앞으로 이동
				}
				else
				{
					p = p->link;//p다음 노드가 p보다 큰 경우이기 때문에 비교할 데이터를 p->link로 대입
					prev = prev->link;//p가 한칸 이동 했기 때문에 prev 노드도 한칸 앞으로 이동
				}
			}
		}
	}

	return fir;//최종적인 head노드를 반환
}


//총점순 버블정렬 함수
ListNode* Sort_Score(ListNode* head, int Count)
{
	ListNode* p;//비교할 데이터를 가르키는 포인터
	ListNode* prev;//비교할 데이터의 전 인덱스를 가르키는 포인터
	ListNode* fir = head;//노드 순서에 맞게 head포인터를 새로고침하기 위한 포인터

	//내림차순으로 정렬 (~낮은 성적)
	for (int i = 0; i < Count - 1; i++)//데이터 n-1번반복
	{
		p = fir->link;//비교할 데이터를 맨 처음 데이터의 다음 데이터로 지정
		prev = fir;//비교할 데이터의 전 인덱스 데이터를 지정

		for (int j = 0; j < Count - i-1; j++)//n-i-1번 반복
		{

			//첫번째 노드인경우
			if (j == 0)
			{
				//첫번째 노드의 경우 실질적인 첫 노드는 prev에 저장된 성적이므로 prev에 저장된 성적값을 비교
				if (prev->data.score < p->data.score)
				{
					prev->link = p->link; //3번째 노드를 첫번째 노드인 prev의 링크에 연결
					p->link = prev;//2번째 노드인 p를 첫번째 노드로 만들기 위에 1번째 노드인 prev앞으로 오도록 연결
					prev = p;//prev에 1번째 노드로 바뀐 p를 대입
					p = p->link;//2번째 노드를 가르키게 하기위해 1번째 노드로 바뀐 p의 링크로 이동
					fir = prev;//변경 후 1번째 노드인 prev를 fir에 저장;
				}
			}
			else
			{
				if ( p->data.score < p->link->data.score)//비교할 데이터를 담고있는 노드 p의 성적이 다음 노드의 학번보다 작은 경우
				{

					prev->link = p->link;//p노드의 전 노드를 p노드의 다음노드 바로 전에 오도록 연결
					p->link = p->link->link;//p노드가 p->link 노드에 위치해야 하기때문에 p노드를 p->link->link 바로 전에 오도록 연걸
					prev->link->link = p;//원래 p의 다음노드였던 노드를 p의 바로 전에 연결
					prev = prev->link;//p가 한칸 이동 했기 때문에 prev 노드도 한칸 앞으로 이동
				}
				else
				{
					p = p->link;//p다음 노드의 학번이 p의 성적 보다 작은 경우이기 때문에 비교할 데이터를 p->link로 대입
					prev = prev->link;//p가 한칸 이동 했기 때문에 prev 노드도 한칸 앞으로 이동
				}
			}
		}
	}

	return fir;//최종적인 head노드를 반환
}

//이름 순 버블정렬 함수
ListNode* Sort_Name(ListNode* head, int Count)
{
	ListNode* p;//비교할 데이터를 가르키는 포인터
	ListNode* prev;//비교할 데이터의 전 인덱스를 가르키는 포인터
	ListNode* fir = head;//노드 순서에 맞게 head포인터를 새로고침하기 위한 포인터

	//오름차순 (~ㅎ) 으로 정렬  
	for (int i = 0; i < Count - 1; i++)//데이터 n-1번반복
	{
		p = fir->link;//비교할 데이터를 맨 처음 데이터의 다음 데이터로 지정
		prev = fir;//비교할 데이터의 전 인덱스 데이터를 지정
		for (int j = 0; j < Count - i-1; j++)//n-i-1번 반복
		{

			//첫번째 노드인경우
			if (j == 0)
			{
				//첫번째 노드의 경우 실질적인 첫 노드는 prev변수이므로 prev에 저장된 값을 비교
				if (strcmp((prev)->data.name , (p)->data.name)>0)//strcmp함수를 이용해 prev의 값이 실질적인 2번째 인덱스 p보다 크면 
				{
					prev->link = p->link; //3번째 노드를 첫번째 노드인 prev의 링크에 연결
					p->link = prev;//2번째 노드인 p를 첫번째 노드로 만들기 위에 1번째 노드인 prev앞으로 오도록 연결
					prev = p;//prev에 1번째 노드로 바뀐 p를 대입
					p = p->link;//2번째 노드를 가르키게 하기위해 1번째 노드로 바뀐 p의 링크로 이동
					fir = prev;//변경 후 1번째 노드인 prev를 fir에 저장;
				}
			}
			else
			{
				if ((strcmp(p->data.name , p->link->data.name) >0))//비교할 데이터를 담고있는 노드 p가 다음 노드보다 큰 경우
				{
					prev->link = p->link;//p노드의 전 노드를 p노드의 다음노드 바로 전에 오도록 연결
					p->link = p->link->link;//p노드가 p->link 노드에 위치해야 하기때문에 p노드를 p->link->link 바로 전에 오도록 연걸
					prev->link->link = p;//원래 p의 다음노드였던 노드를 p의 바로 전에 연결
					prev = prev->link;//p가 한칸 이동 했기 때문에 prev 노드도 한칸 앞으로 이동
				}
				else//그렇지 않은경우
				{
					p = p->link;//p다음 노드가 p보다 큰 경우이기 때문에 비교할 데이터를 p->link로 대입
					prev = prev->link;//p가 한칸 이동 했기 때문에 prev 노드도 한칸 앞으로 이동
				}
			}
		}
	}

	return fir;//최종적인 head노드를 반환
}

//동적할당 해제 함수
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


// 테스트 프로그램
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
		//연결리스트에 추가
		head=insert_first(head,data);
	}

	//node개수 탐색
	int Count = Count_Node(head);
	//학번순 정렬 후 출력
	head = Sort_Stunum(head, Count);
	printf("===========================================================\n\t\t학번순 정렬 (오름차순)\n===========================================================\n\n");
	print_list(head);

	//이름순 정렬 후 출력
	head = Sort_Name(head, Count);
	printf("\n===========================================================\n\t\t이름순 정렬 (ㄱ ~ ㅎ)\n===========================================================\n\n");
	print_list(head);


	//총점순 정렬 후 출력
	head = Sort_Score(head, Count);
	printf("\n===========================================================\n\t\t총점순 정렬 (내림차순)\n===========================================================\n\n");
	print_list(head);

	//동적할당 메모리 해제
	node_free(head);

	return 0;
}