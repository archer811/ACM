#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 200005;
#define ll __int64
ll sum[maxn],s2[maxn];
struct array
{
    int a,b,x;
}s[maxn];
int cmp(array f,array e)
{
    return f.x<e.x;
}
const ll inf = ((ll)1)<<40;
int main()
{
    int i,j,n,m;
    while(cin>>n>>m)
    {
        memset(sum,0,sizeof(sum));
        memset(s2,0,sizeof(s2));
        int t=0;
        for(i=0;i<n;i++)
        {
            cin>>j;
            s[t].a=1;s[t].b=0;s[t++].x=j;
        }
        for(i=0;i<m;i++)
        {
            cin>>j;
            s[t].a=0;s[t].b=1;s[t++].x=j;
        }
        sort(s,s+t,cmp);
        ll num=0;
        int mark=0;
        for(i=0;i<t;i++)
        {
            if(mark==0&&s[i].a==0)continue;
            //cout<<i<<"&"<<endl;
            if(mark==0)sum[i]=0,mark=1;
            else
                sum[i]=sum[i-1]+num*(ll)(s[i].x-s[i-1].x);
            //cout<<i<<" "<<s[i].x<<" "<<sum[i]<<endl;
            if(s[i].a==1)num++;
        }
        num=0;
        mark=0;
        for(i=t-1;i>=0;i--)
        {
            if(mark==0&&s[i].b==0)continue;
            //cout<<i<<"*"<<endl;
            if(mark==0)
                s2[i]=0,mark=1;
            else
                s2[i]=s2[i+1]+num*(ll)(s[i+1].x-s[i].x);
            if(s[i].b==1)num++;
            //cout<<i<<"   "<<s[i].x<<"  "<<s2[i]<<endl;
        }
        ll ans=-1;
        for(i=0;i<t;i++)
        {
            if(sum[i]+s2[i]<ans||ans==-1)ans=sum[i]+s2[i];
            //cout<<i<<" "<<sum[i]<<"  "<<s2[i]<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
