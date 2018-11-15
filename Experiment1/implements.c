
#include "SqList.h"

status InitiaList(SqList *L)//构造新的线性表
{
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

status ListLength(SqList *L)//求表长,初始条件是线性表已存在；操作结果是返回L中数据元素的个数。
{
    return L->length;
}
status ListInsert(SqList *L,int i,ElemType e)//在顺序线性表L中第i个位置之前插入新元素e
{
    //i的合法值为 1<=i<=ListLength(*L)+1
    if(i<1||i>L->length+1) return ERROR;
    ElemType *q,*p;
    if(L->length>=L->listsize)
    {
        ElemType *newbase;
        newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;
    }
    q=&(L->elem[i-1]);//此时q为插入位置
    for(p=&(L->elem[L->length-1]); p>=q; --p)
        *(p+1)=*p;
    *q=e;
    ++L->length;
    return OK;
}

status ListDelete(SqList *L,int i,ElemType *e)//删除元素,初始条件是线性表L已存在且非空,删除L的第i个数据元素，用e返回其值。
{
    //i的合法值为1≤i≤ListLength(L)
    if(i<1||(i>L->length)) return ERROR;
    ElemType *p,*q;
    p=&(L->elem[i-1]);
    *e=*p;
    q=L->elem+L->length-1;
    for(++p; p<=q; ++p)
        *(p-1)=*p;
    --L->length;
    return OK;
}

status DestroyList(SqList *L)//销毁表：初始条件是线性表L已存在；操作结果是销毁线性表L。
{
    free(L->elem);
    free(L);
    return OK;
}
status CleaList(SqList *L)//清空表：初始条件是线性表L已存在；操作结果是若L为空表则返回TRUE,否则返回FALSE。
{
    L->length=0;
    return TRUE;
}
status ListEmpty(SqList *L)//判定空表：初始条件是线性表L已存在；操作结果是若L为空表则返回TRUE,否则返回FALSE。
{
    if(L->length==0) return TRUE;
    else return FALSE;
}
status GetElem(SqList *L,int i,ElemType *e)//获得元素：初始条件是线性表已存在，操作结果是用e返回L中第i个数据元素的值。
{
    //i的合法值范围是1≤i≤ListLength(L)
    *e = L->elem[i-1];
    return OK;
}
status LocateElem(SqList *L,ElemType e)//查找元素：返回第一个值为e的位序，没有则返回0
{
    int i;
    for(i=0; i<=L->length-1; i++)
        if(e == L->elem[i]) return i+1;
    return 0;
}
status PriorElem(SqList *L,ElemType cur_e,ElemType *pre_e)//获得前驱，并用pre_e返回
{
    //cur_e是L的数据元素，且不是第一个,否则操作失败，pre_e无定义
    int i;
    for(i=1; i<=L->length-1; i++)
        if(cur_e==L->elem[i])
        {
            *pre_e = L->elem[i-1];
            return OK;
        }
    return FALSE;
}
status NextElem(SqList *L,ElemType cur_e,ElemType *next_e)//获得后继，并用next_e返回
{
    //cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义。
    int i;
    for(i=0; i<L->length-1; i++)
        if(cur_e==L->elem[i])
        {
            *next_e=L->elem[i+1];
            return OK;
        }
    return FALSE;
}
status ListTraverse(SqList *L)//遍历表：初始条件是线性表L已存在；操作结果是依次对L的每个数据元素调用函数visit()。
{
    int i;
    printf("\n---------------------所有元素 -----------------------\n");
    for ( i = 0; i < L->length; i++)
        printf("%d ", L->elem[i]);
    printf("\n---------------------- 结束------------------------\n");
    return L->length;
}

SqList* ChooseList(int *OpListNum)//选择要操作的线性表
{
    printf("\t请输入要选择的线性表编号(1-%d)：",Lists.length);
    int choice;
    scanf("%d",&choice);
    getchar();
    if(choice<=0||choice>Lists.length)
    {
        printf("该线性表不存在！\n");
        return NULL;
    }
    else
    {
        *OpListNum=choice;
        return Lists.SqListArray[*OpListNum-1];
    }
}
status PreLoadFiles(void)//打开预存的两个文件并将该文件内容读取到线性表中
{
    FILE *pFile1,*pFile2;
    SqListsOptioner *SqLists=&Lists;
    SqList *pSqList;
    if((pFile1=fopen("SqlistTest1.txt","r+"))==NULL)//读取文件1
    {
        printf("\t文件读取失败！\n");
        return 0;
    }
    else
    {
        int i=1,p;
        printf("\t文件1打开成功！");
        SqLists->SqListArray[SqLists->length] = (SqList *)malloc(sizeof(SqList*));
        pSqList=SqLists->SqListArray[SqLists->length];
        InitiaList(pSqList);
        SqLists->length++;
        while(fscanf(pFile1,"%d",&p)!=EOF)
        {
            if(ListInsert(pSqList,i,p)==OK)i++;
            else printf("读取失败！");
        }
        printf("信息读取完成！\n");
    }
    if((pFile2=fopen("SqlistTest2.txt","r+"))==NULL)//读取文件2
    {
        printf("\t文件读取失败！\n");
        return 0;
    }
    else
    {
        int i=1,p;
        printf("\t文件2打开成功！");
        SqLists->SqListArray[SqLists->length] = (SqList *)malloc(sizeof(SqList*));
        pSqList=SqLists->SqListArray[SqLists->length];
        InitiaList(pSqList);
        SqLists->length++;
        while(fscanf(pFile2,"%d",&p)!=EOF)
        {
            if(ListInsert(pSqList,i,p)==OK)i++;
            else printf("读取失败！");
        }
        printf("信息读取完成！\n");
        fclose(pFile2);
    }
    return OK;
}

status OpenFiles(void)//允许用户通过输入文件名来打开文件
{
    SqListsOptioner *SqLists=&Lists;
    SqList *pSqList;
    FILE *pFile;
    char FileName[40];
    int i=1,p;
    printf("\t请输入要打开文件的文件名:\n\t");
    scanf("%s",FileName);
    getchar();
    if((pFile=fopen(FileName,"r+"))==NULL)
    {
        printf("****文件打开失败！\n");
        return FALSE;
    }
    else
    {
        SqLists->SqListArray[SqLists->length] = (SqList *)malloc(sizeof(SqList*));
        pSqList=SqLists->SqListArray[SqLists->length];
        InitiaList(pSqList);
        SqLists->length++;
        while(fscanf(pFile,"%d",&p)!=EOF)
        {
            if(ListInsert(pSqList,i,p)==OK)i++;
            else
            {
                printf("****读取失败！");
                return FALSE;
            }
        }
        printf("\t信息读取完成！\n");
        printf("\t当前线性表数%d\n",SqLists->length);
    }
    return OK;
}
status SaveData(void)//将内存中的线性表数据1,2写入到文件1，2中
{
    FILE *pFILE;
    SqListsOptioner *SqLists = &Lists;
    SqList *pList;
    int i,rest,Saving_num=3;
    if((pFILE = fopen("SqlistTest1.txt", "w+"))==NULL) return FALSE;
    pList=SqLists->SqListArray[0];
    for(i=0; i<pList->length; i++)
        fprintf(pFILE," %d",pList->elem[i]);
    fclose(pFILE) ;
    if((pFILE= fopen("SqlistTest2.txt", "w+"))==NULL) return FALSE;
    pList=SqLists->SqListArray[1];
    for(i=0; i<pList->length; i++)
        fprintf(pFILE," %d",pList->elem[i]);
    fclose(pFILE) ;
    for(rest=(SqLists->length)-2; rest>0; rest--)//检查是否有新建的线性表
    {
        char FileName[40];
        printf("\t还有%d个新建的线性表待保存！请输入线性表%d的文件名：\n",rest,Saving_num);
        scanf("%s",FileName);
        getchar();
        if((pFILE=fopen(FileName,"w+"))==NULL) return FALSE;//保存新建的线性表
        pList=SqLists->SqListArray[Saving_num-1];
        for(i=0; i<pList->length; i++)
            fprintf(pFILE," %d",pList->elem[i]);
        fclose(pFILE);
        Saving_num++;
    }
    return OK;
}


void menu(void) //打印菜单
{
    printf("\n\n");
    printf("      Menu for Linear Table On Sequence Structure \n");
    printf("------------------------------------------------------\n");
    printf("    	  1. InitiaList       7. LocatElem\n");
    printf("    	  2. DestroyList     8. PriorElem\n");
    printf("    	  3. ClearList       9. NextElem \n");
    printf("    	  4. ListEmpty      10. ListInsert\n");
    printf("    	  5. ListLength     11. ListDelete\n");
    printf("    	  6. GetElem        12. ListTrabverse\n");
    printf("    	  0. Exit           13.ChooseList \n");
    printf("          14.SaveData       15.OpenFiles \n");
    printf("------------------------------------------------------\n");
    printf("\n\t\t请输入你的选择:\n");

}
