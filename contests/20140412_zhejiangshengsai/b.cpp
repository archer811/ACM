#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int p[20][20];
#define ll long long
ll d[4100][505];
vector<int>g[13];
int num[4100];
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,k,t;
    for(i=0; i<=12; i++)
        g[i].clear();
    for(i=0; i<4096; i++)
    {
        if(i&1)
            num[i]=num[i/2]+1;
        else num[i]=num[i/2];
        g[num[i]].push_back(i);
    }
//    for(i=0;i<=12;i++)
//    {
//        cout<<g[i].size()<<endl;
//        for(j=0;j<g[i].size();j++)
//            cout<<g[i][j]<<" ";
//        cout<<endl;
//    }
    scanf("%d",&t);
    int n,m;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                scanf("%d",&p[i][j]);
        }
        memset(d,-1,sizeof(d));
        d[0][0]=1;
        int index=0;
        int M = 1<<(n);
        for(i=1; i<=n; i++)
        {
            for(j=0; j<g[i-1].size(); j++)
            {
                //cout<<i<<" "<<g[i-1][j]<<endl;
                if(g[i-1][j]>=M)break;
                for(k=1; k<=n; k++)
                {
                    if(g[i-1][j]&(1<<(k-1)))continue;

                    for(int s=0; s<=500; s++)
                    {

                        if(d[g[i-1][j]][s]==-1)continue;
                        //cout<<g[i-1][j]<<" "<<k<<" "<<s<<endl;
                        int dd = min(m+1,s+p[i][k]);

                        if(d[g[i-1][j]|(1<<(k-1))][dd]==-1)
                            d[g[i-1][j]|(1<<(k-1))][dd]=d[g[i-1][j]][s];
                        else
                            d[g[i-1][j]|(1<<(k-1))][dd]+=d[g[i-1][j]][s];
                        //cout<<dd<<"*"<<(g[i-1][j]|(1<<(k-1)))<<"  "<<
                        // d[g[i-1][j]|(1<<(k-1))][dd]<<endl;
                    }
                }
            }
        }
        ll sum=0,sum2=0;
        for(j=0; j<=m+1; j++)
        {
            if(d[M-1][j]!=-1)
                sum += d[M-1][j];
            if(d[M-1][j]!=-1&&j>=m)
                sum2 += d[M-1][j];
        }
        if(sum2==0)puts("No solution");
        else
        {
            ll x = gcd(sum,sum2);
            printf("%lld/%lld\n",sum/x,sum2/x);
        }

    }

}

