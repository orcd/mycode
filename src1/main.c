#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "link.h"

int main(void)
{
	Node * head = NULL;
	head = CreateLinkTail(); //β�巨��������
	//head = CreateLinkHead(); //ͷ�巨��������
	PrintNode(head); //������ӡ���еĽ��

	//��ĳ������ǰ������½ڵ㣬�������������ڣ�����β�������½ڵ�
	InsertNode(head, 5, 4); //��5��ǰ�����4
	PrintNode(head); //������ӡ���еĽ��

	DelNode(head, 5); //ɾ����һ���ڵ�ֵΪ5�Ľ��
	PrintNode(head); //������ӡ���еĽ��

	DestroyLink(head); //�ͷ����еĽ��
	head = NULL;

	printf("\n");
	system("pause");
	return 0;
}
