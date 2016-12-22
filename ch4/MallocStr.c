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
    
}
