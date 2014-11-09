#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int c[51016];
const int maxn = 51015;
int lowbit(int x)
{
    return x&(-x);
}
int tot;
void add(int x,int val)
{
    while(x <= tot)
    {
        c[x] += val;
        x += lowbit(x);
    }
}
int getsum(int x)//Çósum(x)
{
    int result = 0;
    while(x > 0)
    {
        result += c[x];
        x -= lowbit(x);

    }
    return result;
}
vector<int>g[maxn];
int n;
struct array
{
    int index,num;
}ans[maxn];
int cmp(array x,array y)
{
    return x.num<y.num;
}
int a[maxn],b[maxn],gg[maxn];
void dfs(int u)
{
    int i,j;
    int pre = getsum(tot)-getsum(a[u]);
    //cout<< u << " ()()( "<<getsum(tot) << " "<<getsum(a[u])<<endl;
    for(i=0;i<g[u].size();i++)
    {
        int v  = g[u][i];
        dfs(v);
    }
    add(a[u],1);
    int now = getsum(tot)-getsum(a[u]);
    b[u]=now-pre;
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            g[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d",&j);
            g[j].push_back(i);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&ans[i].num);
            ans[i].index=i;
        }
        tot=1;
        sort(ans,ans+n,cmp);
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                a[ans[i].index]=tot++;
                continue;
            }
            if(ans[i].num!=ans[i-1].num)
            {
                a[ans[i].index]=tot++;
            }
            else a[ans[i].index]=tot-1;
            //cout<<i<< " "<<ans[i].index<<   " " <<ans[i].num<<endl;
        }
        //for(i=0;i<n;i++)
         //   cout<<a[i]<<endl;
        memset(c,0,sizeof(c));
        dfs(0);
        for(i=0;i<n;i++)
        {
            if(i==0)printf("%d",b[i]);
            else printf(" %d",b[i]);
        }
        puts("");
    }
}
