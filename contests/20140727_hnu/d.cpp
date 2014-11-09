#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=11000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;
struct array
{
    int a,x,y;
}now;


vector<array>v[maxm];
int vis[maxm];

int ans[maxm];
struct oo
{
    int val,index;
    friend bool operator < (oo x,oo y)
    {
        return x.val>y.val;
    }
}t;

int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        priority_queue<oo>q;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        {
            v[i].clear();
            scanf("%d",&ans[i]);
            t.val=ans[i];
            t.index=i;
            q.push(t);
        }
        for(i=0;i<m;i++)
        {
            int a,x,y;
            scanf("%d%d%d",&a,&x,&y);
            now.a=a;now.x=x;now.y=y;
            v[x].push_back(now);
            now.a=a;now.x=y;now.y=x;
            v[y].push_back(now);
        }
        int sum=0;
        while(!q.empty())
        {
            t = q.top();q.pop();
            int x = t.index;
            if(vis[x])continue;
            sum++;
            if(sum>=n)break;
            int len=v[x].size();
vis[x]=1;

            for(i=0;i<len;i++)
            {
                int y = v[x][i].y;
                int a = v[x][i].a;
                if(vis[a])continue;
                if(ans[a]>ans[y]+ans[x])
                {
                    ans[a]=ans[y]+ans[x];
                    oo t2;
                    t2.val=ans[a];
                    t2.index=a;
                    q.push(t2);
                }
            }
            vis[x]=1;
        }
        printf("%d\n",ans[1]);

    }
    return 0;
}
