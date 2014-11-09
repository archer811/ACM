#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn=200010;

int first[maxn],nxt[maxn],vv[maxn],siz[maxn];
int low[maxn],ran[maxn],ind,N;
long long ans;

vector<int>V;
void dfs(int n,int ee)
{
    low[n]=ran[n]=++ind;

    int t=0;
    for(int e=first[n]; e; e=nxt[e])
        if(e-ee)
        {
            int v=vv[e];
            if(!ran[v])
            {
                dfs(v,e^1);
                if(low[v]>=ran[n])
                {
                    V.push_back(siz[v]);
                    //printf("%d %d  %d\n",n,v,siz[v]);
                    t+=siz[v];
                    //printf("%d++++++++++\n",n);
                }
                low[n]=min(low[n],low[v]);
                siz[n]+=siz[v];
            }
            else
                low[n]=min(low[n],ran[v]);
        }
    siz[n]++;
    //printf("%d (( %d\n",n,t);
    V.push_back(t);
    N++;
}
int main()
{
    int t,ii=0,n,m,i,j,k,u,v,e;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        e=2;
        memset(first,0,sizeof(first));

        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            nxt[e]=first[u],vv[e]=v,first[u]=e++;
            nxt[e]=first[v],vv[e]=u,first[v]=e++;
        }
        ans=0,N=n;

        memset(siz,0,sizeof(siz));
        memset(ran,0,sizeof(ran));
        ind=0;

        for(i=1; i<=n; i++)if(!ran[i])
        {
                V.clear();
                N=0;
                dfs(i,0);
//                for(j=1; j<=n; j++)
//                    printf("%d\n",siz[j]);
//                for(j=0; j<V.size(); j++)
//                    printf("%d () %d\n",j,V[j]);
                //printf("%d\n",N);
                for(j=0; j<V.size(); j++)
                {
                    //printf("%d %d\n",V[j],N-1-V[j]);
                    ans+=V[j]*(N-V[j]-1);
                }

            }
        printf("Case %d: %lld\n",++ii,ans);
    }
}
