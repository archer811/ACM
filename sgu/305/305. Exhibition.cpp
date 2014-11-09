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
#define ll long long
const int MAXN=910;
int uN,vN;//u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)//从左边开始找增广路径
{
    int v;
    for(v=1; v<=vN; v++) //这个顶点编号从0开始，若要从1开始需要修改
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                //找增广路，反向
                linker[v]=u;
                return true;
            }
        }
    return false;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=1; u<=uN; u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
int a,b;
ll value[MAXN];
int ans[MAXN];
map<ll,int>M;
int tot;
void func(ll tmp,int i)
{
    if(M[tmp]==0)
    {
        M[tmp]=tot++;
        value[tot-1]=tmp;
    }
    int f = M[tmp];
    //cout<<i<<" * "<<f<<endl;
    g[i][f]=1;
}
map<int,int>N;

int main()
{
    int i,j;
    scanf("%d%d",&a,&b);
    {
        tot=1;
        M.clear();
        N.clear();
        memset(g,0,sizeof(g));
        for(i=1; i<=a; i++)
        {
            ll x,y;
            ans[i]=-1;
            scanf("%lld%lld",&x,&y);

            if(x==0)
            {
                if(y>=1&&y<=b)
                    func(y,i);
            }
            else if(x<0)
            {
                ll tp = (1-y)/x;
                //cout<<tp<<endl;
                tp = max(tp,(ll)0);
                while(tp>=0&&x*tp+y<1)tp--;
                for(j=0; j<=a&&tp>=0; j++,tp--)
                {
                    ll tmp = x*tp+y;
                    if(tmp<=b&&tmp>=1)
                        func(tmp,i);
                }
            }
            else
            {
                ll tp = (1-y)/x;
                tp = max(tp,(ll)0);
                while(x*tp+y<1)tp++;
                for(j=0; j<=a; j++,tp++)
                {
                    ll tmp = x*tp+y;
                    //cout<<tp<<"*"<<tmp<<endl;
                    if(tmp>=1&&tmp<=b)
                        func(tmp,i);
                }
            }
        }
        uN=a;
        vN=tot-1;
        hungary();
        for(i=1; i<=tot-1; i++)
        {
            if(linker[i]!=-1)
            {
                ans[linker[i]]=value[i];
                N[value[i]]=1;
            }

        }
        j = 1;
        for(i=1; i<=a; i++)
        {
            if(ans[i]==-1)
            {
                while(N.count(j))j++;
                ans[i]=j;
                j++;
            }
        }
        for(i=1; i<=a; i++)
        {
            if(i==1)printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}

