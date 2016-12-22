typedef struct{
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
