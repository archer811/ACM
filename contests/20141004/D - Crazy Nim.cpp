#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
int vis[100][100][100];
int dfs(int a,int b,int c)
{
    int i;
    int f=0;
    if(vis[a][b][c]!=-1)return vis[a][b][c];
    for(i=0;i<a;i++)
    {
        if(i!=b&&i!=c&&b!=c)
        {
            if(dfs(i,b,c)==0)f=1;
        }
    }
    for(i=0;i<b;i++)
    {
        if(i!=a&&i!=c&&a!=c)
        {
            if(dfs(a,i,c)==0)f=1;
        }
    }
    for(i=0;i<c;i++)
    {
        if(i!=a&&i!=b&&a!=b)
        {
            if(dfs(a,b,i)==0)f=1;
        }
    }
    if(f)return vis[a][b][c]=1;
    return vis[a][b][c]=0;
}
int judge(int x)
{
    while(x)
    {
        if((x&1)==0)return 0;
        x/=2;
    }
    return 1;
}
int f(int a,int b,int c)
{
    if(a>b)swap(a,b);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    return c-(a+b);
}
int main()
{
    int i,j;
    freopen("out.txt","w",stdout);
    memset(vis,-1,sizeof(vis));
    vis[0][0][0]=0;
    for(i=1;i<=99;i++)
    {
        for(j=1;j<=99;j++)
        {
            for(int k=1;k<=99;k++)
            {
                if(i!=j&&i!=k&&j!=k)
                {
                    if(vis[i][j][k]==-1)
                        dfs(i,j,k);
                    int s=0;
                    if(i&1)s++;
                    if(j&1)s++;
                    if(k&1)s++;
                    if(vis[i][j][k]&&(i^j^k)==0)
                    cout<<i<<" "<<j<<" "<<k<<" "<<(i^j^k)<<endl;
                }
            }
        }
    }
    return 0;
}
