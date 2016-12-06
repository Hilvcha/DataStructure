/* algo2-2.c 实现算法2.2的程序 */
#include"s2.c"
void MergeList(SqList *La,SqList *Lb,SqList *Lc) /* 算法2.2 */
{   /* 已知线性表La和Lb中的数据元素按值非递减排列。 */
    /* 归并La和Lb得到新的线性表Lc,Lc的数据元素也按值非递减排列 */
    InitList_Sq(Lc);
    int len_a=ListLength(La);
    int len_b=ListLength(Lb);
    int len_c=0;
    ElemType a,b;
    int i=1,k=1;
    while(i<=len_a&&k<=len_b){
        GetElem(La,i,&a);
        GetElem(Lb,k,&b);
        if(a>b){
            ListInsert(Lc,++len_c,b);
            k++;
        }else{
            ListInsert(Lc,++len_c,a);
            i++;
        }

    }
    while(i<=len_a){
        GetElem(La,i,&a);
        ListInsert(Lc,++len_c,a);
        i++;
    }
    while(k<=len_b){
        GetElem(Lb,k,&b);
        ListInsert(Lc,++len_c,b);
        k++;
    }
}
void Print(ElemType *e)
{
    printf("%d ",*e);
}
int main()
{
    SqList La,Lb,Lc;
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    for(int i=1;i<=5;i++){
        ListInsert(&La,i,2*i);
        ListInsert(&Lb,i,3*i);
    }
    MergeList(&La,&Lb,&Lc);
    ListTraverse(Lc,Print);
    return 0;
}
