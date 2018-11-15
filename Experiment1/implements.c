
#include "SqList.h"

status InitiaList(SqList *L)//�����µ����Ա�
{
    L->elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

status ListLength(SqList *L)//���,��ʼ���������Ա��Ѵ��ڣ���������Ƿ���L������Ԫ�صĸ�����
{
    return L->length;
}
status ListInsert(SqList *L,int i,ElemType e)//��˳�����Ա�L�е�i��λ��֮ǰ������Ԫ��e
{
    //i�ĺϷ�ֵΪ 1<=i<=ListLength(*L)+1
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
    q=&(L->elem[i-1]);//��ʱqΪ����λ��
    for(p=&(L->elem[L->length-1]); p>=q; --p)
        *(p+1)=*p;
    *q=e;
    ++L->length;
    return OK;
}

status ListDelete(SqList *L,int i,ElemType *e)//ɾ��Ԫ��,��ʼ���������Ա�L�Ѵ����ҷǿ�,ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��
{
    //i�ĺϷ�ֵΪ1��i��ListLength(L)
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

status DestroyList(SqList *L)//���ٱ���ʼ���������Ա�L�Ѵ��ڣ�����������������Ա�L��
{
    free(L->elem);
    free(L);
    return OK;
}
status CleaList(SqList *L)//��ձ���ʼ���������Ա�L�Ѵ��ڣ������������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
{
    L->length=0;
    return TRUE;
}
status ListEmpty(SqList *L)//�ж��ձ���ʼ���������Ա�L�Ѵ��ڣ������������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
{
    if(L->length==0) return TRUE;
    else return FALSE;
}
status GetElem(SqList *L,int i,ElemType *e)//���Ԫ�أ���ʼ���������Ա��Ѵ��ڣ������������e����L�е�i������Ԫ�ص�ֵ��
{
    //i�ĺϷ�ֵ��Χ��1��i��ListLength(L)
    *e = L->elem[i-1];
    return OK;
}
status LocateElem(SqList *L,ElemType e)//����Ԫ�أ����ص�һ��ֵΪe��λ��û���򷵻�0
{
    int i;
    for(i=0; i<=L->length-1; i++)
        if(e == L->elem[i]) return i+1;
    return 0;
}
status PriorElem(SqList *L,ElemType cur_e,ElemType *pre_e)//���ǰ��������pre_e����
{
    //cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��,�������ʧ�ܣ�pre_e�޶���
    int i;
    for(i=1; i<=L->length-1; i++)
        if(cur_e==L->elem[i])
        {
            *pre_e = L->elem[i-1];
            return OK;
        }
    return FALSE;
}
status NextElem(SqList *L,ElemType cur_e,ElemType *next_e)//��ú�̣�����next_e����
{
    //cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶��塣
    int i;
    for(i=0; i<L->length-1; i++)
        if(cur_e==L->elem[i])
        {
            *next_e=L->elem[i+1];
            return OK;
        }
    return FALSE;
}
status ListTraverse(SqList *L)//��������ʼ���������Ա�L�Ѵ��ڣ�������������ζ�L��ÿ������Ԫ�ص��ú���visit()��
{
    int i;
    printf("\n---------------------����Ԫ�� -----------------------\n");
    for ( i = 0; i < L->length; i++)
        printf("%d ", L->elem[i]);
    printf("\n---------------------- ����------------------------\n");
    return L->length;
}

SqList* ChooseList(int *OpListNum)//ѡ��Ҫ���������Ա�
{
    printf("\t������Ҫѡ������Ա���(1-%d)��",Lists.length);
    int choice;
    scanf("%d",&choice);
    getchar();
    if(choice<=0||choice>Lists.length)
    {
        printf("�����Ա����ڣ�\n");
        return NULL;
    }
    else
    {
        *OpListNum=choice;
        return Lists.SqListArray[*OpListNum-1];
    }
}
status PreLoadFiles(void)//��Ԥ��������ļ��������ļ����ݶ�ȡ�����Ա���
{
    FILE *pFile1,*pFile2;
    SqListsOptioner *SqLists=&Lists;
    SqList *pSqList;
    if((pFile1=fopen("SqlistTest1.txt","r+"))==NULL)//��ȡ�ļ�1
    {
        printf("\t�ļ���ȡʧ�ܣ�\n");
        return 0;
    }
    else
    {
        int i=1,p;
        printf("\t�ļ�1�򿪳ɹ���");
        SqLists->SqListArray[SqLists->length] = (SqList *)malloc(sizeof(SqList*));
        pSqList=SqLists->SqListArray[SqLists->length];
        InitiaList(pSqList);
        SqLists->length++;
        while(fscanf(pFile1,"%d",&p)!=EOF)
        {
            if(ListInsert(pSqList,i,p)==OK)i++;
            else printf("��ȡʧ�ܣ�");
        }
        printf("��Ϣ��ȡ��ɣ�\n");
    }
    if((pFile2=fopen("SqlistTest2.txt","r+"))==NULL)//��ȡ�ļ�2
    {
        printf("\t�ļ���ȡʧ�ܣ�\n");
        return 0;
    }
    else
    {
        int i=1,p;
        printf("\t�ļ�2�򿪳ɹ���");
        SqLists->SqListArray[SqLists->length] = (SqList *)malloc(sizeof(SqList*));
        pSqList=SqLists->SqListArray[SqLists->length];
        InitiaList(pSqList);
        SqLists->length++;
        while(fscanf(pFile2,"%d",&p)!=EOF)
        {
            if(ListInsert(pSqList,i,p)==OK)i++;
            else printf("��ȡʧ�ܣ�");
        }
        printf("��Ϣ��ȡ��ɣ�\n");
        fclose(pFile2);
    }
    return OK;
}

status OpenFiles(void)//�����û�ͨ�������ļ��������ļ�
{
    SqListsOptioner *SqLists=&Lists;
    SqList *pSqList;
    FILE *pFile;
    char FileName[40];
    int i=1,p;
    printf("\t������Ҫ���ļ����ļ���:\n\t");
    scanf("%s",FileName);
    getchar();
    if((pFile=fopen(FileName,"r+"))==NULL)
    {
        printf("****�ļ���ʧ�ܣ�\n");
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
                printf("****��ȡʧ�ܣ�");
                return FALSE;
            }
        }
        printf("\t��Ϣ��ȡ��ɣ�\n");
        printf("\t��ǰ���Ա���%d\n",SqLists->length);
    }
    return OK;
}
status SaveData(void)//���ڴ��е����Ա�����1,2д�뵽�ļ�1��2��
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
    for(rest=(SqLists->length)-2; rest>0; rest--)//����Ƿ����½������Ա�
    {
        char FileName[40];
        printf("\t����%d���½������Ա�����棡���������Ա�%d���ļ�����\n",rest,Saving_num);
        scanf("%s",FileName);
        getchar();
        if((pFILE=fopen(FileName,"w+"))==NULL) return FALSE;//�����½������Ա�
        pList=SqLists->SqListArray[Saving_num-1];
        for(i=0; i<pList->length; i++)
            fprintf(pFILE," %d",pList->elem[i]);
        fclose(pFILE);
        Saving_num++;
    }
    return OK;
}


void menu(void) //��ӡ�˵�
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
    printf("\n\t\t���������ѡ��:\n");

}
