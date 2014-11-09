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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
ll d[10][522][30];
int len[(1<<10)];
int main()
{
    int i,j;
    int n,K;
    int N = 1<<10;
    for(i=0; i<N; i++)
    {
        if(i&1)len[i]=len[i/2]+1;
        else len[i]=len[i/2];
    }
    while(scanf("%d%d",&n,&K)!=EOF)
    {
        memset(d,0,sizeof(d));
        d[0][0][0]=1;
        int M = 1<<n;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<M; j++)
            {
                for(int k=0; k<=K; k++)
                {
                    if(d[i-1][j][k]==0)continue;
                    for(int t=0; t<M; t++)
                    {
                        if(t&j)continue;
                        int x = t<<1;
                        if(x&j)continue;
                        if(x&t)continue;
                        x = t>>1;
                        if(x&j)continue;
                        if(x&t)continue;

                        if(k+len[t]>K)continue;

//                        if(d[i][j|t][k+len[t]]==-1)
//                            d[i][j|t][k+len[t]] = d[i-1][j][k];
//                        else
                            d[i][t][k+len[t]]+=d[i-1][j][k];
//                        if(d[i][t][k+len[t]]>0&&k+len[t]==2)
//                            cout<<i<<" "<<j<<" "<<t<<" "<<k+len[t]<<
//                            " ** "<<d[i][t][k+len[t]]<<endl;
                    }
                }

            }
        }
        ll sum=0;
        for(i=0;i<M;i++)
        {
            sum += d[n][i][K];
        }

        printf("%lld\n",sum);
    }
    return 0;
}
