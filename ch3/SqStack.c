#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2

typedef int SElemType;
typedef int Status;
typedef struct Sqstack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

 Status InitStack(SqStack *S)
 { /* 构造一个空栈S */
	(*S).base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base){
		exit(OVERFLOW);
	}
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
   return OK;
 } 

Status DestroyStack(SqStack *S){
    free((*S).base);
    (*S).base=NULL;
    (*S).top=NULL; 
    (*S).stacksize=NULL;
    return 0;
}
Status ClearStack(SqStack *S){
    free((*S).base);
    (*S).top=(*S).base;
    return OK;
}
Status StackEmpty(SqStack S){
    if(S.top==S.base){
        return OK;
    }
    return FALSE;
}
Status StackLength(SqStack S){
    return S.top-S.base;
}
Status GetTop(SqStack S,SElemType *e){
    if ( StackEmpty(S) ) {
        return ERROR;
    }
    *e=*(S.top-1);
    return OK;
}
Status Push(SqStack *S,SElemType e){
    if ( (*S).top-(*S).base>(*S).stacksize  ) {
        (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
        if ( !S->base ) {
            exit(OVERFLOW);
        }
        S->top=S->base+S->stacksize;
        S->stacksize+=STACKINCREMENT;
    }
    *(S->top)=e;
    (S->top)++;
    return OK;
}
Status Pop(Sqstack *S,SElemType *e){
   if ((*S).top==(*S).base){
       return ERROR;
   }
   *e=*(--(*S).top);
   return OK;
}
Status StackTraverse(Sqstack S,Status(*visit)(SElemType)){
    while(S.top>S.base){
        visit(*S.base);
        S.base++;
    }
    return OK;
}
