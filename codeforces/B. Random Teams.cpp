#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif

int main()
{
    int i,j;
    ll n,m;
    while(cin>>n>>m)
    {
        if(m==1)
        {
            ll tmp = n*(n-1)/2;
            cout<<tmp <<" "<<tmp<<endl;
        }
        else
        {
            ll x = n/m;
            ll y = n-(x*(m));
            ll g = x*(x+1)/2;
           // cout<<g<<"()"<<y<<endl;
            ll tmp1 = (y)*(g);
            //cout<<y<<" "<<g<<" "<<m-y<<" "<<(x*(x-1)/2)<<endl;
            ll tmp2 = (m-y)*((x*(x-1))/2);
            ll ansx = tmp1+tmp2;

            x = n-(m-1);
            x = x*(x-1)/2;
            ll ansy = x;
            if(ansx>ansy)swap(ansx,ansy);
            cout<<ansx<<" "<<ansy<<endl;
        }
    }
    return 0;
}

