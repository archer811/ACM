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
int a[100005];
map<int,int>M;
int vis[100005];
int a2,b;
map<int,int>N;
const int maxn = 100005;
int ans[maxn];
int ok;
int judge(int x,int g,int g2,int o)
{
    ok=0;
    ans[ok++]=x;
    static int id;
    id++;
    N[x]=id;
    for(int i=0;i<ok;i++)
    {
        int x2 = ans[i];
        int y = g-x2;
        if(M[y]==0)return 0;
        if(N[y]!=id)
        {
            N[y]=id;
            ans[ok++]=y;
        }
        int t1 = g2-x2;
        int t2 = g2-y;
        if(M[t1])
        {
            if(N[t1]!=id)
            {
                N[t1]=id;
                ans[ok++]=t1;
            }
        }
        if(M[t2])
        {
            if(N[t2]!=id)
            {
                N[t2]=id;
                ans[ok++]=t2;
            }
        }
    }
    for(int i=0;i<ok;i++)
    {
        vis[M[ans[i]]]=o;
    }
    return 1;
}
int main()
{
    int i,j,n;
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&a2,&b)!=EOF)
    {
        M.clear();
        N.clear();
        memset(vis,-1,sizeof(vis));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            // cout<<a[i]<<endl;
            M[a[i]]=i;
        }
        int flag=0;
        for(i=1; i<=n; i++)
        {
            if(vis[i]!=-1)continue;
            if(!judge(a[i],a2,b,0)&&!(judge(a[i],b,a2,1)))
            {
                flag=1;
                break;
            }
        }
        if(flag)puts("NO");
        else
        {
            puts("YES");
            for(i=1; i<=n; i++)
                cout<<vis[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

