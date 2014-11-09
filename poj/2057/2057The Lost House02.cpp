#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int N = 1010;
int tree[N][N];
int leaves[N];
int worm[N];
int suc[N];
int fal[N];
void init()
{
    memset(tree,0,sizeof(tree));
    memset(suc,0,sizeof(suc));
    memset(worm,0,sizeof(worm));
    memset(fal,0,sizeof(fal));
    memset(leaves,0,sizeof(leaves));
}
int n;
int tmp[N];
int cmp(int a,int b)
{
    return  (fal[a]+2)*leaves[b]<(fal[b]+2)*leaves[a];
}
void dfs(int now)
{
    if(tree[now][0]==0)
    {
        suc[now]=fal[now]=0;
        leaves[now]=1;
        return;
    }
    int i,j,k;
    for(i=0;i<tree[now][0];i++)
    {
        dfs(tree[now][i+1]);
    }
    for(i=0;i<tree[now][0];i++)
    {
        leaves[now]+=leaves[tree[now][i+1]];
        if(worm[now]==0)
        {
            fal[now]+=fal[tree[now][i+1]]+2;
        }
        tmp[i]=tree[now][i+1];
    }
    //cout<<now<<" "<<leaves[now]<<endl;
    k =0;
    sort(tmp,tmp+tree[now][0],cmp);
    for(i=0;i<tree[now][0];i++)
    {
        suc[now]+=(k+1)*leaves[tmp[i]]+suc[tmp[i]];
        k += fal[tmp[i]]+2;
    }
}
int main()
{
    int i,j,k;
    int a;
    char c[2];
    while(scanf("%d",&n)&&n)
    {
       init();
       for(i=1;i<=n;i++)
       {
           scanf("%d%s",&a,&c);
           if(a!=-1)
              tree[a][++tree[a][0]]=i;
           if(c[0]=='Y')
              worm[i]=1;
       }
       dfs(1);
       printf("%.4f\n",(double)suc[1]*1.0/leaves[1]);
    }
}
