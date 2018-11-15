#include "SqList.h"
void main(void)
{
    SqListsOptioner *SqLists = &Lists;//头文件中的全局变量
    SqList *pList=NULL;//在程序中操作的线性表
    int OpListNum=0;//当前操作的线性表的编号
    int i;
    int options;//在菜单中选择的选项
    ElemType elem,*elem2;//在后续操作中会用到的元素
    if(!PreLoadFiles()) printf("****程序运行错误！文件无法打开！\n");
    printf("****当前线性表数：%d\t（最大线性表数%d）\n",SqLists->length,MAX_SQLIST_NUM);
    printf("****当前操作的线性表（n=1,2,3....）:");//显示当前的线性表数量和正在操作的线性表
    if(!OpListNum) printf("\t请选择要操作的线性表\n");
    else printf("%d\n",OpListNum);
    if(!SqLists->length) printf("\t（当前无可操作的线性表！）\n");
    menu();//菜单
    scanf("%d",&options);
    getchar();
    while(options)
    {
        system("cls");//每次循环后清屏
        menu();
        printf("****当前线性表数：%d\t（最大线性表数%d）\n",SqLists->length,MAX_SQLIST_NUM);
        printf("****当前操作的线性表（n=1,2,3....）:\n");
        switch(options)
        {
        case 0:
            break;
        case 1:
            printf("\n****你选择的是  InitiaList\n");
            if(SqLists->length>=MAX_SQLIST_NUM)
            {
                printf("\t线性表操作数已达到最大值！不能继续创建线性表\n");
                getchar();
                break;
            }
            if (!(SqLists->SqListArray[SqLists->length++] =(SqList *)malloc(sizeof(SqList))))
                exit(OVERFLOW);
            if(InitiaList(SqLists->SqListArray[SqLists->length-1])==OK)//在线性表指针数组中创建新指针并对该指针创建线性表
            {
                printf("\t线性表%d创建成功！\n",SqLists->length);
                printf("****当前线性表数：%d\t（最大线性表数%d）\n",SqLists->length,MAX_SQLIST_NUM);
            }
            else
            {
                printf("\t线性表创建失败！\n");
                free(SqLists->SqListArray[SqLists->length-1]);
            }
            break;

        case 2:
            printf("\n****你选择的是  DestroyList\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要销毁的线性表！\n");
                break;
            }
            else if(DestroyList(pList))
            {
                printf("\t线性表%d销毁成功！\n",OpListNum);
                if(OpListNum<SqLists->length)
                    for(i=OpListNum; i<SqLists->length-1; i++)
                        SqLists->SqListArray[i-1]=SqLists->SqListArray[i];
                SqLists->length--;
            }
            OpListNum=0;
            break;
        case 3:
            printf("\n****你选择的是  ClearList\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要置空的线性表！\n");
                break;
            }
            if(CleaList(pList))
                printf("\t线性表%d置空成功！\n");
            break;
        case 4:
            printf("\n****你选择的是  ListEmpty\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要判空的线性表！\n");
                break;
            }
            if(ListEmpty(pList))
                printf("\t线性表为空！\n");
            else printf("\t线性表不为空！\n");
            break;
        case 5:
            printf("\n****你选择的是  ListLength \n");
            if(OpListNum<1)
            {
                printf("\t请先选择要求长度的线性表！\n");
                break;
            }
            printf("\t线性表的长度为%d!\n",ListLength(pList));
            break;
        case 6:
            printf("\n****你选择的是   GetElem\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要获取元素的线性表！\n");
                break;
            }
            printf("\t请输入你需要获得第几个元素：");
            scanf("%d",&i);
            getchar();
            if(i>=1&&i<=pList->length)
            {
                GetElem(pList,i,&elem);
                printf("\t线性表中的第%d个元素为：%d\n",i,elem);
            }
            else printf("\t元素不存在！\n");
            break;

        case 7:
            printf("\n****你选择的是  LocatElem\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要定位元素的线性表！\n");
                break;
            }
            printf("\t请输入要查找的元素：");
            scanf("%d",&elem);
            getchar();
            if(i=LocateElem(pList,elem)) printf("\t你查找的元素为表中的第%d个元素\n",i);
            else printf("\t元素不存在！\n");
            break;

        case 8:
            printf("\n****你选择的是 PriorElem\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要获取元素前驱的线性表！\n");
                break;
            }
            printf("\t请输入你要获取哪一个元素的前驱：");
            scanf("%d",&i);
            getchar();
            if(PriorElem(pList,i,&elem)) printf("\t元素%d的前驱是%d！\n",i,elem);
            else printf("\t前驱不存在！\n");
            break;
        case 9:
            printf("\n****你选择的是 NextElem\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要获取元素后继的线性表！\n");
                break;
            }
            printf("\t请输入你要获取哪一个元素的后继：");
            scanf("%d",&i);
            getchar();
            if(NextElem(pList,i,&elem)) printf("\t元素%d的后继是%d！\n",i,elem);
            else printf("\t后继不存在！\n");
            break;
        case 10:
            printf("\n****你选择的是 ListInsert\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要插入元素的线性表！\n");
                break;
            }
            printf("\t请输入你要插入元素的位置和要插入元素的值：");
            scanf("%d%d",&i,&elem);
            getchar();
            if(ListInsert(pList,i,elem)) printf("\t元素%d已成功插入到第%d个位置之前！\n",elem,i);
            else printf("\t插入失败！\n");
            break;
        case 11:
            printf("\n****你选择的是 ListDelete\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要删除元素的线性表！\n");
                break;
            }
            printf("\t请输入你要删除的元素位置：");
            scanf("%d",&i);
            getchar();
            if(ListDelete(pList,i,&elem)) printf("\t第%d个元素%d已从线性表中删除！\n",i,elem);
            else printf("\t元素删除失败！\n");
            break;
        case 12:
            printf("\n****你选择的是ListTrabverse\n");
            if(OpListNum<1)
            {
                printf("\t请先选择要遍历的线性表！\n");
                break;
            }
            if(!ListTraverse(pList)) printf("\t线性表为空表！\n");
            break;
        case 13:
            printf("\n****你选择的是ChooseList\n");
            pList=ChooseList(&OpListNum);
            printf("\t当前操作的线性表为线性表%d\n",OpListNum);
            break;
        case 14:
            printf("\n****你选择的是SaveData\n");
            if(SaveData()) printf("\t文件保存成功！\n");
            else printf("\t文件保存失败！\n");
            break;
        case 15:
            printf("\n****你选择的是OpenFiles\n");
            if(OpenFiles()) printf("\t文件打开成功！\n");
            else printf("\t文件打开失败！\n");
            break;
        default:
            printf("\n\t指令错误！\n");
        }
        scanf("%d",&options);//读入下一个指令
        getchar();
    }
    printf("\t欢迎下次再使用本系统！\n");
}
