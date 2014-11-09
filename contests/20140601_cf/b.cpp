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
const int maxn = 100005;
struct arar
{
    int x,y,ss;
}s[maxn];
int w[maxn];
int cmp(arar a,arar b)
{
    return a.ss>b.ss;
}
int f[maxn],num[maxn];
#define ll long long
int find(int x)
{
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void add(int u,int v)
{
    f[v]=u;
    num[u]+=num[v];
}
struct Edge
{
    int u,v;
    Edge(){};
    Edge(int uu,int vv){u=uu;v=vv;};
};
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int>G[maxn],bcc[maxn];
stack<Edge>S;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int child=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        Edge e = (Edge){u,v};
        if(!pre[v])
        {
            S.push(e);
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])
            {
                iscut[u]=true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;)
                {
                    Edge x=S.top();S.pop();
                    if(bccno[x.u]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u]=bcc_cnt;
                    }
                    if(bccno[x.v]!=bcc_cnt)
                    {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v]=bcc_cnt;
                    }
                    if(x.u==u&&x.v==v)break;
                }
            }
        }
        else if(pre[v]<pre[u] && v!=fa)
        {
            S.push(e);
            lowu = min(lowu,pre[v]);
        }
    }
    if(fa<0&&child==1)iscut[u]=0;
    return lowu;
}
void find_bcc(int n)
{
    memset(pre,0,sizeof(pre));
    memset(iscut,0,sizeof(iscut));
    memset(bccno,0,sizeof(bccno));
    dfs_clock=bcc_cnt=0;
    for(int i=1;i<=n;i++)
        if(!pre[i])dfs(i,-1);
}
const int inf =0x3fffffff;
int l[maxn];
map<pair<int,int>,int>M;
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        M.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            f[i]=i;num[i]=1;
            G[i].clear();
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&s[i].x,&s[i].y);
            if(s[i].x>s[i].y)swap(s[i].x,s[i].y);
            s[i].ss=min(w[s[i].x],w[s[i].y]);
            G[s[i].x].push_back(s[i].y);
            G[s[i].y].push_back(s[i].x);
            M[make_pair(s[i].x,s[i].y)]=i;
        }
        /*
        find_bcc(n);
        for(i=1;i<=bcc_cnt;i++)
            l[i]=inf;
        //cout<<bcc_cnt<<endl;
        for(i=1;i<=bcc_cnt;i++)
        {
            for(j=0;j<bcc[i].size();j+=2)
            {
                int x=bcc[i][j],y=bcc[i][j+1];
                if(x>y)swap(x,y);
                int tmp = M[make_pair(x,y)];
                //cout<<bcc[i][j]<<" "<<bcc[i][j+1]<<tmp<<endl;
                l[i]=min(l[i],s[tmp].ss);
            }
           // cout<<i<<" "<<l[i]<<endl;
            //cout<<endl;
        }*/
        sort(s,s+m,cmp);
        double sum=0;
        for(i=0;i<m;i++)
        {
            int a=s[i].x,b=s[i].y;
            int x = find(a),y=find(b);
            if(x==y)continue;
            sum += num[x]*num[y]*(double)s[i].ss/(double)n/(double)(n-1)*2;
            add(x,y);
        }
        printf("%.4f\n",sum);
    }
    return 0;
}
