/*
    程序名称：线性表的单链表存储结构
    编辑日期：2016年10月12日22:06:52
    程序功能：链表的基本操作
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
struct LNode{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;


/*
    程序名称：线性表的顺序表示和实现12
    编辑日期：2016-9-26 00:28:13
    程序功能：基本操作
*/
Status InitList(LinkList *L)
{ /* 操作结果：构造一个空的线性表L */

    *L=(LinkList)malloc(sizeof(LNode));
    if(!*L){
        exit(OVERFLOW);
    }
    (*L)->next=nullptr;
    return OK;
}
Status DestroyList(LinkList *L)
{ /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
    LinkList temp=nullptr;
    while(*L){
        temp=*L;
        *L=(*L)->next;
        free(temp);
    }
    return OK;
}
Status ClearList(LinkList L) /* 不改变L */
{ /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
    LinkList temp1=L->next;
    LinkList temp2=nullptr;
    while(temp1){
        temp2=temp1;
        temp1=temp1->next;
        free(temp2);
    }
    L->next=nullptr;
    return OK;
}
Status ListEmpty(LinkList L)
{ /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */

    if(!L->next){
        return OK;
    }
    return FALSE;
}
int ListLength(LinkList L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
    int count=0;
    LinkList p=L->next;
    while(p){
        p=p->next;
        count++;
    }
    return count;
}
Status GetElem(LinkList L,int i,ElemType *e) /* 算法2.8 */
{ /* L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
    LinkList p=L->next;
    int count=1;
    while(p&&count<i){
        p=p->next;
        count++;
    }
    if(!p||count>i){
        return ERROR;
    }
    *e=p->data;
    return OK;
}
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{ /* 初始条件: 线性表L已存在,compare()是数据元素判定函数(满足为1,否则为0) */
   /* 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。 */
   /*           若这样的数据元素不存在,则返回值为0 */
    LinkList p=L->next;
	int count=1;
	while(p){
		if(compare(e,p->data)){
			return count;
		}
		count++;
		p=p->next;
	}
	
    return 0;
}
 Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
 { /* 初始条件: 线性表L已存在 */
   /* 操作结果: 若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱, */
   /*           返回OK;否则操作失败,pre_e无定义,返回INFEASIBLE */
    LinkList p=L->next;
	LinkList temp;
	while(p->next){
		temp=p->next;
		if(temp->data==cur_e){
			*pre_e=p->data;
			return OK;
		}
		p=temp;
	}
	return INFEASIBLE;
	
}
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* 初始条件：线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， */
   /*           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE */
    LinkList p=L->next;
	while(p->next){
		if(cur_e==p->data){
			*next_e=p->next->data;
			return OK;
		}
		p=p->next;
	}
	return INFEASIBLE;
}
Status ListInsert(LinkList L,int i,ElemType e) /* 算法2.9。不改变L */
{ /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
	LinkList p=L;
	LinkList insert;
	int count=0;
	while(p&&count<i-1){
		count++;
		p=p->next;
	}
	if(!p||count>i-1){
		return ERROR;
	}
	insert=(LNode)malloc(sizeof(struct LNode));
	insert->data=e;
	insert->next=p->next;
	p->next=insert;
	return OK;
}
Status ListDelete(LinkList L,int i,ElemType *e) /* 算法2.10。不改变L */
{ /* 在带头结点的单链线性表L中，删除第i个元素,并由e返回其值 */
	LinkList p=L->next,temp;
	int count=1;
	while(p&&count<i-1){
		p=p->next;
		count++;
	}
	if(!p||count>i-1){
		return ERROR;
	}
	temp=p->next;
	p->next=temp->next;
	*e=temp->data;
	free(temp);
	return OK;
}

Status ListTraverse(LinkList L,void(*vi)(ElemType))
/* vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 */
/* 初始条件：线性表L已存在 */
/* 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
{   
	LinkList p=L->next;
	vi(p->data);
	while(p->next){
		p=p->next;
		vi(p->data);
	}
	printf("\n");
	return OK;
}
	