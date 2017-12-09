#pragma once
#include <stdlib.h>

typedef struct _LinkNode
{
	void *data;
	struct _LinkNode *next;
}LinkNode;

typedef struct _LinkList
{
	LinkNode header;
	int size;
}LinkList;

//��ʼ��
void * Init_LinkList();
//��λ�ò���
void PushByPos_LinkList(void *_list, int pos, void *data);
//ͷ������
void PushFront_LinkList(void *_list, void *data);
//β������
void PushBack_LinkList(void *_list, void *data);
//��ֵǰ����
void PushByVal_LinkList(void *_list, void *oldval, void *newval, int(*compare)(void *, void *));
//��λ��ɾ��
void RemoveByPos_LinkList(void *_list, int pos);
//ͷ��ɾ��
void RemoveFront_LinkList(void *_list);
//β��ɾ��
void RemoveBack_LinkList(void *_list);
//��ֵɾ��
void RemoveByVal_LinkList(void *_list, void *data, int(*compare)(void *, void *));
//����
void Foreach_LinkList(void *_list, void(*print)(void *));
//��λ�û�ȡֵ
void * GetByPos_LinkList(void *_list, int pos);
//����
void Destroy_LinkList(void *_list);
