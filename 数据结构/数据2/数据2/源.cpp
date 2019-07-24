#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//（1）定义链式栈
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}LinkStackNode, *LinkStack;

//(2)链式存储实现栈的初始化
void InitStack_Link(LinkStack* top)
{
	LinkStackNode *tmp = (LinkStackNode *)malloc(sizeof(LinkStackNode));//头结点
	if (tmp == NULL)
		return;
	tmp->data = 0;
	tmp->next = NULL;
	*top = tmp;
}

//(3)链式存储实现栈的入栈
void Push_Link(LinkStack top, DataType x)
{
	LinkStackNode* tmp;
	tmp = (LinkStackNode*)malloc(sizeof(LinkStackNode));//申请空间
	if (tmp == NULL)
		return;
	tmp->data = x;
	tmp->next = top->next; 
	//修改栈顶指针
	top->next = tmp;
}

//(4)链式存储实现栈的出栈
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
//(5)打印链式栈
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
//（1）定义顺序栈
typedef struct
{
	DataType arr[Size];
	int top;
}SeqStack;

//(2)顺序存储实现栈的初始化
void InitStack_Seq(SeqStack* s)
{
	s->top = -1;
}

//(3)顺序存储实现栈的入栈
int Push_Seq(SeqStack* s, DataType x)
{
	//栈满了
	if (s->top == Size - 1)
		return 0;
	s->top++;
	s->arr[s->top] = x;
	return 1;
}

//(4)顺序存储实现栈的出栈
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
//(5)打印顺序栈
void Print_Seq_Stack(SeqStack s)
{
	int i = 0;
	for (i = 0; i <= s.top; i++)
	{
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
//（3）定义链队列
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
//(2)链式存储实现队列的初始化
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

//(3)链式存储实现队列的入队
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

//(4)链式存储实现队列的出队
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
//(5)打印链队列
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
//(1)定义顺序队列
	typedef struct
	{
		DataType arr[Size];
		int front;
		int rear;
	}SeqQueue;

	//(2)顺序存储实现循环队列的初始化
	void SInitQueue(SeqQueue* q)
	{
		q->front = q->rear = 0;
	}

	//(3)顺序存储实现循环队列的入队
	int InQue(SeqQueue* q, DataType data)
	{
		//队列满
		if ((q->rear + 1) % Size == q->front)
			return 0;

		q->arr[q->rear] = data;
		q->rear = (q->rear + 1) % Size;
		return 1;
	}

	//(4)顺序存储实现循环队列的出队
	int SOutQueue(SeqQueue* q, DataType* x)
	{
		if (q->front == q->rear)//队列空
			return 0;
		*x = q->arr[q->front];
		q->front = (q->front + 1) % Size;
		return 1;
	}
	//(5)打印顺序队列
	void Print_SQueue(SeqQueue* q)
	{
		int i = q->front;
		if (q->front == q->rear)
		{
			printf("此时队列是空的\n");
		}
		while (i != q->rear)
		{
			printf("%d ", q->arr[i]);
			i++;
			i = i % Size;
		}
		printf("\n");
	}
	//1.链栈入栈
	void chosestackin1()
	{
		DataType a;
		int flag = 1;
		LinkStackNode  *head = NULL;
		InitStack_Link(&head);
		while (flag)
		{
			int c;
			printf("请输入你的数字，输入111结束！\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[该程序结束!!!]\n");
			}
			else
			{
				Push_Link(head, c);
				printf("链栈入栈成功\n");
				Print(head);
			}
		}
	}
	//2.顺序栈入栈
	void chosestackin2()
	{

		int flag = 1;
		SeqStack head;
		InitStack_Seq(&head);
		while (flag)
		{
			int c;
			printf("请输入你的数字，输入111结束！\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[该程序结束!!!]\n");
			}
			else
			{
				Push_Seq(&head,c);
				printf("顺序栈入栈成功:\n");
				Print_Seq_Stack(head);
			}
		}
	}
	//3.链对列入队
	void chosestackin3()
	{

		int flag = 1;
		LinkQueue head;
		InitQue(&head);
		while (flag)
		{
			int c;
			printf("请输入你的数字，输入111结束！\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[该程序结束!!!]\n");
			}
			else
			{
				EnterQueue(&head, c);
				printf("链对列入队成功:\n");
				Print_Link_Queue(&head);
			}
		}
	}
	//4.顺序对列入队
	void chosestackin4()
	{

		int flag = 1;
		SeqQueue head;
		SInitQueue(&head);
		while (flag)
		{
			int c;
			printf("请输入你的数字，输入111结束！\nc=");
			scanf("%d", &c);
			if (c == 111)
			{
				flag = 0;
				printf("[该程序结束!!!]\n");
			}
			else
			{
				InQue(&head, c);
				printf("链对列入队成功:\n");
				Print_SQueue(&head);
			}
		}
	}
	
	void menu()
	{
		printf("\t\t\t\t\t*******************主菜单********************\n");
		printf("\t\t\t\t\t****************输入1链栈入栈****************\n");
		printf("\t\t\t\t\t****************输入2链栈出栈****************\n");
		printf("\t\t\t\t\t****************输入3顺序栈入栈**************\n");
		printf("\t\t\t\t\t****************输入4顺序栈出栈**************\n");
		printf("\t\t\t\t\t****************输入5链队入队****************\n");
		printf("\t\t\t\t\t****************输入6链队出队****************\n");
		printf("\t\t\t\t\t****************输入7顺序队列入队************\n");
		printf("\t\t\t\t\t****************输入8顺序队列出队************\n");
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
			printf("请输入你的选择：");
			scanf("%d", &n);
			switch (n)
			{
			case 1:
				printf("--链栈压栈过程--\n");
				chosestackin1();
				break;
			case 2:
				printf("--链栈出栈过程--\n");
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
				printf("顺序栈压栈过程：\n");
				chosestackin2();
				break;
			case 4:
				printf("顺序栈出栈过程：\n");
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
				printf("链队列压栈过程：\n");
				chosestackin3();
				break;
			case 6:
				printf("链队列出栈过程：\n");
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
				printf("循环队列压栈过程：\n");
				chosestackin4();
				break;
			case 8:
				printf("循环队列出栈过程：\n");
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
				printf("选择错误，请重新选择！\n");
			}
		}
		system("pause:");
		return 0;
	}
		