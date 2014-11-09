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
ll a[4];
int main()
{
    int i,j;
    while(cin>>a[0]>>a[1]>>a[2])
    {
        sort(a,a+3);
        ll ans = (a[0]+a[1]+a[2])/3;
        if(a[0]+a[1]<=2*a[2])
        {
            ans=  min(ans,a[0]+a[1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

