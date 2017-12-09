#include "LinkList.h"
#include <stdio.h>

typedef struct _Person
{
	char name[20];
	int age;
}Person;

int compare(void *d1, void *d2)
{
	Person *p1 = (Person *)d1;
	Person *p2 = (Person *)d2;
	return strcmp(p1->name, p2->name) == 0 || p1->age == p2->age;
}

void print(void *data)
{
	Person *p = (Person *)data;
	printf("%s,%d\n", p->name, p->age);
}

int main()
{
	Person p1 = { "a",18 };
	Person p2 = { "b", 19 };
	Person p3 = { "c", 20 };
	Person p4 = { "d", 21 };
	Person p5 = { "e",22 };

	void *list = Init_LinkList();

	//��λ�ò���
	PushByPos_LinkList(list, 0, &p1); // 18
	//ͷ��
	PushFront_LinkList(list, &p2); //19,18
	//β��
	PushBack_LinkList(list, &p3); //19,18,20
	//ֵǰ����
	PushByVal_LinkList(list, &p1, &p4, compare); //19,21,18,20
	//��λ�ò���p5
	PushByPos_LinkList(list, 2, &p5); //19,21,22,18,20
	//������ӡ
	Foreach_LinkList(list, print);

	printf("-------------------------------\n");

	//��λ��ɾ��
	RemoveByPos_LinkList(list, 2); //19,21,18,20
 //������ӡ
	Foreach_LinkList(list, print);
	printf("-------------------------------\n");

	//��ֵɾ��
	RemoveByVal_LinkList(list, &p1, compare); //19,21,20
											  //������ӡ
	Foreach_LinkList(list, print);
	printf("-------------------------------\n");

	//��λ�û�ȡ
	Person *p = (Person *)GetByPos_LinkList(list, 1);
	printf("%s,%d\n", p->name, p->age); //21

	//ͷɾ��
	RemoveFront_LinkList(list);
	Foreach_LinkList(list, print); //21,20
	printf("-------------------------------\n");
	//βɾ��
	RemoveBack_LinkList(list);
	Foreach_LinkList(list, print); //21
	printf("-------------------------------\n");
	//����
	Destroy_LinkList(list);
}