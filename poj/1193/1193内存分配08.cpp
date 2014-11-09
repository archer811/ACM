#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int inf = 1<<30;
int n;
struct array
{
    int t,m,p,s,next;
}a[10004];
queue<int>q;
int root,nextime;
int t=0;
int have(int pos,int t)
{
    if(root==0||a[root].s-0>=a[pos].m)
    {
        a[pos].next=root;
        root=pos;
        a[pos].t=t;
        a[pos].s=0;
        return 1;
    }
    int i;
    for(i=root;a[i].next!=0;i=a[i].next)
    {
        if(a[i].s+a[i].m-1+a[pos].m<a[a[i].next].s)
        {
            a[pos].next=a[i].next;
            a[i].next=pos;
            a[pos].s=a[i].s+a[i].m;
            a[pos].t=t;
            return 1;
        }
    }
    if(i && n-(a[i].s+a[i].m) >= a[pos].m)
    {
        a[i].next = pos;
        a[pos].next=0;
        a[pos].s = a[i].s+a[i].m;
        a[pos].t = t;
        return 1;
    }
    return 0;
}
void pour()
{
    int pre = root,temp = inf;
    for(int i=root;i;)
    {
        if(a[i].t+a[i].p==nextime)
        {
            if(i==root)
            {
                root=a[i].next;
                i=root;
            }
            else i = a[pre].next=a[i].next;
        }
        else
        {
            temp = min(temp,a[i].t+a[i].p);
            pre=i;
            i = a[i].next;
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        if(!have(u,nextime))break;
        else
        {
            q.pop();
            temp = min(temp,a[u].t+a[u].p);
        }
    }
    nextime = temp;
}
void insert(int pos)
{
    while(a[pos].t>=nextime)pour();
    if(!have(pos,a[pos].t)){q.push(pos);t++;}
    else nextime = min(nextime,a[pos].t+a[pos].p);
}
int solve()
{
    while(!q.empty())pour();
    int ans = nextime;
    for(int i=root;i;)
    {
        if(a[i].t+a[i].p>ans)ans=a[i].t+a[i].p;
        i = a[i].next;
    }
    return ans;
}
int main()
{
    int i,j,k;
    root=0;
    scanf("%d",&n);
    for(i=1;;i++)
    {
        scanf("%d%d%d",&a[i].t,&a[i].m,&a[i].p);
		if (a[i].t==0 && a[i].m==0 && a[i].p==0) break;
        insert(i);
        //cout<<"*"<<endl;
    }
    printf("%d\n%d\n",solve(),t);
}
