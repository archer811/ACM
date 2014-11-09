#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define N 1005
#define V 102005
int U[V],D[V],L[V],R[V],C[V],H[N],S[N],mark[V];
int size,n,m,ok[N],flag;
const int inf = 0x3f3f3f3f;
void link(int r,int c)
{
    S[c]++;C[size]=c;
    U[size]=U[c];D[U[c]]=size;
    D[size]=c;U[c]=size;
    if(H[r]==-1)H[r]=L[size]=R[size]=size;
    else
    {
        L[size]=L[H[r]];
        R[L[H[r]]]=size;
        R[size]=H[r];
        L[H[r]]=size;
    }
    mark[size]=r;
    size++;
}
void remove(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
        for (int j = R[i]; j != i; j = R[j])
            U[D[j]] = U[j], D[U[j]] = D[j], S[C[j]]--;
}
void resume(int c)
{
    int i,j;
    for(i=U[c];i!=c;i=U[i])
    {
        for(j=L[i];j!=i;j=L[j])
        {
            U[D[j]]=j;
            D[U[j]]=j;
            S[C[j]]++;
        }
    }
    L[R[c]]=c;
        R[L[c]]=c;
}
void dance(int k)
{
    int i,j,Min,c;
    if(!R[0])
    {
        flag=1;
        printf("%d",k);
        for(i=0;i<k;i++)
            printf(" %d",mark[ok[i]]);
        printf("\n");
        return ;
    }
    for(Min=inf,i=R[0];i;i=R[i])
        if(S[i]<Min)Min = S[i],c=i;
    remove(c);
    for(i=D[c];i!=c;i=D[i])
    {
        ok[k]=i;
        for(j=R[i];j!=i;j=R[j])
            remove(C[j]);
        dance(k+1);
        if(flag)return;
        for(j=L[i];j!=i;j=L[j])
            resume(C[j]);
    }
    resume(c);
}
int main()
{
    int i,j,num;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<=m;i++)
        {
            S[i]=0;
            D[i]=U[i]=i;
            L[i+1]=i;
            R[i]=i+1;
        }
        R[m]=0;
        size = m+1;
        memset(H,-1,sizeof(H));
        memset(mark,0,sizeof(mark));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&j);
                link(i,j);
            }
        }
        flag=0;
        dance(0);
        if(!flag)puts("NO");
    }
}
