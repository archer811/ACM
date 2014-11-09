#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100005;
#define ll long long
ll s[maxn],p[maxn];
ll sum[maxn],Min[maxn];
int main()
{
    int i,j,k,t;
    int n,m;
    scanf("%d",&t);
    ll q;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&s[i],&p[i]);
            sum[i]=(ll)s[i]*(ll)p[i];
        }
        Min[n-1]=sum[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(Min[i+1]<sum[i])
                Min[i]=Min[i+1];
            else Min[i]=sum[i];
        }
        for(i=0;i<m;i++)
        {
            scanf("%lld",&q);
            int tmp = lower_bound(s,s+n,q)-s;
            if(s[tmp]>q)tmp--;
            //cout<<tmp<<endl;
            if(q>=s[n-1])
            {
                printf("%lld\n",q*p[n-1]);
                //cout<<<<endl;
            }
            else
            {
                ll temp = (ll)p[tmp]*(ll)q;
                if(tmp+1<n)tmp++;
                if(Min[tmp]<temp)temp=Min[tmp];
                //cout<<temp<<endl;
                printf("%lld\n",temp);
            }
        }
    }
}
