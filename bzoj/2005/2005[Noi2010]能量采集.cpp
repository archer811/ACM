#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
long long n,m;
bool tp[1000001];
long long prime[1000001],s[1000001],u[1000001];
long long pn,t;
long long ans,now;
void init()
{
    long long i,j;
    pn=0;
    memset(tp,0,sizeof(tp));
    for(i=2;i<=1000000;i++)
    {
        if(!tp[i])
        {
            pn++;prime[pn]=i;
            u[i]=-1;
        }
        for(j=1;j<=pn;j++)
        {
            if(i*prime[j]>1000000)break;
            tp[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                u[i*prime[j]]=0;break;
            }
            else
            u[i*prime[j]]=-u[i];
        }
    }
    u[1]=1;
    s[0]=0;
    for(i=1;i<=1000000;i++)
        s[i]=s[i-1]+u[i];
}
long long _min(long long a,long long b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int T;
    long long i,j,k,sum;
    init();
    while(cin>>n>>m)
    {
        i=1;ans=0;
        k = _min(n,m);
        sum =0;
        for(j=1;j<=k;j++)
        {
            i=1;ans=0;
            while(i<=k)
            {
                now = k/(k/i);
                ans += ((j/i+1)*(j/i+1)-1)*(s[now]-s[i-1]);
                i=now+1;
            }
            cout<<ans << " "<<j<<endl;
            sum += ans*j;
        }

        cout<<sum<<endl;
    }
}
