#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define OVERFLOE 666
#define OK 1
#define FALSE 0
#define ERROR 0
#define TRUE 1
 typedef int Status;
 typedef int ElemType;
 
 typedef struct LNode{
	 ElemType data;
	 struct LNode *next;
 }*Link, *Position;
 
 typedef struct{
	 Link head, tail;
	 int len;
 }LinkList;
 
 Status MakeNode(Link *p,ElemType e){
	 *p=(Link)malloc(sizeof(struct LNode));
	 if(*p){
		 (*p)->data=e;
		 return OK;
	 }
	 return ERROR;
 }
 
 void FreeNode(Link *p){
	 free(*p);
	 *p=NULL;
 }
 
 Status InitList(LinkList *L){
	 Link p;
	 p=(Link)malloc(sizeof(struct LNode));
	 if(p){
		 (*L)->head=(*L)->tail=p;
		 (*L)->len=0;
	 }
 }
 
 Status ClearList(LinkList *L){//空是指只剩一个头结点
	 if((*L)->head==(*L)->tail){
		 (*L)->len=0;
		 return OK;
	 }
	 Link p=(*L)->head,temp;
	 p=temp=p->next;
	 while(p!=(*L)->tail){
		 q=p->next;
		 free(p);
		 p=q;
	 }
	 free(p);
	 (*L)->tail=(*L)->head;
	 (*L)->len=0;
	 return OK;
 }
 
 Status DestroyList(LinkList *L){
	 ClearList(L);
	 FreeNode(&(*L)->head);
	 (*L)->tail=NULL;
	 (*L)->len=0;
	 return OK;
 }
 
 Status Insfirst(LinkList *L,Link h,Link s){
	 s->next=h->next;
	 h->next=s;
	 if(h==(*L)->tail){
		 (*L)->tail=s;
		 (*L)->len++;
		 return OK;
	 }
 }
 
 Status DelFirst(LinkList *L,Link h,Link *q){
	 /* 形参增加L,因为需修改L */
	/* h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。 */
   /* 若链表为空(h指向尾结点)，q=NULL，返回FALSE */
	*q=h->next;
	 if(*q){
		 h->next=(*q)->next;
//		 FreeNode(&(h->next));删除的不用释放 还要返回
		if(!h->next){
			(*L)->tail=h;
		}
		(*L)->len--; 
		 return OK;
	 }
	 return FALSE;
 }
 
 Status Append(LinkList *L, Link s){
	/* 将指针s(s->data为第一个数据元素)所指(彼此以指针相链,以NULL结尾)的 */
	/* 一串结点链接在线性链表L的最后一个结点之后,并改变链表L的尾指针指向新 */
	/* 的尾结点 */
	(*L)->len++;
	(*L)->tail->next=s;
	while(s->next){
		s=s->next;
		(*L)->len++;
	}
	(*L)->tail=s;
	return OK;
 }
 
 Status Remove(LinkList *L,Link *q){
	 Link p=(*L)->head;
	 if((*L)->len==0){
		 *q=NULL;
		 return FALSE;
	 }
	 *q=(*L)->tail;
	 while(p->next!=(*L)->tail){
		 p=p->next;
	 }
	 (*L)->tail=p;
	 p->next=NULL;
	 (*L)->len--;
	 return OK;
 }
  /* 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之前， */
   /* 并修改指针p指向新插入的结点 */
 Status InsBefore(LinkList *L,Link *p,Link s){
	 Link q=(*L)->head,temp;
	 while(q->next!=*p){
		 q=q->next;
	 }
	 q->next=s;
	 s->next=*p;
	 *p=s;
	 (*L)->len++;
	 return OK;
	}

Status InsAfter(LinkList *L,Link *p,Link s){ 
	/* 已知p指向线性链表L中的一个结点，将s所指结点插入在p所指结点之后， */
   /* 并修改指针p指向新插入的结点 */
   if(*p==(*L).tail){
	   (*L)->tail=s;
	   s->next=NULL;
   } /* 修改尾指针 */
	s->next=(*p)->next;
	(*p)->next=s;
	*p=s;
	(*L)->len++;
	return Ok;
}

Status SetCurElem(Link *p,ElemType e){
	 /* 已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值 */
	(*p)->data=e;
	return OK;
}

ElemType GetCurElem(Link p){
	/* 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值 */
	return p->data;
}

Status ListEmpty(LinkList L){
	 /* 若线性链表L为空表，则返回TRUE，否则返回FALSE */
  if(L.len){
	  return FALSE;
  }
  return TRUE;
}

int ListLength(LinkList L){
	return L.len;
}

Position GetHead(LinkList L){
//getback head point
	return L.head;
}

Position GetLast(LinkList L){
	return L.tail;
}

Position PriorPos(LinkList L,Link p){
	//返回p的直接前驱
	Link q=L.head->next;
	if(q==p){
		return NULL;
	}
	while(q->next!=p){
		q=q->next;
	}
	return q;
}

Position NextPos(LinkList L,Link p){
	return p->next;
}

Status Locatepos(LinkList L,int i,Link *p){
	if(i<0||i>L.len){
		return ERROR;
	}
	*p=L.head;
	for(int j=1;j<=i;j++){
		*p=(*p)->next;
		return OK;
	}
}

Position LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType)){
	Link p=L.head;
	p=p->next;
	while(p&&!(compare(p->data,e))){
		p=p->next;
		return p;
	}
}

Status ListTraverse(LinkList L,void(*visit)(ElemType)){
	Link p=L.head->next;
	for(int i=1;i<=L.len;i++){
		visit(p->data);
		p=p->next;
	}
	printf("\n");
	return OK;
}

Status OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType)){
	Link s,p,q;
	q=(*L).head;
	p=q->next;
	while(p!=NULL&&comp(p->data,e)<0){
		q=p;
		p=p->next;
	}
	s=(Link)malloc(sizeof(LNode));
	s->data=e;
	q->next=s;
	s->next=p;
	(*L).len++;
	if(!p){
		(*L).tail=s;
	}
	return OK;
}

 Status LocateElemP(LinkList L,ElemType e,Position *q,int(*compare)(ElemType,ElemType)){
	/* 若升序链表L中存在与e满足判定函数compare()取值为0的元素，则q指示L中 */
	/* 第一个值为e的结点的位置，并返回TRUE；否则q指示第一个与e满足判定函数 */
	/* compare()取值>0的元素的前驱的位置。并返回FALSE。（用于一元多项式） */
    Link s,p,pr;
	pr=(*L).head;
	p=(*L).head->next;
	int flag=1;
	while(p){
		int tag=compare(p->data,e);
		if(tag==0){
			*q=p;
			return TRUE;
		}else if(tag>0&&flag){
			*q=pr;
			flag=0;
		}
		pr=p;
		p=p->next;
	}
	return FALSE;
	
 }