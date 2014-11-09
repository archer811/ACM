#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int N=10000000;
const ll inf = 999999999;
int F[N+15];
int cnt_1[N+15];
int cnt_2[N+15];
ll S[N+15];
ll x,y;
int n;
void init()
{
    S[2]=0;
    int i,j,k;
    for (i=2; i<=N; i++)
    {
        if (cnt_1[i]==0)
        {
            F[i]=i;
            cnt_1[i]=1;
        }

        for (j=2,k=i+i; j<=F[i]; j++,k+=i)
        {
            if (k>N) break;
            F[k]=j;
            cnt_2[k]=cnt_2[i]+(j==F[i]);  //计算k有多少个i^2形式的因子
            cnt_1[k]=cnt_1[i]+1;    //计算k有多少个因子。
        }

        int t;
        int &c1=cnt_1[i];
        int &c2=cnt_2[i];
        if (c2==0)
            if (c1&1)
                t=c1;
            else
                t=-c1;
        else if (c2==1) t=( (c1&1)?1:-1 );
        else t=0;
        S[i+1]=S[i]+t;
    }
}
ll _min(ll a,ll b)
{
    if(a<b)return a;
    return b;
}
int main()
{
    int i,j,k;
    ll ans;
    ll now;
    init();
    scanf("%d",&n);
    while(n--)
    {
        //cin>>x>>y;
        scanf("%lld%lld",&x,&y);
        ans =0;
        i = 1;
        while(i<=x||i<=y)
        {
            now = inf;
            if(i<=x)now = _min(now,x/(x/i));
            if(i<=y)now = _min(now,y/(y/i));
            //cout<<now<<endl;
            ans = ans + (x/now)*(y/now)*(S[now+1]-S[i]);
            i=now+1;
        }
        printf("%lld\n",ans);
        //cout<<ans<<endl;
    }
}


