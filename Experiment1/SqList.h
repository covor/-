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
#define MAX_SQLIST_NUM 10//最多能同时操作的表的数目

typedef int status;
typedef int ElemType;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct//线性表结构
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
typedef struct//用来操作线性表的含线性表指针数组的结构
{
  SqList* SqListArray[MAX_SQLIST_NUM];
  int length;
}SqListsOptioner;

SqListsOptioner Lists;//全局变量，用于操作

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
status ListTraverse(SqList *L);//至此为实验要求中的12个函数
SqList *ChooseList(int *OpListNum);//多表操作中用来选择线性表
status PreLoadingFiles(void);//打开预存的文件
status OpenFiles(void);//通过输入文件名的方式来打开文件
status SaveData(void);//保存文件
void menu(void);//打印菜单

#endif // SQLIST_H_INCLUDED

