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
#define ll unsigned long long
const int maxn = 5000006;
ll phi[maxn];
const int N= 5000000;
void ruler()
{
    int i,j;
    for (i = 1; i <= N; i++) phi[i] = i;
    for (i = 2; i <= N; i += 2) phi[i] /= 2;
    for (i = 3; i <= N; i += 2)
        if(phi[i] == i)
        {
            for (j = i; j <= N; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
}
ll ans[maxn],sum[maxn];
int g[maxn],g2[maxn];
int main()
{
    int i,j;
    ruler();
    ans[0]=0;
    sum[0]=0;
    for(i=1; i<=N; i++)
    {
        phi[i] = (ll)i*(ll)phi[i]/2;
        phi[i] *= (ll)i;
        sum[i] = sum[i-1]+phi[i];
//        if(i<=10)
//            cout<<i<<"*"<<phi[i]<<endl;
    }
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ll anssum=0;


        int L,R;
        L=R=1;
        ll cur=1;
        while(L<=n)
        {
            ll ret=n/cur;
            R=n/ret;
            if(R>=n) R=n;
            ll tmp = (1+ret)*ret/2;
            anssum+=(sum[R]-sum[L-1])*tmp;
            //cout<<ret<<" "<<tmp<<" "<<(sum[R]-sum[L-1])<<endl;
            L=R+1;
            cur=L;
        }
        //cout<<anssum<<endl;
//
//
//        for(i=1; i<=n; i++)
//        {
//            ll tmp = n/i;
//            tmp = (1+tmp)*tmp/2;
//            cout<<n/i<<" "<<tmp<<"()"<<phi[i]<<endl;
//            //anssum += tmp*phi[i];
//
//        }
        printf("Case %d: ",++cas);
        cout<<anssum<<endl;
    }

    return 0;
}


