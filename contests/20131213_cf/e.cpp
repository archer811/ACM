#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll unsigned __int64
int a[20];
int main()
{
    int i,j;
    ll w,m,k;
    while(cin>>w>>m>>k)
    {
        ll n=0;
        ll mm = m,_m=m;
        while(mm)
        {
            mm/=10;n++;
        }
        ll sum=0;
        for(i=0;i<(int)n;i++)
            sum = sum*10+9;
        while(1)
        {
            //cout<<sum<<"*"<<sum-m+1<<endl;
            ll tmp = sum-m+1;
            if(tmp*k*n>w)
            {
                //cout<<tmp<<" "<<k<<" "<<tmp*k<<endl;
                tmp = w/k/n;
                //cout<<tmp<<"G"<<m<<endl;
                ll ans = m+tmp-_m;
                cout<<ans<<endl;break;
            }
            else
            {
                w -= tmp*k*n;
                //cout<<tmp<<"    "<<k<<" "<<n<<endl;
                m = sum+1;
                sum = sum*10+9;n++;
            }
        }
    }
}
