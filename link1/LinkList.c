#include "LinkList.h"

//��ʼ��
void * Init_LinkList()
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;
	return list;
}
//��λ�ò���
void PushByPos_LinkList(void *_list, int pos, void *data)
{
	if (NULL == _list)
		return;
	if (NULL == data)
		return;
	LinkList *list = (LinkList *)_list;
	if (pos < 0 || pos > list->size)
		pos = list->size;
	LinkNode *p = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		p = p->next;
	}

	LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = p->next;
	p->next = newNode;

	++list->size;
}
//ͷ������
void PushFront_LinkList(void *_list, void *data)
{
	return PushByPos_LinkList(_list, 0, data);
}
//β������
void PushBack_LinkList(void *_list, void *data)
{
	LinkList *list = (LinkList *)_list;
	return PushByPos_LinkList(list, list->size, data);
}
//��ֵǰ����
void PushByVal_LinkList(void *_list, void *oldval, void *newval, int(*compare)(void *, void *))
{
	if (NULL == _list)
		return;
	if (NULL == oldval)
		return;
	if (NULL == newval)
		return;
	if (NULL == compare)
		return;
	LinkList *list = (LinkList *)_list;
	LinkNode *p = &list->header;
	while (p->next)
	{
		if (compare(p->next->data, oldval))
		{
			LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
			newNode->data = newval;
			newNode->next = NULL;

			newNode->next = p->next;
			p->next = newNode;
			++list->size;
			break;
		}
		p = p->next;
	}
}
//��λ��ɾ��
void RemoveByPos_LinkList(void *_list, int pos)
{
	if (NULL == _list)
		return;
	LinkList *list = (LinkList *)_list;
	if (list->size == 0)
		return;
	if (pos < 0 || pos >= list->size)
		return;
	LinkNode *p = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		p = p->next;
	}
	LinkNode *pDel = p->next;
	p->next = pDel->next;
	free(pDel);
	--list->size;
}
//ͷ��ɾ��
void RemoveFront_LinkList(void *_list)
{
	return RemoveByPos_LinkList(_list, 0);
}
//β��ɾ��
void RemoveBack_LinkList(void *_list)
{
	LinkList *list = (LinkList *)_list;
	return RemoveByPos_LinkList(_list, list->size - 1);
}
//��ֵɾ��
void RemoveByVal_LinkList(void *_list, void *data, int(*compare)(void *, void *))
{
	if (NULL == _list)
		return;
	if (NULL == data)
		return;
	if (NULL == compare)
		return;
	LinkList *list = (LinkList *)_list;
	if (list->size == 0)
		return;
	LinkNode *p = &list->header;
	while (p->next)
	{
		if (compare(p->next->data, data))
		{
			LinkNode *pDel = p->next;
			p->next = pDel->next;
			free(pDel);
			--list->size;
			break;
		}
		p = p->next;
	}
}
//����
void Foreach_LinkList(void *_list, void(*print)(void *))
{
	if (NULL == _list)
		return;
	if (NULL == print)
		return;
	LinkList *list = (LinkList *)_list;
	LinkNode *p = list->header.next;
	while (p)
	{
		print(p->data);
		p = p->next;
	}
}
//��λ�û�ȡֵ
void * GetByPos_LinkList(void *_list, int pos)
{
	if (NULL == _list)
		return NULL;
	LinkList *list = (LinkList *)_list;
	if (list->size == 0)
		return NULL;
	if (pos < 0 || pos >= list->size)
		return NULL;
	LinkNode *p = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		p = p->next;
	}
	return p->next->data;
}
//����
void Destroy_LinkList(void *_list)
{
	if (NULL == _list)
		return;
	LinkList *list = (LinkList *)_list;
	LinkNode *pDel = list->header.next;
	while (pDel)
	{
		LinkNode *p = pDel->next;
		free(pDel);
		pDel = p;
	}
	free(list);
}