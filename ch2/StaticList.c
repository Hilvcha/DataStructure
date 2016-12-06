 /* c2-3.h 线性表的静态单链表存储结构 */
 #define MAXSIZE 100 /* 链表的最大长度 */
 typedef struct
 {
   ElemType data;
   int cur;
 }component,SLinkList[MAXSIZE];
 /* bo2-3.c 实现算法2.15、2.16的程序 (数据结构由c2-3.h定义) (3个) */
 int Malloc(SLinkList space) /* 算法2.15 */
 { /* 若备用链表非空,则返回分配的结点下标(备用链表的第一个结点),否则返回0 */
	int i=space[0].cur;
	if(i){
		space[0].cur=space[i].cur;
	}
	return i;
 }

void Free(SLinkList space,int k) /* 算法2.16 */
{ /* 将下标为k的空闲结点回收到备用链表(成为备用链表的第一个结点) */
	space[k].cur=space[0].cur;
	space[0].cur=k;
}
 
 void DestroyList()
 { /* 静态数组不能被销毁 */
 }
