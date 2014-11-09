#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
using namespace std;
#define ll __int64
ll a,b,c;
int main()
{
    //freopen("out1.txt","w",stdout);
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
    {
        int sum=0;
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        if(b>c)swap(b,c);
        if(a)sum++;
        if(b)sum++;
        if(c)sum++;
        ll ans;
        if(sum==0)
        {
            ans = 0;
        }
        else if(sum==1)
        {
            if(c==1)ans = 0;
            else if(c>=2)ans = 1+(c-2)*(ll)2;
        }
        else if(sum==2)
        {
            int x=b,y=c;
            if(x>=2&&y>=2)
                ans = (ll)6+(ll)(x-2+y-2)*(ll)4;
            else if(x<2&&y>=2)
            {
                ans = (ll)3+(ll)(y-2)*(ll)3;
            }
            else if(x<2&&y<2)ans = 1;
        }
        else if(sum==3)
        {
            if(a>=2&&b>=2&&c>=2)
            {
                ans = (ll)15+(a-2+b-2+c-2)*(ll)6;
            }
            else if(a<2&&b<2&&c>=2)
            {
                ans = (ll)6+(c-2)*(ll)4;
            }
            else if(a<2&&b>=2&&c>=2)
            {
                ans = (ll)10+(b-2+c-2)*(ll)5;
            }
            else if(a<2&&b<2&&c<2)
                ans = (ll)3;
        }
        cout<<ans<<endl;
    }
}
