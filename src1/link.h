#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���͵�����
typedef struct Node
{
	int id; //������
	struct Node *next; //ָ����
}Node;


//ѭ�������ڵ㣬����������Ϊ�������˳�ѭ��
//β�巨, ����ֵΪ�ṹ��ָ������
Node * CreateLinkTail();

//ͷ�巨, ����ֵΪ�ṹ��ָ������
Node * CreateLinkHead();

void PrintNode(Node *head);

//��ĳ������ǰ������½ڵ㣬�������������ڣ�����β�������½ڵ�
void InsertNode(Node * head, int x, int y);

//ɾ����һ���ڵ�ֵΪx�Ľ��
void DelNode(Node * head, int x);

void DestroyLink(Node *head);

