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
#define ll __int64
ll num,k;
int a[100005];
ll x;
struct node
{
    ll v;
    ll tmp;
} now,next;
ll val[100005];
int main()
{
    //freopen("out.txt","w",stdout);
    a[1]=a[0]=1;
    for(int i=2; i<=100000; i++)
    {
        if(a[i]==0)
        {
            for(int j=i+i; j<=100000; j+=i)
                a[j]=1;
        }
    }
    while(scanf("%I64d%I64d",&x,&k)!=EOF)
    {
        if(x==1)
        {
            printf("1\n");
            continue;
        }
        if(k>(ll)100000)k=100000;
        int gg=0;
        ll y2=sqrt(x);
        for(ll i=2; i<=y2; i++)
        {
            if(x%i==0)
            {
                gg=1;
                break;
            }
        }
        num=0;
        //cout<<gg<<endl;
        if(gg==0)
        {
            int tt=0;
            while(tt<k)
            {
                num++;
                // cout<<num<<"*"<<endl;
                if(num>100000)break;
                printf("1 ");
                tt++;
            }
            num++;
            if(num>100000);
            else
                printf("%I64d ",x);
            continue;
        }
        //cout<<x<<endl;
        int myans=0;
        for(ll i=1; i<=y2; i++)
        {
            if(x%i==0)
            {
                val[myans++]=x/i;
            }
        }
        if(y2*y2==x)
            y2--;
        for(ll i=y2; i>=1; i--)
        {
            if(x%i==0)
            {
                val[myans++]=i;
            }
        }


        stack<node>s;
        now.v=x;
        now.tmp=0;
        s.push(now);
        while(num<100000)
        {
            if(s.empty())break;
            //cout<<num<<"()"<<endl;
            now = s.top();
            s.pop();
            ll u = now.v;
            ll y = sqrt(u);
            ll tt=now.tmp;
            //cout<<u<<"***"<<tt<<endl;
            //cout<<u<<"**"<<tt<<"  "<<y<<endl;
            if(tt>=k)
            {
                num++;
                printf("%I64d ",u);
                continue;
            }
            if(num>=100000)continue;
            if(u==1)
            {
                num++;
                printf("1 ");
                continue;
            }
            if(num>=100000)continue;
            if(u<=100000&&a[u]==0)
            {
                //cout<<u<<endl;
                while(tt<k)
                {
                    num++;
                    // cout<<num<<"*"<<endl;
                    if(num>100000)break;
                    printf("1 ");
                    tt++;
                }
                num++;
                if(num>100000)continue;
                printf("%I64d ",u);
                continue;
            }

            if(num>=100000)continue;
           // cout<<"ok"<<u<<endl;
            //for(int i=myans-1;i>=0;i--)
            for(int i=0;i<myans;i++)
            {
                if(u%val[i]==0)
                {
                    next.v=val[i];

                    next.tmp=now.tmp+1;
                    s.push(next);
                }
            }
        }
        puts("");
    }
    return 0;
}
