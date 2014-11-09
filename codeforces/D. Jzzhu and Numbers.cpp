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
const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
#define ll __int64
//const ll linf=1122334455667788990;
int a[maxm];
int f[(1<<20)];
int x[maxm];
struct array
{
    int index,v;
}b[maxm],c[maxm];
int ans[maxm];
const ll mod = 1000000007 ;
const int N = 2;
ll mul(ll x,ll n)
{
    ll b= 1;
    while(n)
    {
        if(n&1)
        b = b*x%mod;
        x = x*x%mod;
        n/=2;
    }
    return b;
}
int main()
{
    int n,i,j;
    int M = (1<<N)-1;
    //cout<<(1^M)<<endl;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(f,0,sizeof(f));
        memset(x,0,sizeof(x));
        memset(ans,0,sizeof(ans));
        for(i=1;i<=n;i++)
        {
            int g=0;
            for(j=0;j<N;j++)
            {
                if((a[i]&(1<<j))==0)
                {
                    g = g|(1<<j);
                }
            }
            //cout<<i<<" "<<g<<endl;
            f[g]++;
        }
//        for(i=0;i<10;i++)
//        {
//            cout<<i<<"*"<<f[i]<<endl;
//        }
        int num=0;
        for(i=0;i<N;i++)
        {
            if(i==0)
            {
                b[num].index=(1<<i);
                b[num++].v=f[(1<<i)^M];
                b[num].index=0;
                b[num++].v=f[0^M];
                ans[0^M]=f[0^M];
                ans[(1<<i)^M]=f[(1<<i)^M];
            }
            else
            {
                int num2=0;
                for(j=0;j<num;j++)
                {
                    int x = b[j].index|(1<<i);
                    ans[x]=b[j].v+f[x];
                    c[num2++]=b[j];
                    c[num2].index=x;
                    c[num2++].v=ans[x];
                }
                num=0;
                for(j=0;j<num2;j++)
                    b[num++]=c[j];
            }
            cout<<i<<endl;
            for(j=0;j<num;j++)
            {
                cout<<j<<"!"<<b[j].index<<" "<<b[j].v<<endl;
            }
        }
        ll ant=0;
        for(i=0;i<=M;i++)
        {
            ant += f[i]*(((mul(2,ans[i])-1)%mod+mod)%mod)%mod;
        }
        cout<<ant<<endl;
    }

    return 0;
}
