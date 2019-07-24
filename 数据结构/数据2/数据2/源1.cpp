#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define  MAX 100
//��������洢�ṹ
typedef char DataType;
typedef struct Node
{
	DataType data;
	struct Node*LChild;
	struct Node*RChild;
}BiTree;
//ջ�е���������
typedef BiTree*E;
typedef struct
{
	E data[MAX];
	int top;
}SeqStack;
//ջ�����Ͷ��壬˳��ջ
typedef struct
{
	E queue[MAX];
	int front;
	int rear;
}S;
//��ʼ��ջ
SeqStack*initSeqStack()
{
	SeqStack*s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}
//��ջ
int push(SeqStack*e,E x)
{
	if (e->top==MAX-1)
	{
		printf("error");
		return 0;
	}
	e->top++;
	e->data[e->top] = x;
	return 1;
}
//��ջ
void pop(SeqStack*e)
{
	e->top--;
}
int empty(SeqStack*e)
{
	if (e->top==-1)
	{
		return 1;
	}
	else return 0;
}
E top(SeqStack*e)
{ 
	return (e->data[e->top]);
}
//1.��д����, �����ַ�����, �����������Ķ�������
BiTree *createBiTree()
{
	DataType c;
	BiTree *t;
	c = getchar();
	if (c == '0')return NULL;
	else
	{

		t = (BiTree*)malloc(sizeof(BiTree));
		t->data = c;
		t->LChild = createBiTree();
		t->RChild = createBiTree();
		return t;
	}
}
//2.��д����, ʵ�ֶ�����������ݹ�����㷨��
void InOrder(BiTree *root)
{
	if (root)
	{
		
		InOrder(root->LChild);
		printf("%c ", root->data);
		InOrder(root->RChild);

	}
}
//3.��д����, ʵ�ֶ�����������ǵݹ�����㷨
void InOrderUn(BiTree*e)
{
	SeqStack*s;
	s = initSeqStack();
	while (1)
	{
		while (e)
		{
			push(s, e);
		   e=e->LChild;
		}
		if (empty(s))
			break;
		e = top(s);
		pop(s);
		printf("%c ",e->data);
		e = e->RChild;
	}
}
//4.��д����, ��������ʵ�ֶ������Ĳ�α����㷨
void LevelOrder(BiTree*e)
{
	S*p;
	p = (S*)malloc(sizeof(S));
	p->front = 0;
	p -> rear = 0;
	if (e!=NULL)
	{
		p->queue[p->front] = e;
		p->front = p->front + 1;
	}
	while (p->front != p->rear)
	{
		e = p->queue[p->rear];
		p->rear = p->rear + 1;
		printf("%c ", e->data);
		if (e->LChild != NULL)
		{
			p->queue[p->front] = e->LChild;
			p->front = p->front + 1;
		}
		if (e->RChild != NULL)
		{
			p->queue[p->front] = e->RChild;
			p->front = p->front + 1;
		}
	}
}
//5.��д����, ��������ĸ߶�
int high(BiTree*e)
{
	int j, i;
	if (!e)return 0;
	 j = high(e->LChild);
	 i = high(e->RChild);
	return j > i ? j + 1 : i + 1;
}
//6.��д����, ��������Ľ�����
int Node(BiTree *e)
{
	int i, j;
	if (e==NULL)return 0;
	else if (e->LChild == NULL&&e->RChild == NULL)
		return 1;
	else
	{
		i = Node(e->LChild);
		j = Node(e->RChild);
		return i + j + 1;	
	}
}
//7.��д����, ���������Ҷ�Ӹ���
int Leaf(BiTree*e)
{
	int i, j;
	if (e == NULL) return 0;
	else 
	{
		if (e->LChild == NULL&&e->RChild == NULL) return 1;
		i = Leaf(e->LChild);
		j = Leaf(e->RChild);
		return i + j ;		
	}
}

//8.��д����, ����������ÿ��������������������
void Exchange(BiTree*e)
{

	BiTree*t = NULL;
	if (e->LChild == NULL&&e->RChild == NULL) return ;
	else
	{
		t = e->LChild;
		e -> LChild = e->RChild;
		e->RChild = t;
	
	}	
	if (e->LChild) Exchange(e->LChild);
	if (e->RChild) Exchange(e->RChild);
}
void menu()
{
	printf("\n\t\t\t\t\t\t        ���˵�����\n");
	printf("\t\t\t\t\t\t����1 �����������Ķ�������\n");
	printf("\t\t\t\t\t\t����2 ����ݹ����\n");
	printf("\t\t\t\t\t\t����3 ����ǵݹ����\n");
	printf("\t\t\t\t\t\t����4 ����ʵ�ֶ������Ĳ�α���\n");
	printf("\t\t\t\t\t\t����5 �������ĸ߶�\n");
	printf("\t\t\t\t\t\t����6 �������Ľ�����\n");
	printf("\t\t\t\t\t\t����7 ��������Ҷ�Ӹ���\n");
	printf("\t\t\t\t\t\t����8 ����������ÿ��������������������\n");
	printf("\t\t\t\t\t\t����������ʾ��������");
}
int main()
{
	BiTree *b;
	b = NULL;
	int choice = 1;
	int a = 1;
	menu();
	while (choice)
	{
		printf("\n���������ѡ��");
		scanf("%d",&a);
		getchar();
		switch (a)
		{
		case 1:
			printf("���������ǰ�򴴽���������");
			b = createBiTree();
			break;
		case 2:
			printf("����ݹ����:");
			InOrder(b);
			printf("\n");
			break;
		case 3:
			printf("����ǵݹ����:");
			InOrderUn(b);
			printf("\n");
			break;
		case 4:
			printf("����ʵ�ֶ������Ĳ�α���:");
			LevelOrder(b);
			printf("\n");
			break;
		case 5:
			printf("�������߶ȣ�%d", high(b));
			printf("\n");
			break;
		case 6:
			printf("�����������Ϊ��%d", Node(b));
			printf("\n");
			break;
		case 7:
			printf("������Ҷ����Ϊ��%d", Leaf(b));
			printf("\n");
			break;
		case 8:
			printf("����������ÿ����������������������");
			Exchange(b);
			InOrder(b);
			printf("\n");
			break;
		default:printf("\n����������\n");
		}
	}
}