#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll __int64
ll a[100005];
int cmp(ll a,ll b)
{
    return (a%2)>(b%2);
}
int main()
{
    int i,j,n,odd,even;
    int k,p;
    while(cin>>n>>k>>p)
    {
        odd=0;
        even=0;
        int k2=k-p;//odd
        for(i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]%2)odd++;
            else even++;
        }
        sort(a,a+n,cmp);

        int flag=0;
        if(odd<k2)flag=1;
        if(odd>=k2&&(odd-k2)%2)flag=1;
        if(odd>=k2&&(odd-k2)%2==0&&(odd-k2)/2+even<p)flag=1;
        if(flag)
        {
            puts("NO");continue;
        }
        puts("YES");
        if(p==0)
        {
            for(i=0;i<k2-1;i++)
            {
                cout<<1<<" "<<a[i]<<endl;
            }
            if(n-1-(k2-1)+1>0)
            cout<<n-1-(k2-1)+1<<" ";
            for(;i<n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
            continue;
        }

        for(i=0; i<k2; i++)
        {
            cout<<1<<" "<<a[i]<<endl;
        }
        int s=n-1;
        for(i=0;i<p-1;i++)
        {
            if(a[s]%2==0)
            {
                cout<<1<<" "<<a[s--]<<endl;
            }
            else
            {
                cout<<2<<" "<<a[s--]<<" "<<a[s--]<<endl;
            }
        }
        if(s-k2+1>0)
        cout<<s-k2+1<<" ";
        if(p>=1)
        for(i=k2;i<=s;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
