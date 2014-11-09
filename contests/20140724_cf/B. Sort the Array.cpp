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
int a[100005];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>a[i];
    int flag=0;
        for(i=2;i<=n;i++)
        {
            if(a[i]>a[i-1])continue;
            flag=1;
        }
        if(flag==0)
        {
            puts("yes");
            cout<<1<<" "<<1<<endl;
            continue;
        }
        int l=1;
        for(i=2;i<=n;i++)
        {
            if(a[i]>a[i-1])l=i;
            else break;
        }
        int r = n;
        for(i=n-1;i>=l;i--)
        {
            if(a[i]<a[i+1])r=i;
            else break;
        }
        flag=0;
        //cout<<l<<" "<<r<<endl;
        for(i=l;i<=r;i++)
        {
            if(i==l)continue;
            if(a[i]<a[i-1])continue;
            flag=1;
        }
        int ll=l,rr=r;
        while(l<=r)
        {
            swap(a[l],a[r]);
            l++;r--;
        }
        for(i=2;i<=n;i++)
        {
            if(a[i]>a[i-1])continue;
            else flag=1;
        }
        if(flag)puts("no");
        else
        {
            puts("yes");
            cout<<ll<<" "<<rr<<endl;
        }
    }
    return 0;
}
