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

//初始化
void * Init_LinkList();
//按位置插入
void PushByPos_LinkList(void *_list, int pos, void *data);
//头部插入
void PushFront_LinkList(void *_list, void *data);
//尾部插入
void PushBack_LinkList(void *_list, void *data);
//按值前插入
void PushByVal_LinkList(void *_list, void *oldval, void *newval, int(*compare)(void *, void *));
//按位置删除
void RemoveByPos_LinkList(void *_list, int pos);
//头部删除
void RemoveFront_LinkList(void *_list);
//尾部删除
void RemoveBack_LinkList(void *_list);
//按值删除
void RemoveByVal_LinkList(void *_list, void *data, int(*compare)(void *, void *));
//遍历
void Foreach_LinkList(void *_list, void(*print)(void *));
//按位置获取值
void * GetByPos_LinkList(void *_list, int pos);
//销毁
void Destroy_LinkList(void *_list);
