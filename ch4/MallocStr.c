typedef struct{ //storage as same as length all the time
    char *ch;
    int length;
}HString;
Status StrAssign(HString *T,char *chars){
    if((*T).ch)       //former version may have data
        free((*T).ch);
    }
    int lench=strlen(chars);
    if(!lench){                 //chars 's length doesn't exist
        (*T).ch=NULL;
        (*T).length=NULL;
    }
    (*T).ch=(char *)malloc(sizeof(char)*lench);
    if(!(*T)){
        exit(OVERFLOW);
    }
    (*T).length=lench;
    for ( int i = 0; i < lench; i++ ) {
        (*T).ch[i]=chars[i];
    }
    return OK;
}
Status StrCopy(HString *T,HString S){
   if((*T).ch) {
       free((*T).ch);
   }
   (*T),ch=(char *)malloc(sizeof(char)*S.length);
   if(!(*T).ch){
       exit(OVERFLOW);
   }
   for ( int i = 0; i < S.length; i++ ) {
       (*T).ch[i]=S.ch[i];
   }
   (*T).length=S.length;
   return OK;
}
Status StrEmpty(HString S){
    if ( S.length==0&&S.ch==NULL) {
        return TRUE;
    }
    return FALSE;
}
int StrCompare(HString S,HString T){
    int i=0;
    while(i<=S.length&&i<=T.length){
        if ( S.ch[i]!=T.ch[i] ) {
            return S.ch[i]-T.ch[i];
        }
        i++;
    }
    return S.length-T.length;
}
int StrLength(HString S){
    return S.length;
}
Status ClearString(HString *S){
    free((*S).ch);
    (*S).ch=NULL;
    (*S).length=0;
    return OK;
}
Status Concat(HString *T,HString S1,HString S2){
    if((*T).ch){
        free((*T).ch);
    }
    (*T).ch=(char*)malloc(sizeof(char)*(S1.length+S2.length));
    if(!(*T).ch){
        exit(OVERFLOW);
    }
    int i=0
    for ( i = 0; i < S1.length; i++ ) {
        (*T).ch[i]=S1.ch[i];
    }
    for(int j=0; j < S2.length;j++){
        (*T).ch[i++]=S2.length[j];
    }
    (*T).length=S1.length+S2.length;
    return OK;
}
Status SubString(HString *Sub,HString S,int pos,int len){
    if ( !(1<=pos&&pos<=StrLength(S)&&0<=len&&len<=StrLength(S)-pos+1) ) {
        return ERROR;
    }
    if(!len){
        (*Sub).ch=NULL;
        (*Sub).length=0;
        return OK;
    }
    if((*Sub).ch){
        free((*T).ch);
    }
    (*Sub).ch=(char*)malloc(sizeof(char)*len);
    if(!(*Sub).ch){
        exit(OVERFLOW);
    }
    for ( int i = pos; i < pos+len; i++ ) {
        (*Sub).ch[i-pos]=(*S).ch[i];
    }
    (*Sub).length=len;
    return OK;
}
void InitString(HString *T){
    (*T).ch=NULL;
    (*T).length=0;
}
int Index(HString S,HString T,int pos){
    int lenS=StrLength(S),lenT=StrLength(T);
    int i=pos,j=1;
    while(i<lenS&&j<lenT) {
        if(S.ch[i]==T.ch[j]){
            i++;
            j++
        }else{
            i-j+2;
            j=1;
        }
    }
    if(j==lenT){
        return i;
    }else{
        return 0;
    }
}
Status StrLength(HString *S,int pos,HString T){
    if ( pos<1||pos>StrLength(S)+1 ) {
        return ERROR;
    }
    if (T.length) {//probable empty
        (*S).ch=(char*)realloc((*S).ch,(T.length+(*S).length)*sizeof(char));
        if(!(*S).ch){
            exit(OVERFLOW);
        }
        for ( int i = (*S).length-1; i >=pos-1; i-- ) {
            (*S).ch[i+T.length]=(*S).ch[i];
        }
        for ( int j = pos-1; j < pos+T.length; j++ ) {
            (*S).ch[j]=T.ch[j-pos+1];//one is from jishuciweixu
        }
        (*S).length+=T.length;
    }
    return OK;
}
Status StrDelete(HString *S,int pos,int len){
    if(pos<1||pos>(*S).length||len>(*S).length-pos||len<1){
        return ERROR;
    }
    for ( int i = pos-1; i < (*S).length-len; i++ ) {
        (*S).ch[i]=(*S).ch[i+len];
    }
    (*S).length-=len;
    (*S).ch=(char*)realloc((*S).ch,(*S).length*sizeof(char));
    return OK;
}
Status Replace(HString *S,HString T,HString V){
    int i=1;
    if(StrEmpty(T)){
        return ERROR;
    }
    while(i){
        i=Index(*S,T,i);
        if(i){
            StrDelete(S,i,StrLength(T));
            StrInsert(S,i,v);
            i+=StrLength(V);
        }
    }
    return OK;
}
//堆分配字符串无法销毁？
