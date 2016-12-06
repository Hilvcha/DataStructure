/*
    程序名称：实现算法2-1
    编辑日期：2016年10月9日23:04:03
    程序功能：
*/
#include"s2.c"
#define OVERFLOW 1
//所有在Lb但不在la中的插入到la中
Status equal(ElemType c1,ElemType c2)
{
    if(c1==c2){
        return TRUE;
    }else{
        return FALSE;
    }
}
void Union(SqList *La,SqList *Lb)
{
    ElemType e;
    int len_a=ListLength(La);
    int len_b=ListLength(Lb);
    for(int i=1;i<=len_b;i++){
        GetElem(Lb,i,&e);
        if(!LocateElem(&Lb,e,equal)){
            ListInsert(La,++len_a,e);

        }
    }

}

void Print(ElemType *e)
{
    printf("%d ",*e);
}
int main()
{
    SqList La,Lb;
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    for(int i=1;i<=5;i++){
        ListInsert(&La,i,2*i);
        ListInsert(&Lb,i,3*i);
    }
    Union(&La,&Lb);
    ListTraverse(La,Print);
    return 0;
}
