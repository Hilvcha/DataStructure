
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
 /* bo2-4.c 设立尾指针的单循环链表(存储结构由c2-2.h定义)的12个基本操作 */
 Status InitList_CL(LinkList *L)
 { /* 操作结果：构造一个空的线性表L */
	*L=(LinkList)malloc(sizeof(LNode));
	if(*L){
		*L->next=*L;
		return OK;
	}
	return ERROR;//此时他是头结点 也是最后一个结点 符合尾指针 和 空表需要头结点的定义
 }

Status DestroyList_CL(LinkList *L)
{ /* 操作结果：销毁线性表L */
	LinkList q,p=*L->next;
	while(p!=*L){
		q=p->next;
		free(p);
		p=q;
	}
	free(*L);
	*L=NULL;
	return OK;
}

Status ClearList_CL(LinkList *L) /* 改变L */
{ /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
	LinkList p=*L->next,q;
	while(p!=*L){
		q=p->next;
		free(p);
		p=q;
	}
	*L->next=NULL;
	return OK;
}

Status ListEmpty_CL(LinkList L)
{ /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
	if(L){
		if(L->next==L){
			return TRUE;
		}else
		return FALSE;
	}
	return ERROR;
}

int ListLength_CL(LinkList L)
{ /* 初始条件：L已存在。操作结果：返回L中数据元素个数 */
	LinkList p=L->next; 
	int count=0;
	while(p!=L){
		p=p->next;
		count++;
	}
	return count;//计数的这个值之所以从“头指针开始0计数是因为当比到最后一个节点无法计数 所以把头结点当成最后一个结点 前面多记了一个”
}

Status GetElem_CL(LinkList L,int i,ElemType *e)
{ /* 当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
		LinkList p=L->next;
		p=p->next;
		int count=1;
		while(p!=L&&count<i){
			p=p->next;
			count++;
		}
		if(p==L||count>i){
			return ERROR;
		}
		*e=p->data;
		return OK;
}

int LocateElem_CL(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{ /* 初始条件：线性表L已存在，compare()是数据元素判定函数 */
   /* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。 */
   /*           若这样的数据元素不存在，则返回值为0 */
	LinkList p=L->next;
	p=p->next;
	int count=1;
	while(p!=L->next){
		if(compare(p->data,e)){
			return i;
		}
		p=p->next;
		count++;
	}
	return 0;
}

 Status PriorElem_CL(LinkList L,ElemType cur_e,ElemType *pre_e)
{ /* 初始条件：线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， */
   /*           否则操作失败，pre_e无定义 */
	LinkList p=L->next;
	p=p->next;
	while(p->next->data!=cur_e&&p->next!=L->next){
		p=p->next;
	}
	if(p->next==L->next){
		return FALSE;
	}
	*pre_e=p->data;
	return OK;
}

 Status NextElem_CL(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* 初始条件：线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素,且不是最后一个,则用next_e返回它的后继， */
   /*           否则操作失败，next_e无定义 */
	LinkList p=L->next;
	p=p->next;
	while(p->next!=L->next){
		if(p->data=cur_e){
			*next_e=p->next->data;
		}
		p=p->next;
	}
	return FALSE;
 }

Status ListInsert_CL(LinkList *L,int i,ElemType e) /* 改变L */
{ /* 在L的第i个位置之前插入元素e */
	 LinkList p=(*L)->next,s; /* p指向头结点 */
	int j=0;
	if(i<=0||i>ListLength_CL(*L)+1) /* 无法在第i个元素之前插入 */
		return ERROR;
	while(j<i-1) /* 寻找第i-1个结点 */
	{
		p=p->next;
		j++;
	}
	s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
	s->data=e; /* 插入L中 */
	s->next=p->next;
	p->next=s;
	if(p==*L) /* 改变尾结点 */
		*L=s;
	return OK;
}

Status ListDelete_CL(LinkList *L,int i,ElemType *e) /* 改变L */
{ /* 删除L的第i个元素,并由e返回其值 */
	LinkList p=(*L)->next,s;
	int count=0;
	if(i<=0||i>ListLength_CL(*L)+1){
		return ERROR;
	}
	while(count<i-1){
		p=p->next;
		count++;
	}
	s=p->next;
	p->next=s->next;
	*e=s->data;
	if(*L==s){
		*L=p;
	}
	free(s);
	return  OK;
	
}

Status ListTraverse_CL(LinkList L,void(*vi)(ElemType))
{ /* 初始条件:L已存在。操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
	 LinkList p=L->next->next;
	while(p!=L->next)
	{
		vi(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}