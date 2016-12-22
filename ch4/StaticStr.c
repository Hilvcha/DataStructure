/************************************************
 *Author*        :WYJ
 *Created Time*  : 12/22/2016 10:02:34 AM
**Problem**: １．求串长 StrLength(s)
操作条件：串 s 存在
操作结果：求出串 s 的长度。
２．串赋值 StrAssign(s1,s2)
操作条件：s1 是一个串变量，s2 或者是一个串常量，或者是一个串变量（通常 s2 是一个串常量
时称为串赋值，是一个串变量称为串拷贝） 。
操作结果：将 s2 的串值赋值给 s1， s1 原来的值被覆盖掉。
３．连接操作 ：StrConcat (s1,s2,s) 或 StrConcat (s1,s2)
操作条件：串 s1,s2 存在。
操作结果：两个串的连接就是将一个串的串值紧接着放在另一个串的后面，连接成一个串。前者
是产生新串 s，s1 和 s2 不改变，后者是在 s1 的后面连接 s2 的串值，s1 改变，s2 不改变。
例如： s1=＂he＂，s2=＂bei＂，前者操作结果是 s=＂he bei＂；后者操作结果是 s1=＂he bei＂。
４．求子串 SubStr (s,i,len)：
操作条件：串 s 存在，1≤i≤StrLength(s)，0≤len≤StrLength(s)-i+1。
操作结果：返回从串 s 的第 i 个字符开始的长度为 len 的子串。len=0 得到的是空串。
例如：SubStr(＂abcdefghi＂,3,4)= ＂cdef＂
５．串比较 StrCmp(s1,s2)
操作条件：串 s1,s2 存在。
操作结果：若 s1==s2，操作返回值为 0；若 s1<s2，返回一个负整数；若 s1>s2, 返回一个正整数。
６．子串定位 StrIndex(s,t)：找子串 t 在主串 s 中首次出现的位置
操作条件：串 s,t 存在。
操作结果：若 t∈s，则操作返回 t 在 s 中首次出现的位置，否则返回值为-1。
如：StrIndex(＂abcdebda＂,＂bc＂)=2
StrIndex(＂abcdebda＂,＂ba＂)=-1
７．串插入 StrInsert(s,i,t)
操作条件：串 s,t 存在，1≤i≤StrLength(s)+1。
操作结果：将串 t 插入到串 s 的第 i 个字符位置上，s 的串值发生改变。
８．串删除 StrDelete(s,i,len)
操作条件：串 s 存在，1≤i≤StrLength(s)，0≤len≤StrLength(s)-i+1。
操作结果：删除串 s 中从第 i 个字符开始的长度为 len 的子串，s 的串值改变。
９．串替换 StrRep(s,t,r)
操作条件：串 s,t,r 存在，t 不为空。
操作结果：用串 r 替换串 s 中出现的所有与串 t 相等的不重叠的子串，s 的串值改变。
以上是串的几个基本操作。其中前 5 个操作是最为基本的，它们不能用其他的操作来合成，因此
通常将这５个基本操作称为最小操作集。12
【基本要求】
**Analyse**:
**Get**:
**Code**:
*********************************************/
#define MAXSTRLEN 40
typedef char SString[MAXSTRLEN+1];
Status StrAssign(SString T,char *chars){
    if ( strlen(chars)>MAXSTRLEN ) {
        return ERROR;
    }
    int lenT=StrLength(T);
    for ( int i = 1; i <= lenT ; i++ ) {  //strlength is T[0]
        T[i]=*(chars++);
    }
    return OK;
}
Status StrCopy(SString T,SString S){
    for ( int i =1; i <= len[S]; i++ ) {
        T[i]=S[i];
    }
    return OK;
}
Status StrEmpty(SString S){
    if(S[0]==0){
        return TRUE;
    }
    return FALSE;
}
int StrCompare(SString S,SString T){
    int stra=1,strb=1;
    int len=StrLength(S)>StrLength(T)?StrLength(T):StrLength(S);
    for ( int i = 1; i <= len; i++ ) {
        if ( T[i]!=S[i] ) {
            return S[i]-T[i];
        }
    }
    return S[0]-T[0];// Slenth>T the later part of S enable it > T
}
int StrLength(SString S){
    return S[0];
}
Status ClearString(SString S){
    S[0]=0;  //static storage doesn't need free. there is the space all the Time
    return OK;
}
Status Concat(SString T,SString S1,SString S2){
    if ( StrLength(S1)+StrLength(S2)<=MAXSTRLEN  ) {
        T[0]=StrLength(S1)+StrLength(S2);
        int i;
        for ( i = 1; i <=StrLength(S1); i++ ) {
            T[i]=S1[i];
        }
        for ( ; i <=T[0]; i++ ) {
            T[i]=S2[i];
        }
        return TRUE;
    }else if (StrLength(S1)>=MAXSTRLEN){
        for ( int i = 1; i <= MAXSTRLEN; i++ ) {
            T[i]=S1[i];
        }
        T[0]=MAXSTRLEN;
        return FALSE;
    }else {
        int i;
        for ( i = 1; i <= StrLength(S1); i++ ) {
            T[i]=S1[i];
        }
        for ( ; i <= MAXSTRLEN; i++ ) {
            T[i]=S2[i];
        }
        T[0]=MAXSTRLEN;
        return FALSE;
    }
}
Status SubString(SString Sub,SString S,int pos,int len){
    if ( pos<1||pos>S[0]||len<0||len>S[0]-pos+1 ) {
        return ERROR;
    }
    int strb=1;
    for ( int i = pos; i <= pos+len-1; i++ ) {
        Sub[strb++]=S[i];
    }
    Sub[0]=len;
    return OK;
}
int Index(SString S,SString T,int pos){
    int lenT=StrLength(T);
    for (int i=pos;  i<=StrLength(S); i++ ) {
        if ( S[i]==T[1] ) {
            int tempi=i;
            for ( int j = 1; j <= lenT; j++ ) {
                if(S[tempi++]==T[j]){
                    continue;
                }else{
                    break;
                }
            }
            if(j==lenT+1){
                return i;
            }
        }
    }
    return 0;
}
Status StrInsert(SString S,int pos,SString T){
      if ( pos<1||pos>StrLength(S)+1  ) {
          return ERROR;
      }
      if(StrLength(S)+StrLength(T)<=MAXSTRLEN){//all in
          int k=1;
          for ( int i = StrLength(S); i >=pos; i-- ) {
              S[i+StrLength(T)]=S[i];
          }
          for ( int j = pos; j <= pos+StrLength(T); j++ ) {
              S[j]=T[k++];
          }
          S[0]=S[0]+T[0];
          return TRUE;
      }else{//part of
          ???
            return FALSE;
      }
}
Status StrDelete(SString S,int pos,int len){
    if ( !(1<=pos&&StrLength(S)-len+1>=pos) ) {
        return ERROR;
    }
    for ( int i = pos; i <= StrLength(S); i++ ) {
        S[i]=S[i+len<MAXSTRLEN?i+len:MAXSTRLEN];
    }
    S[0]-=len;
    return OK;
}
Status Replace(SString S,SString T,SString V){
   /* 操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */    
    if(StrEmpty(T)){
        return ERROR;
    }
    int i=1;
    while(i=Index(S,T,i)){
        StrDelete(S,i,StrLength(T));
        StrInsert(S,i,V);
        i+=StrLength(V);
    }
    return OK;
}
void StrPrint(SString T){
    int i;
    for(i=1;i<=T[0];i++){
        printf("%c",T[i]);
    }
    printf("\n");
}
