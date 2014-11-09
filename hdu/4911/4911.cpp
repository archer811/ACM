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
ll num;
int a[1000006],b[1000005];
ll max(ll a,ll b)
{
    if(a>b)return a;
    return b;
}
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
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        num=0;
        msort(1,n);
        printf("%I64d\n",max((num-(ll)k),0));
    }
    return 0;
}
