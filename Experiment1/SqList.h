#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
#define MAX_SQLIST_NUM 10//�����ͬʱ�����ı����Ŀ

typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct//���Ա�ṹ
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
typedef struct//�����������Ա�ĺ����Ա�ָ������Ľṹ
{
  SqList* SqListArray[MAX_SQLIST_NUM];
  int length;
}SqListsOptioner;

SqListsOptioner Lists;//ȫ�ֱ��������ڲ���

status InitiaList(SqList *L);
status ListLength(SqList *L);
status ListInsert(SqList *L,int i,ElemType e);
status ListDelete(SqList *L,int i,ElemType *e);
status DestroyList(SqList *L);
status CleaList(SqList *L);
status ListEmpty(SqList *L);
status GetElem(SqList *L,int i,ElemType *e);
status LocateElem(SqList *L,ElemType e);
status PriorElem(SqList *L,ElemType cur_e,ElemType *pre_e);
status NextElem(SqList *L,ElemType cur_e,ElemType *next_e);
status ListTraverse(SqList *L);//����Ϊʵ��Ҫ���е�12������
SqList *ChooseList(int *OpListNum);//������������ѡ�����Ա�
status PreLoadingFiles(void);//��Ԥ����ļ�
status OpenFiles(void);//ͨ�������ļ����ķ�ʽ�����ļ�
status SaveData(void);//�����ļ�
void menu(void);//��ӡ�˵�

#endif // SQLIST_H_INCLUDED

