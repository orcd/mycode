#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "link.h"

int main(void)
{
	Node * head = NULL;
	head = CreateLinkTail(); //尾插法创建链表
	//head = CreateLinkHead(); //头插法创建链表
	PrintNode(head); //遍历打印所有的结点

	//在某个数的前面插入新节点，如果这个数不存在，就在尾部插入新节点
	InsertNode(head, 5, 4); //在5的前面插入4
	PrintNode(head); //遍历打印所有的结点

	DelNode(head, 5); //删除第一个节点值为5的结点
	PrintNode(head); //遍历打印所有的结点

	DestroyLink(head); //释放所有的结点
	head = NULL;

	printf("\n");
	system("pause");
	return 0;
}
