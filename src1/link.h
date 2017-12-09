#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//类型的声明
typedef struct Node
{
	int id; //数据域
	struct Node *next; //指针域
}Node;


//循环创建节点，如果输入的数为负数，退出循环
//尾插法, 返回值为结构体指针类型
Node * CreateLinkTail();

//头插法, 返回值为结构体指针类型
Node * CreateLinkHead();

void PrintNode(Node *head);

//在某个数的前面插入新节点，如果这个数不存在，就在尾部插入新节点
void InsertNode(Node * head, int x, int y);

//删除第一个节点值为x的结点
void DelNode(Node * head, int x);

void DestroyLink(Node *head);

