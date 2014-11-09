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
#define ll long long
int n,m;
const int maxn = 51000;
int c[maxn],a[maxn];
struct array
{
    int x,y,index;
} s[maxn];
int M;
int cmp(array a,array b)
{
    if(a.x/M!=b.x/M)return a.x/M<b.x/M;
    return a.y<b.y;
}
struct T
{
    ll x,y;
} ans[maxn];
ll sum;
void add(int x)
{
    x = c[x];
    sum -= (ll)(a[x])*(ll)(a[x]-1);
    a[x]++;
    sum += (ll)(a[x])*(ll)(a[x]-1);
}
void de(int x)
{
    x = c[x];
    sum -= (ll)(a[x])*(ll)(a[x]-1);
    a[x]--;
    sum += (ll)(a[x])*(ll)(a[x]-1);
}
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    {
        M = sqrt(n*1.0);
        for(i=1; i<=n; i++)
            scanf("%d",&c[i]);
        memset(a,0,sizeof(a));
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&s[i].x,&s[i].y);
            s[i].index=i;
        }
        sum=0;
        sort(s,s+m,cmp);
        for(i=s[0].x; i<=s[0].y; i++)
        {
            //cout<<c[i]<<"("<<endl;
            a[c[i]]++;
        }
        for(i=1; i<=n; i++)
        {
            //cout<<a[i]<<endl;
            if(a[i])
                sum += (ll)(a[i])*(ll)(a[i]-1);
        }
        //cout<<sum<<endl;
        ans[s[0].index].x=sum;
        if(sum==0)ans[s[0].index].y=1;
        else
        {
            ll tmp3 = s[0].y-s[0].x+1;

            ll tmp2 = tmp3*(tmp3-1);
            //cout<<tmp2<<endl;
            ll tmp = gcd(sum,tmp2);
            ans[s[0].index].x=sum/tmp;
            ans[s[0].index].y=tmp2/tmp;
        }
        int prex=s[0].x,prey=s[0].y;
        for(i=1; i<m; i++)
        {
            //cout<<s[i].x<<" "<<s[i].y<<endl;
            while(s[i].y>prey)
            {
                add(prey+1);
                prey++;
            }
            while(s[i].y<prey)
            {
                de(prey);
                prey--;
            }
            while(s[i].x>prex)
            {
                de(prex);
                prex++;
            }
            while(s[i].x<prex)
            {
                add(prex-1);
                prex--;
            }
            ll tmp3 = s[i].y-s[i].x+1;
            //cout<<tmp3<<endl;
            ll tmp2 = tmp3*(tmp3-1);
            ll tmp = gcd(sum,tmp2);
            if(sum==0)
                ans[s[i].index].x=0,ans[s[i].index].y=1;
            else
            {
                ans[s[i].index].x=sum/tmp;
                ans[s[i].index].y=tmp2/tmp;
            }

            //cout<<sum<<endl;
        }
        for(i=0; i<m; i++)
        {

             printf("%lld/%lld\n",ans[i].x,ans[i].y);

        }
    }
}
