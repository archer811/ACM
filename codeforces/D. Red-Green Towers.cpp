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
const ll mod = 1000000007;
const int maxn = 200005;
ll d[2][maxn];
int main()
{
    ll i,j,r,g;
    while(scanf("%I64d%I64d",&r,&g)!=EOF)
    {
        memset(d,0,sizeof(d));
        int now=1,pre=0;
        ll ans=0;
        if(r)
            d[0][1]=1;
        if(g)
            d[0][0]=1;
        ans = max(ans,d[0][1]+d[0][0]);
        for(i=2;i*(i+1)/2<=r+g;i++)
        {
            ll sum=0;
            int flag=0;
            for(j=min(r,i*(i+1)/2);j>=0;j--)
            {
                //cout<<j<<":"<<endl;
                if(j>=i)
                {
                    int tmp = i*(i+1)/2-j;
                    if(tmp>=0&&tmp<=g)
                    {
                        //cout<<tmp<<endl;
                        d[now][j]+=d[pre][j-i];
                        if(d[now][j]>mod)
                            d[now][j]-=mod;
                    }
                }
                int tmp = i*(i+1)/2-j;
                //cout<<i*(i+1)/2<<"*"<<j<<" "<<tmp<<endl;
                if(tmp>=0&&tmp<=g)
                {
                    d[now][j]+=d[pre][j];
                    if(d[now][j]>mod)
                        d[now][j]-=mod;
                }
                d[pre][j]=0;
                if(d[now][j]!=0)
                {
                    flag=1;
                    sum+=d[now][j];
                    if(sum>mod)
                        sum-=mod;
                }
            }
            if(flag)ans=sum;
            now^=1;
            pre^=1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
200000 200000


*/
