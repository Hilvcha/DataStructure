/*
    程序名称：LALB顺序归并为LC表
    编辑日期：2016年9月26日00:30:52
    程序功能：归并 顺序存储
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<limits.h>
#include<ctype.h>
#include<process.h>
#include<string.h>
#define LIST_INIT_SIZE 10//线性表存储的初始分配值
#define LISTINCREMENT 2  //空间分配增量
#define OVERFLOW 666
#define OK 1
#define FALSE 0
#define TRUE 1

#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;//存储的容量
}SqList;


/*
    程序名称：线性表的顺序表示和实现12
    编辑日期：2016-9-26 00:28:13
    程序功能：基本操作
*/
//构造一个空的动态分配顺序线性表
Status InitList_Sq(SqList*L)
{
    (*L).elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem){
        exit(OVERFLOW);
    }
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
    return OK;
}
//操作结果：销毁顺序线性表L
Status DestroyList(SqList *L)
{
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
    return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
 {
    L->length=0;
    return OK;
 }
 /* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList *L)
{
    if(!L->length){
        return OK;
    }
    return FALSE;
}
 /* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
  int ListLength(SqList *L)
 {
     return L->length;
 }
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(SqList *L,int i,ElemType *e)
{
    *e=*(L->elem+i-1);
    return OK;
}
/* 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1,否则为0) */
/* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。 */
/*           若这样的数据元素不存在，则返回值为0。算法2.6 */
int LocateElem(const SqList *L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    for(int i=0;i<L->length;i++){
        if(compare((*L).elem[i],e)){
            return i+1;
        }
    }
    return 0;
}
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， */
/*           否则操作失败，pre_e无定义 */
Status PriorElem(const SqList *L,ElemType cur_e,ElemType *pre_e)
{
    int i=2;
    ElemType *p=L->elem+1;
    while(i<=L->length&&*p!=cur_e){
        p++;
        i++;
    }
    if(i<=L->length){
        *pre_e=*--p;
        return OK;
    }
    else{
        return FALSE;
    }
}
/* 初始条件：顺序线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， */
   /*           否则操作失败，next_e无定义 */

Status NextElem(SqList L,ElemType cur_e,ElemType *next_e)
{
    int i=L.length-1;
    ElemType *p=L.elem+L.length-2;
    while(i>0&&*p!=cur_e){
        p--;
        i--;
    }
    if(i>0){
        *next_e=*++p;
        return OK;
    }else{
        return FALSE;
    }
}
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1 */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */

Status ListInsert(SqList *L,int i,ElemType e) /* 算法2.4 */
{
    ElemType *newbase,*q,*p;
    if(i<1||i>L->length+1){
        return FALSE;
    }
    if(L->length+1>L->listsize){
        newbase=(ElemType*)realloc(L->elem,(LIST_INIT_SIZE+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase){
            return FALSE;
        }
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;
    }
    q=L->elem+i-1;
    for(p=L->elem+L->length-1;p>=q;p--){
        *(p+1)=*p;
    }
    L->length++;
    *q=e;
    return OK;
}
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L,int i,ElemType *e) /* 算法2.5 */
{
    ElemType *q,*p;
    if(i<1||i>L->length){
        exit(FALSE);
    }
    q=L->elem+L->length-1;
    *e=*q;
    for(p=L->elem+i-1;p<=q;p++){
        *(p-1)=*p;
    }
    L->length--;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */
/*           vi()的形参加'&'，表明可通过调用vi()改变元素的值 */
Status ListTraverse(SqList L,void(*vi)(ElemType*))
{
    ElemType *p;
    int i;
    p=L.elem;
    for(i=1;i<=L.length;i++){
        vi(p++);
    }
    return OK;
}
