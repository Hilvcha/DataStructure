/************************************************
 *Author*        :WYJ
 *Created Time*  : 12/21/2016 10:54:35 PM
**Problem**:
**Analyse**:
**Get**:
**Code**:
*********************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f;
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define NULL 0
#define ERROR 0
#include "Sqstack.c"

void conversion(int N){
    Sqstack S;
    InitStack(&S);
    while ( N ) {
        Push(&S,N%8);
        N/=8;
    }
    int n=0;
    while(!StackEmpty(S)){
        Pop(&S,&n);
        printf("%d",n);
    }
}


int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int N=0;
    scanf("%d",&N);
    conversion(N);
    return 0;
}
