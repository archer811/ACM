#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll long long
struct array
{
    ll x,y;
}s[50005];
const ll inf = 2000000000;
ll sx,sy;
ll g(ll x,ll y)
{
    x = x-sx;
    y = y-sy;
    if(x*y%2)return x*y/2+1;
    else return x*y/2;
}
ll f(ll a,ll b,ll c,ll d)
{
    ll t = (c-a)*(d-b);

    if((t%2&&(a+b)%2==0))return t/2+1;
    else return t/2;
}
int main()
{
    int i,j,n;
    int a,b,c,d;
//    while(cin>>a>>b>>c>>d)
//    {
//        cout<<f(a,b,c,d)<<endl;
//    }
    while(scanf("%d",&n)!=EOF)
    {
        ll sx = inf, sy = inf;
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&s[i].x,&s[i].y);
            if(sx>s[i].x)sx=s[i].x;
            if(sy>s[i].y)sy=s[i].y;
        }
        if((sx+sy)%2)sx--;
        s[n]=s[0];
        long long bsum=0,sum=0;
//        cout<<sx<<" "<<sy<<endl;
        for(i=1;i<=n;i++)
        {
            if(s[i].x==s[i-1].x&&s[i].y>=s[i-1].y)//up
            {
                bsum += f(sx,s[i-1].y,s[i].x,s[i].y);
                //cout<<f(sx,s[i-1].y,s[i].x,s[i].y)<<"up"<<endl;
                sum += s[i].x*(s[i].y-s[i-1].y);
            }
            else if(s[i].x==s[i-1].x&&s[i].y<s[i-1].y)//down
            {
                bsum -= f(sx,s[i].y,s[i-1].x,s[i-1].y);
                //cout<<f(sx,s[i].y,s[i-1].x,s[i-1].y)<<"down"<<endl;
                sum -= s[i].x*(s[i-1].y-s[i].y);
            }
            else if(s[i].x>=s[i-1].x&&s[i].y==s[i-1].y)//right
            {
                bsum -= f(s[i-1].x,sy,s[i].x,s[i].y);
               // cout<<f(s[i-1].x,sy,s[i].x,s[i].y)<<"right"<<endl;
                sum -= s[i].y*(s[i].x-s[i-1].x);
            }
            else if(s[i].x<s[i-1].x&&s[i].y==s[i-1].y)//left
            {
                bsum += f(s[i].x,sy,s[i-1].x,s[i-1].y);
               // cout<< f(s[i].x,sy,s[i-1].x,s[i-1].y)<<"left"<<endl;
                sum += s[i].y*(s[i-1].x-s[i].x);
            }
        }
        printf("%lld %lld\n",bsum/2,sum/2-bsum/2);
    }
}
