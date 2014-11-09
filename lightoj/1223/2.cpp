#include <iostream>
#include <cstdio>
#include <cstring>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;


const int INF=1000000000;
int C,num=0;
int f[105][105][105],n,m;


int DFS(int x,int L,int R)
{
    if(L>R) return 0;
    int &ans=f[x][L][R],i;
    if(ans!=-1) return ans;
    ans=INF;
    for(i=L;i<=R;i++) ans=min(ans,i+max(DFS(x-1,L,i-1),DFS(x,i+1,R)));
    return ans;
}

void init()
{
    memset(f,-1,sizeof(f));
    int i,j,k;
    for(i=1;i<=100;i++) for(j=i;j<=100;j++) f[1][i][j]=(i+j)*(j-i+1)/2;
    for(i=2;i<=100;i++) for(j=1;j<=100;j++) for(k=j;k<=100;k++)
        DFS(i,j,k);
}

int main()
{
    init();
    for(scanf("%d",&C);C--;)
    {
        scanf("%d%d",&m,&n);
        printf("Case %d: %d\n",++num,f[m][1][n]);
    }
    return 0;
}
