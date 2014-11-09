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
#define ll long long
map<ll,int>M;
ll a[100005],s[100005];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        s[0]=0;
        M.clear();
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            s[i]=s[i-1]+a[i];
            sum+=a[i];
            M[s[i]]++;
        }
        M[s[n]]--;
        if(sum%3||n<3)
        {
            puts("0");continue;
        }
        ll ans=0;
        for(i=1;i<=n-2;i++)
        {
            M[s[i]]--;
            if(sum/3==s[i])
            {
                ll tmp = s[i]+sum/3;
                //cout<<i<<" "<<M[tmp]<<endl;
                ans+=M[tmp];
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
