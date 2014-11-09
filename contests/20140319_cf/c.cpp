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
const int maxn = 100005;
int d[maxn];
struct array
{
    int x,y;
}s[maxn*12];
struct ar
{
    int num,dis;
}dot[maxn];
int k,n;
queue<ar>q;
int ans[maxn];
int cmp(ar a,ar b)
{
    if(a.dis!=b.dis)return a.dis<b.dis;
    return a.num<b.num;
}
int judge[maxn];
int main()
{
    int i,j;

    while(cin>>n>>k)
    {
        while(!q.empty())
        q.pop();
        memset(ans,0,sizeof(ans));
        memset(judge,0,sizeof(judge));
        int f=0;
        for(i=1;i<=n;i++)
        {
            cin>>dot[i].dis;
            dot[i].num=i;
            if(dot[i].dis<0||dot[i].dis>=n)f=1;
            if(dot[i].dis==0)
            {
                q.push(dot[i]);
            }
            judge[dot[i].dis]++;
        }
        for(i=n-1;i>=0;i--)
        {
            if(judge[i])break;
        }
        for(;i>=0;i--)
        {
            if(judge[i]==0){f=1;}
        }
        if(f||q.size()!=1)
        {
            cout<<-1<<endl;continue;
        }
        sort(dot+1,dot+1+n,cmp);
        int tmp=0;
        i = 2;
        int t=0;
        //cout<<"ok"<<endl;
        while(!q.empty())
        {
            if(i==n+1)break;
            while(!q.empty()&&q.front().dis<tmp)
                q.pop();
            tmp ++;
            //cout<<tmp<<" "<<dot[i].dis<<" "<<q.empty()<<"  "<<q.front().dis<<endl;
            if(tmp!=dot[i].dis){f=1;break;}
            while(!q.empty())
            {
                if(i==n+1)break;
                if(q.front().dis!=tmp-1)break;
                if(tmp!=dot[i].dis)break;
                ar now = q.front();
//cout<<now.num<<" * "<<now.dis<<"  "<<tmp<<" "<<dot[i].dis<<endl;
                if(dot[i].dis>tmp)break;
                if(ans[now.num]+1<=k)
                {
//if(now.num==4)
                  //  cout<<now.num<<" ** "<<dot[i].num<<endl;
                    ans[now.num]++;
                    s[t].x=now.num;
                    s[t++].y=dot[i].num;
                    ans[dot[i].num]=1;
                    q.push(dot[i]);
                    i++;
                }
                else
                   q.pop();
            }
        }
        //cout<<i<<endl;
        if(f||i<=n)
        {
            cout<<-1<<endl;continue;
        }
        cout<<t<<endl;
        for(i=0;i<t;i++)
            cout<<s[i].x<<" "<<s[i].y<<endl;
    }
}
