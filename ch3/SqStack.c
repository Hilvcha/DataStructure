#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
typedef int SElemType;
typedef int Status;
typedef struct Sqstack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}Sqstack;

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