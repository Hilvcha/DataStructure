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
 
 Status ClearList(LinkList *L){//����ָֻʣһ��ͷ���
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
	 /* �β�����L,��Ϊ���޸�L */
	/* hָ��L��һ����㣬��h����ͷ��㣬ɾ�������еĵ�һ����㲢��q���ء� */
   /* ������Ϊ��(hָ��β���)��q=NULL������FALSE */
	*q=h->next;
	 if(*q){
		 h->next=(*q)->next;
//		 FreeNode(&(h->next));ɾ���Ĳ����ͷ� ��Ҫ����
		if(!h->next){
			(*L)->tail=h;
		}
		(*L)->len--; 
		 return OK;
	 }
	 return FALSE;
 }
 
 Status Append(LinkList *L, Link s){
	/* ��ָ��s(s->dataΪ��һ������Ԫ��)��ָ(�˴���ָ������,��NULL��β)�� */
	/* һ�������������������L�����һ�����֮��,���ı�����L��βָ��ָ���� */
	/* ��β��� */
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
  /* ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮ǰ�� */
   /* ���޸�ָ��pָ���²���Ľ�� */
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
	/* ��֪pָ����������L�е�һ����㣬��s��ָ��������p��ָ���֮�� */
   /* ���޸�ָ��pָ���²���Ľ�� */
   if(*p==(*L).tail){
	   (*L)->tail=s;
	   s->next=NULL;
   } /* �޸�βָ�� */
	s->next=(*p)->next;
	(*p)->next=s;
	*p=s;
	(*L)->len++;
	return Ok;
}

Status SetCurElem(Link *p,ElemType e){
	 /* ��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ */
	(*p)->data=e;
	return OK;
}

ElemType GetCurElem(Link p){
	/* ��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ */
	return p->data;
}

Status ListEmpty(LinkList L){
	 /* ����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
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
	//����p��ֱ��ǰ��
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
	/* ����������L�д�����e�����ж�����compare()ȡֵΪ0��Ԫ�أ���qָʾL�� */
	/* ��һ��ֵΪe�Ľ���λ�ã�������TRUE������qָʾ��һ����e�����ж����� */
	/* compare()ȡֵ>0��Ԫ�ص�ǰ����λ�á�������FALSE��������һԪ����ʽ�� */
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