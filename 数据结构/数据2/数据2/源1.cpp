#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define  MAX 100
//二叉链表存储结构
typedef char DataType;
typedef struct Node
{
	DataType data;
	struct Node*LChild;
	struct Node*RChild;
}BiTree;
//栈中的数据类型
typedef BiTree*E;
typedef struct
{
	E data[MAX];
	int top;
}SeqStack;
//栈的类型定义，顺序栈
typedef struct
{
	E queue[MAX];
	int front;
	int rear;
}S;
//初始化栈
SeqStack*initSeqStack()
{
	SeqStack*s;
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}
//入栈
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
//出栈
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
//1.编写函数, 输入字符序列, 建立二叉树的二叉链表
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
//2.编写函数, 实现二叉树的中序递归遍历算法。
void InOrder(BiTree *root)
{
	if (root)
	{
		
		InOrder(root->LChild);
		printf("%c ", root->data);
		InOrder(root->RChild);

	}
}
//3.编写函数, 实现二叉树的中序非递归遍历算法
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
//4.编写函数, 借助队列实现二叉树的层次遍历算法
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
//5.编写函数, 求二叉树的高度
int high(BiTree*e)
{
	int j, i;
	if (!e)return 0;
	 j = high(e->LChild);
	 i = high(e->RChild);
	return j > i ? j + 1 : i + 1;
}
//6.编写函数, 求二叉树的结点个数
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
//7.编写函数, 求二叉树的叶子个数
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

//8.编写函数, 交换二叉树每个结点的左子树和右子树
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
	printf("\n\t\t\t\t\t\t        主菜单界面\n");
	printf("\t\t\t\t\t\t输入1 建立二叉树的二叉链表\n");
	printf("\t\t\t\t\t\t输入2 中序递归遍历\n");
	printf("\t\t\t\t\t\t输入3 中序非递归遍历\n");
	printf("\t\t\t\t\t\t输入4 队列实现二叉树的层次遍历\n");
	printf("\t\t\t\t\t\t输入5 二叉树的高度\n");
	printf("\t\t\t\t\t\t输入6 二叉树的结点个数\n");
	printf("\t\t\t\t\t\t输入7 二叉树的叶子个数\n");
	printf("\t\t\t\t\t\t输入8 交换二叉树每个结点的左子树和右子树\n");
	printf("\t\t\t\t\t\t输入其他提示重新输入");
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
		printf("\n请输入你的选择：");
		scanf("%d",&a);
		getchar();
		switch (a)
		{
		case 1:
			printf("请输入结点的前序创建二叉树：");
			b = createBiTree();
			break;
		case 2:
			printf("中序递归遍历:");
			InOrder(b);
			printf("\n");
			break;
		case 3:
			printf("中序非递归遍历:");
			InOrderUn(b);
			printf("\n");
			break;
		case 4:
			printf("队列实现二叉树的层次遍历:");
			LevelOrder(b);
			printf("\n");
			break;
		case 5:
			printf("二叉树高度：%d", high(b));
			printf("\n");
			break;
		case 6:
			printf("二叉树结点数为：%d", Node(b));
			printf("\n");
			break;
		case 7:
			printf("二叉树叶子数为：%d", Leaf(b));
			printf("\n");
			break;
		case 8:
			printf("交换二叉树每个结点的左子树和右子树：");
			Exchange(b);
			InOrder(b);
			printf("\n");
			break;
		default:printf("\n请重新输入\n");
		}
	}
}