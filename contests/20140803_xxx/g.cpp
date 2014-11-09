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
}g[1000005];
int cmp(o a,o b)
{
    if(a.x==b.x)return a.v>b.v;
    return a.x<b.x;
}
ll num;
int a[1000006],b[1000005];
void msort(int s,int t)
{
    int mid = (t+s)/2;
    int qb=1,bn=t-s+1;
    int i,j;
    if(s>=t)return;
    msort(s,mid);
    msort(mid+1,t);
    for(i=s,j=mid+1;i<=mid&&j<=t;)
    {
        if(a[i]<=a[j])
        {
            b[qb]=a[i];
            i++;
        }
        else
        {
            b[qb]=a[j];
            num+=mid-i+1;
            j++;
        }qb++;
    }
    while(j<=t)
    {
        b[qb]=a[j];qb++;j++;
    }
    while(i<=mid)
    {
        b[qb]=a[i];
        qb++;
        i++;
    }
    for(i=1,j=s;i<qb;i++,j++)
    {
        a[j]=b[i];
    }
}
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
        for(i=1;i<=n;i++)
            a[i]=g[i].v;
//        for(i=1;i<=n;i++)
//            cout<<a[i]<<" ";
//        cout<<endl;
        num=0;
        msort(1,n);
        printf("%lld\n",num);
    }
    return 0;
}
