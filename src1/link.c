#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "link.h"

//ѭ�������ڵ㣬����������Ϊ�������˳�ѭ��
//β�巨, ����ֵΪ�ṹ��ָ������
Node * CreateLinkTail()
{
	Node *head;
	Node *pnew;
	Node *ptail;

	//�ȴ���ͷ���
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL; //ֻ��һ���ڵ�ʱ��ͷ���Ҳ��β���
	ptail = head; //����β����λ��

	int data;
	while (1)
	{
		printf("������id: ");
		scanf("%d", &data);
		if (data < 0)
		{
			break;
		}

		//�½����
		pnew = (Node *)malloc(sizeof(Node));
		//��Ա������ֵ
		pnew->id = data;

		//��㽨����ϵ
		ptail->next = pnew; //β������һ�����ʱ�½��
		pnew->next = NULL; //�½����Ϊβ���
		ptail = pnew; //����β����λ��
	}
	return head;
}

//ͷ�巨, ����ֵΪ�ṹ��ָ������
Node * CreateLinkHead()
{
	Node *head;
	Node *pnew;

	//�ȴ���ͷ���
	head = (Node *)malloc(sizeof(Node));
	head->next = NULL; //ֻ��һ���ڵ�ʱ��ͷ���Ҳ��β���

	int data;
	while (1)
	{
		printf("������id: ");
		scanf("%d", &data);
		if (data < 0)
		{
			break;
		}

		//�½����
		pnew = (Node *)malloc(sizeof(Node));
		//��Ա������ֵ
		pnew->id = data;

		pnew->next = head->next; //�½�����һ�����Ϊͷ������һ�����
		head->next = pnew; //ͷ������һ�����Ϊ�½��
	}

	return head;
}

void PrintNode(Node *head)
{
	Node * tmp = head->next;
	printf("head -> ");
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->id);
		tmp = tmp->next; //��������ƶ�
	}
	printf("NULL\n");
}

//��ĳ������ǰ������½ڵ㣬�������������ڣ�����β�������½ڵ�
void InsertNode(Node * head, int x, int y)
{
	if (head == NULL)
	{
		printf("head == NULL\n");
		return;
	}

	Node *pre;
	Node *pcur;
	Node *pnew;

	//2�����һ����㣬pre��ǰ
	pre = head;
	pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id == x)
		{
			break;
		}
		//�����������ƶ�һ��λ��
		pre = pre->next;
		pcur = pcur->next;
	}

	//�½����
	pnew = (Node *)malloc(sizeof(Node));
	pnew->id = y;

	//��㽨����ϵ
	pre->next = pnew;
	pnew->next = pcur;
}

//ɾ����һ���ڵ�ֵΪx�Ľ��
void DelNode(Node * head, int x)
{
	if (head == NULL)
	{
		printf("head == NULL\n");
		return;
	}

	Node *pre;
	Node *pcur;
	int flag = 0; //0û���ҵ��� 1�ҵ�

	//2�����һ����㣬pre��ǰ
	pre = head;
	pcur = head->next;

	while (pcur != NULL)
	{
		if (pcur->id == x)
		{
			pre->next = pcur->next;
			free(pcur);
			flag = 1;

			break;
		}
		//�����������ƶ�һ��λ��
		pre = pre->next;
		pcur = pcur->next;
	}

	if (0 == flag)
	{//û������ڵ�
		printf("û��ֵΪ%d�Ľ��\n", x);
	}
}

void DestroyLink(Node *head)
{
	Node *tmp = head;
	Node *del = head;

	while (tmp != NULL)
	{
		//�ͷ�ǰ�ȱ�����һ�����
		tmp = tmp->next;
		free(del); //�ͷŵ�ǰ�ڵ㣬tmp����һ�����
		del = tmp; //������һ����Ҫ�ͷŵĽ��
	}
}

