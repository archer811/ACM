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
struct o
{
    int x,v;
}g[1000005],g2[1000005];
int cmp(o a,o b)
{
    if(a.x==b.x)return a.v>b.v;
    return a.x<b.x;
}
ll num;
ll c[1100006];
int lowbit(int x)
{
    return x&(-x);
}
const int maxn = 1100006;
void add(int x,ll v)
{
    while(x<maxn)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
ll sum(int x)
{
    ll s=0;
    while(x>0)
    {
        s+=c[x];
        //cout<<c[x]<<"*"<<endl;
        x-=lowbit(x);
    }
    //cout<<s<<"()"<<endl;
    return s;
}
ll y[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&g[i].x,&g[i].v);
        }
        sort(g+1,g+1+n,cmp);
        memset(c,0,sizeof(c));
        num=0;
        j=1;
        for(i=1;i<=n;i++)
        {
            if(i==1||(!(g[i].x==g[i-1].x&&g[i].v==g[i-1].v)))
            {
                g2[j++]=g[i];
                y[j-1]=1;
            }
            else
                y[j-1]++;
        }
        for(i=j-1;i>=1;i--)
        {
            //cout<<sum(g2[i].v-1)<<endl;
            num += sum(g2[i].v-1);
            add(g2[i].v,y[i]);
            num += y[i]*(y[i]-1)/2;
           // cout<<g2[i].x<<" "<<g2[i].v<<" "<<y[i]<<endl;

        }

        printf("%lld\n",num);
    }
    return 0;
}
