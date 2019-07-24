#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//��1��������ʽջ
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}LinkStackNode, *LinkStack;

//(2)��ʽ�洢ʵ��ջ�ĳ�ʼ��
void InitStack_Link(LinkStack* top)
{
	LinkStackNode *tmp = (LinkStackNode *)malloc(sizeof(LinkStackNode));//ͷ���
	if (tmp == NULL)
		return;
	tmp->data = 0;
	tmp->next = NULL;
	*top = tmp;
}

//(3)��ʽ�洢ʵ��ջ����ջ
void Push_Link(LinkStack top, DataType x)
{
	LinkStackNode* tmp;
	tmp = (LinkStackNode*)malloc(sizeof(LinkStackNode));//����ռ�
	if (tmp == NULL)
		return;
	tmp->data = x;
	tmp->next = top->next; 
	//�޸�ջ��ָ��
	top->next = tmp;
}

//(4)��ʽ�洢ʵ��ջ�ĳ�ջ
void Pop_Link(LinkStack top, DataType* x)
{
	LinkStackNode* tmp;
	tmp = top->next;
	if (tmp == NULL)
	{
		return;
	}
	*x = tmp->data;
	top->next = tmp->next;
	free(tmp);
}
//(5)��ӡ��ʽջ
void Print(LinkStack top)
{
	LinkStackNode* ss = top->next;
	if (top == NULL)
		return;
	else
	{
		while (ss != NULL)
		{
			printf("%d ", ss->data);
			ss = ss->next;
		}
		printf("\n");
	}
}
#define Size 50
//��1������˳��ջ
typedef struct
{
	DataType arr[Size];
	int top;
}SeqStack;

//(2)˳��洢ʵ��ջ�ĳ�ʼ��
void InitStack_Seq(SeqStack* s)
{
	s->top = -1;
}

//(3)˳��洢ʵ��ջ����ջ
int Push_Seq(SeqStack* s, DataType x)
{
	//ջ����
	if (s->top == Size - 1)
		return 0;
	s->top++;
	s->arr[s->top] = x;
	return 1;
}

//(4)˳��洢ʵ��ջ�ĳ�ջ
int Pop_Seq(SeqStack* s, DataType* x)
{
	if (s->top == -1)
		return 0;
	else
	{
		*x = s->arr[s->top];
		s->top--;
		return 1;
	}
}
//(5)��ӡ˳��ջ
void Print_Seq_Stack(SeqStack s)
{
	int i = 0;
	for (i = 0; i <= s.top; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
//��3������������
typedef struct qNode
{
	DataType data;
	struct qNode* next;
}LinkQueueNode;

typedef struct
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;
//(2)��ʽ�洢ʵ�ֶ��еĳ�ʼ��
void InitQue(LinkQueue* q)
{
	q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (q->front == NULL)
	{
		return;
	}
	else
	{
		q->rear = q->front;
		q->front->next = NULL;
	}
}

//(3)��ʽ�洢ʵ�ֶ��е����
void EnterQueue(LinkQueue* q, DataType x)
{
	LinkQueueNode* NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
	else
		return;
}

//(4)��ʽ�洢ʵ�ֶ��еĳ���
void OutQueue(LinkQueue* q, DataType* x)
{
	LinkQueueNode* first = q->front->next;
	if (first == NULL)
		return;
	if (first->next == NULL)
	{
		*x = first->data;
		q->rear = q->front;
		q->front->next = NULL;
	}
	else
	{
		*x = first->data;
		q->front->next = first->next;
	}
	free(first);
	first = NULL;
}
//(5)��ӡ������
void Print_Link_Queue(LinkQueue* q)
{
	LinkQueueNode* cur = q->front;
	if (q->front == q->rear)
		return;
	while (cur != q->rear)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n");
}
//(1)����˳�����
	typedef struct
	{
		DataType arr[Size];
		int front;
		int rear;
	}SeqQueue;

	//(2)˳��洢ʵ��ѭ�����еĳ�ʼ��
	void SInitQueue(SeqQueue* q)
	{
		q->front = q->rear = 0;
	}

	//(3)˳��洢ʵ��ѭ�����е����
	int InQue(SeqQueue* q, DataType data)
	{
		//������
		if ((q->rear + 1) % Size == q->front)
			return 0;

		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % Size;
		return 1;
	}

	//(4)˳��洢ʵ��ѭ�����еĳ���
	int SOutQueue(SeqQueue* q, DataType* x)
	{
		if (q->front == q->rear)//���п�
			return 0;
		*x = q->arr[q->front];
		q->front = (q->front + 1) % Size;
		return 1;
	}
	//(5)��ӡ˳�����
	void Print_SQueue(SeqQueue* q)
	{
		int i = q->front;
		if (q->front == q->rear)
		{
			printf("��ʱ�����ǿյ�\n");
		}
		while (i != q->rear)
		{
			printf("%d ", q->arr[i]);
			i++;
			i = i % Size;
		}
		printf("\n");
	}
	//1.��ջ��ջ
	void chosestackin1()
	{
		DataType a;
		int flag = 1;
		LinkStackNode  *head = NULL;
		InitStack_Link(&head);
		while (flag)
		{
			int c;
			printf("������������֣�����111������\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[�ó������!!!]\n");
			}
			else
			{
				Push_Link(head, c);
				printf("��ջ��ջ�ɹ�\n");
				Print(head);
			}
		}
	}
	//2.˳��ջ��ջ
	void chosestackin2()
	{

		int flag = 1;
		SeqStack head;
		InitStack_Seq(&head);
		while (flag)
		{
			int c;
			printf("������������֣�����111������\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[�ó������!!!]\n");
			}
			else
			{
				Push_Seq(&head,c);
				printf("˳��ջ��ջ�ɹ�:\n");
				Print_Seq_Stack(head);
			}
		}
	}
	//3.���������
	void chosestackin3()
	{

		int flag = 1;
		LinkQueue head;
		InitQue(&head);
		while (flag)
		{
			int c;
			printf("������������֣�����111������\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[�ó������!!!]\n");
			}
			else
			{
				EnterQueue(&head, c);
				printf("��������ӳɹ�:\n");
				Print_Link_Queue(&head);
			}
		}
	}
	//4.˳��������
	void chosestackin4()
	{

		int flag = 1;
		SeqQueue head;
		SInitQueue(&head);
		while (flag)
		{
			int c;
			printf("������������֣�����111������\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[�ó������!!!]\n");
			}
			else
			{
				InQue(&head, c);
				printf("��������ӳɹ�:\n");
				Print_SQueue(&head);
			}
		}
	}
	
	void menu()
	{
		printf("\t\t\t\t\t*******************���˵�********************\n");
		printf("\t\t\t\t\t****************����1��ջ��ջ****************\n");
		printf("\t\t\t\t\t****************����2��ջ��ջ****************\n");
		printf("\t\t\t\t\t****************����3˳��ջ��ջ**************\n");
		printf("\t\t\t\t\t****************����4˳��ջ��ջ**************\n");
		printf("\t\t\t\t\t****************����5�������****************\n");
		printf("\t\t\t\t\t****************����6���ӳ���****************\n");
		printf("\t\t\t\t\t****************����7˳��������************\n");
		printf("\t\t\t\t\t****************����8˳����г���************\n");
	}


	int main()
	{
		DataType a;
		LinkQueue q;
		SeqQueue q1;
		SeqStack s;
		LinkStackNode* head = NULL;

		menu();
		int n = 0;
		while (1)
		{
			printf("���������ѡ��");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				printf("--��ջѹջ����--\n");
				chosestackin1();
				break;
			case 2:
				printf("--��ջ��ջ����--\n");
				InitStack_Link(&head);
				Push_Link(head, 9);
				Push_Link(head, 7);
				Push_Link(head, 8);
				Push_Link(head, 5);
				Push_Link(head, 3);
				Push_Link(head, 0);
				Print(head);

				Pop_Link(head, &a);
				Print(head);
				Pop_Link(head, &a);
				Print(head);
				Pop_Link(head, &a);
				Print(head);
				Pop_Link(head, &a);
				Print(head);
				Pop_Link(head, &a);
				Print(head);
				Pop_Link(head, &a);
				Print(head);
				break;
			case 3:
				printf("˳��ջѹջ���̣�\n");
				chosestackin2();
				break;
			case 4:
				printf("˳��ջ��ջ���̣�\n");
				InitStack_Seq(&s);
				Push_Seq(&s, 9);
				Push_Seq(&s, 7);
				Push_Seq(&s, 6);
				Push_Seq(&s, 55);
				Push_Seq(&s, 4);
				Push_Seq(&s, 2);
				Print_Seq_Stack(s);

				Pop_Seq(&s, &a);
				Print_Seq_Stack(s);
				Pop_Seq(&s, &a);
				Print_Seq_Stack(s);
				Pop_Seq(&s, &a);
				Print_Seq_Stack(s);
				Pop_Seq(&s, &a);
				Print_Seq_Stack(s);
				Pop_Seq(&s, &a);
				Print_Seq_Stack(s);
				Pop_Seq(&s, &a);
				Print_Seq_Stack(s);
				break;
			case 5:
				printf("������ѹջ���̣�\n");
				chosestackin3();
				break;
			case 6:
				printf("�����г�ջ���̣�\n");
				InitQue(&q);
				EnterQueue(&q, 45);
				EnterQueue(&q, 65);
				EnterQueue(&q, 75);
				EnterQueue(&q, 85);
				EnterQueue(&q, 95);
				EnterQueue(&q, 33);
				Print_Link_Queue(&q);

				OutQueue(&q, &a);
				Print_Link_Queue(&q);
				OutQueue(&q, &a);
				Print_Link_Queue(&q);
				OutQueue(&q, &a);
				Print_Link_Queue(&q);
				OutQueue(&q, &a);
				Print_Link_Queue(&q);
				OutQueue(&q, &a);
				Print_Link_Queue(&q);
				OutQueue(&q, &a);
				Print_Link_Queue(&q);
				break;
			case 7:
				printf("ѭ������ѹջ���̣�\n");
				chosestackin4();
				break;
			case 8:
				printf("ѭ�����г�ջ���̣�\n");
				SInitQueue(&q1);
				InQue(&q1, 13);
				InQue(&q1, 44);
				InQue(&q1, 55);
				InQue(&q1, 76);
				InQue(&q1, 90);
				Print_SQueue(&q1);

				SOutQueue(&q1, &a);
				Print_SQueue(&q1);
				SOutQueue(&q1, &a);
				Print_SQueue(&q1);
				SOutQueue(&q1, &a);
				Print_SQueue(&q1);
				SOutQueue(&q1, &a);
				Print_SQueue(&q1);
				break;
			default:
				printf("ѡ�����������ѡ��\n");
			}
		}
		system("pause:");
		return 0;
	}
		