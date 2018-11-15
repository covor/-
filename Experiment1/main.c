#include "SqList.h"
void main(void)
{
    SqListsOptioner *SqLists = &Lists;//ͷ�ļ��е�ȫ�ֱ���
    SqList *pList=NULL;//�ڳ����в��������Ա�
    int OpListNum=0;//��ǰ���������Ա�ı��
    int i;
    int options;//�ڲ˵���ѡ���ѡ��
    ElemType elem,*elem2;//�ں��������л��õ���Ԫ��
    if(!PreLoadFiles()) printf("****�������д����ļ��޷��򿪣�\n");
    printf("****��ǰ���Ա�����%d\t��������Ա���%d��\n",SqLists->length,MAX_SQLIST_NUM);
    printf("****��ǰ���������Ա�n=1,2,3....��:");//��ʾ��ǰ�����Ա����������ڲ��������Ա�
    if(!OpListNum) printf("\t��ѡ��Ҫ���������Ա�\n");
    else printf("%d\n",OpListNum);
    if(!SqLists->length) printf("\t����ǰ�޿ɲ��������Ա���\n");
    menu();//�˵�
    scanf("%d",&options);
    getchar();
    while(options)
    {
        system("cls");//ÿ��ѭ��������
        menu();
        printf("****��ǰ���Ա�����%d\t��������Ա���%d��\n",SqLists->length,MAX_SQLIST_NUM);
        printf("****��ǰ���������Ա�n=1,2,3....��:\n");
        switch(options)
        {
        case 0:
            break;
        case 1:
            printf("\n****��ѡ�����  InitiaList\n");
            if(SqLists->length>=MAX_SQLIST_NUM)
            {
                printf("\t���Ա�������Ѵﵽ���ֵ�����ܼ����������Ա�\n");
                getchar();
                break;
            }
            if (!(SqLists->SqListArray[SqLists->length++] =(SqList *)malloc(sizeof(SqList))))
                exit(OVERFLOW);
            if(InitiaList(SqLists->SqListArray[SqLists->length-1])==OK)//�����Ա�ָ�������д�����ָ�벢�Ը�ָ�봴�����Ա�
            {
                printf("\t���Ա�%d�����ɹ���\n",SqLists->length);
                printf("****��ǰ���Ա�����%d\t��������Ա���%d��\n",SqLists->length,MAX_SQLIST_NUM);
            }
            else
            {
                printf("\t���Ա���ʧ�ܣ�\n");
                free(SqLists->SqListArray[SqLists->length-1]);
            }
            break;

        case 2:
            printf("\n****��ѡ�����  DestroyList\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ���ٵ����Ա�\n");
                break;
            }
            else if(DestroyList(pList))
            {
                printf("\t���Ա�%d���ٳɹ���\n",OpListNum);
                if(OpListNum<SqLists->length)
                    for(i=OpListNum; i<SqLists->length-1; i++)
                        SqLists->SqListArray[i-1]=SqLists->SqListArray[i];
                SqLists->length--;
            }
            OpListNum=0;
            break;
        case 3:
            printf("\n****��ѡ�����  ClearList\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ�ÿյ����Ա�\n");
                break;
            }
            if(CleaList(pList))
                printf("\t���Ա�%d�ÿճɹ���\n");
            break;
        case 4:
            printf("\n****��ѡ�����  ListEmpty\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ�пյ����Ա�\n");
                break;
            }
            if(ListEmpty(pList))
                printf("\t���Ա�Ϊ�գ�\n");
            else printf("\t���Ա�Ϊ�գ�\n");
            break;
        case 5:
            printf("\n****��ѡ�����  ListLength \n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ�󳤶ȵ����Ա�\n");
                break;
            }
            printf("\t���Ա�ĳ���Ϊ%d!\n",ListLength(pList));
            break;
        case 6:
            printf("\n****��ѡ�����   GetElem\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ��ȡԪ�ص����Ա�\n");
                break;
            }
            printf("\t����������Ҫ��õڼ���Ԫ�أ�");
            scanf("%d",&i);
            getchar();
            if(i>=1&&i<=pList->length)
            {
                GetElem(pList,i,&elem);
                printf("\t���Ա��еĵ�%d��Ԫ��Ϊ��%d\n",i,elem);
            }
            else printf("\tԪ�ز����ڣ�\n");
            break;

        case 7:
            printf("\n****��ѡ�����  LocatElem\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ��λԪ�ص����Ա�\n");
                break;
            }
            printf("\t������Ҫ���ҵ�Ԫ�أ�");
            scanf("%d",&elem);
            getchar();
            if(i=LocateElem(pList,elem)) printf("\t����ҵ�Ԫ��Ϊ���еĵ�%d��Ԫ��\n",i);
            else printf("\tԪ�ز����ڣ�\n");
            break;

        case 8:
            printf("\n****��ѡ����� PriorElem\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ��ȡԪ��ǰ�������Ա�\n");
                break;
            }
            printf("\t��������Ҫ��ȡ��һ��Ԫ�ص�ǰ����");
            scanf("%d",&i);
            getchar();
            if(PriorElem(pList,i,&elem)) printf("\tԪ��%d��ǰ����%d��\n",i,elem);
            else printf("\tǰ�������ڣ�\n");
            break;
        case 9:
            printf("\n****��ѡ����� NextElem\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ��ȡԪ�غ�̵����Ա�\n");
                break;
            }
            printf("\t��������Ҫ��ȡ��һ��Ԫ�صĺ�̣�");
            scanf("%d",&i);
            getchar();
            if(NextElem(pList,i,&elem)) printf("\tԪ��%d�ĺ����%d��\n",i,elem);
            else printf("\t��̲����ڣ�\n");
            break;
        case 10:
            printf("\n****��ѡ����� ListInsert\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ����Ԫ�ص����Ա�\n");
                break;
            }
            printf("\t��������Ҫ����Ԫ�ص�λ�ú�Ҫ����Ԫ�ص�ֵ��");
            scanf("%d%d",&i,&elem);
            getchar();
            if(ListInsert(pList,i,elem)) printf("\tԪ��%d�ѳɹ����뵽��%d��λ��֮ǰ��\n",elem,i);
            else printf("\t����ʧ�ܣ�\n");
            break;
        case 11:
            printf("\n****��ѡ����� ListDelete\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫɾ��Ԫ�ص����Ա�\n");
                break;
            }
            printf("\t��������Ҫɾ����Ԫ��λ�ã�");
            scanf("%d",&i);
            getchar();
            if(ListDelete(pList,i,&elem)) printf("\t��%d��Ԫ��%d�Ѵ����Ա���ɾ����\n",i,elem);
            else printf("\tԪ��ɾ��ʧ�ܣ�\n");
            break;
        case 12:
            printf("\n****��ѡ�����ListTrabverse\n");
            if(OpListNum<1)
            {
                printf("\t����ѡ��Ҫ���������Ա�\n");
                break;
            }
            if(!ListTraverse(pList)) printf("\t���Ա�Ϊ�ձ�\n");
            break;
        case 13:
            printf("\n****��ѡ�����ChooseList\n");
            pList=ChooseList(&OpListNum);
            printf("\t��ǰ���������Ա�Ϊ���Ա�%d\n",OpListNum);
            break;
        case 14:
            printf("\n****��ѡ�����SaveData\n");
            if(SaveData()) printf("\t�ļ�����ɹ���\n");
            else printf("\t�ļ�����ʧ�ܣ�\n");
            break;
        case 15:
            printf("\n****��ѡ�����OpenFiles\n");
            if(OpenFiles()) printf("\t�ļ��򿪳ɹ���\n");
            else printf("\t�ļ���ʧ�ܣ�\n");
            break;
        default:
            printf("\n\tָ�����\n");
        }
        scanf("%d",&options);//������һ��ָ��
        getchar();
    }
    printf("\t��ӭ�´���ʹ�ñ�ϵͳ��\n");
}
