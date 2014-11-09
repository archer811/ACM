#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[1005],n;
int cal(int add,int mid)
{
    int i,j;
    int l=a[0]-mid,r=a[0]+mid;
    //cout<<l<<" "<<r<<endl;
    for(i=1;i<n;i++)
    {
        int l1=a[i]-mid;
        int r1=a[i]+mid;
        l += add;r += add;
        if(l1>r||r1<l)return 0;
        l = max(l,l1);
        r = min(r,r1);
    }
    return 1;
}
int f(int mid)
{
    int i,j;
    for(i=0;i<=20000;i++)
    {
        if(cal(i,mid))
        {
           // if(mid==16)cout<<i<<"()"<<endl;
            return 1;
        }
    }
    return 0;
}
void ff(int add,int mid)
{
    int i,j;
    for(i=a[0]-mid;i<=a[0]+mid;i++)
    {
        int tmp = i;
       // cout<<i<<endl;
        for(j=1;j<n;j++)
        {
            int l1 = a[j]-mid;
            int r1 = a[j]+mid;
            tmp += add;
           // cout<<l1<<"*"<<r1<<" "<<tmp<<endl;
            if(tmp>=l1&&tmp<=r1)continue;
            else break;
        }
        //cout<<endl;
    }
}
void output(int add,int mid)
{
    int i,j;
    for(i=a[0]-mid;i<=a[0]+mid;i++)
    {
        int tmp = i;
       // cout<<i<<endl;
        for(j=1;j<n;j++)
        {
            int l1 = a[j]-mid;
            int r1 = a[j]+mid;
            tmp += add;
           // cout<<l1<<"*"<<r1<<" "<<tmp<<endl;
            if(tmp>=l1&&tmp<=r1)continue;
            else break;
        }
        if(j==n)
        {
            printf("%d %d\n",i,add);
            break;
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);

        int l =0,r=20002;

        while(l<r)
        {
            int mid = (l+r)/2;
           // cout<<l<<" "<<r<<" "<<mid<<"*"<<f(mid)<<endl;
            if(f(mid))r=mid;
            else l=mid+1;
        }
       // f(16);ff(24,16);
        printf("%d\n",l);

        for(i=0;i<=20000;i++)
        {
            if(cal(i,l))
            {
                output(i,l);
                //cout<<i<<endl;
                break;
            }
        }
    }
}
