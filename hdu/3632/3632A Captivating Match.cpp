#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
int w[101];
vector<int>g[101];
int num;
int vis[101];
int judge(int l,int r,int a)
{
    if(l+1==r)
    {
        for(int i=0;i<g[a].size();i++)
        {
            int j=g[a][i];
            if(j>=l&&j<=r)return 1;
        }
        return 0;
    }
    int num1=0,num2=0;
     for(int i=0;i<g[a].size();i++)
     {
         int j =g[a][i];
         if(j>=l&&j<=a-1)
            if(judge(l,a-1,j))num1=1;
         if(num1)break;
     }
     for(int i=0;i<g[a].size();i++)
     {
         int j =g[a][i];
         if(j>=a+1&&j<=r)
            if(judge(a+1,r,j))num2=1;
         if(num2)break;
     }
     if(a-1<l)num1=1;
     if(a+1>r)num2=1;
     if(num1&&num2)return 1;
     return 0;
}
struct array
{
    int a,num;
}s[101];
int cmp(array x,array y)
{
    return x.num>y.num;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            s[i].a=i;
            scanf("%d",&s[i].num);
        }
        sort(s+1,s+1+n,cmp);
        for(i=1;i<=n;i++)
        {
            g[i].clear();
            for(j=1;j<=n;j++)
            {
                scanf("%d",&k);
                if(k)g[i].push_back(j);
            }
        }
        printf("Case %d: ",++cas);
        for(i=1;i<=n;i++)
        {
            if(judge(1,n,s[i].a))
            {
                printf("%d\n",s[i].num);break;
            }
        }
    }
}
