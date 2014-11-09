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
const ll mod = 19876547;
int main()
{
    int i,j;
    freopen("out.txt","w",stdout);
    for(ll d=2;d<=1000;d++)
    {
        ll y=1;
        ll g= sqrt(d);
        if(g*g==d)continue;
        while(1)
        {
            ll x = (ll)sqrt(d*y*y+1);
            if(x*x-d*y*y==1)break;
            y++;
            //if(y>=mod)break;
        }
        cout<<d<<" "<<y<<endl;
    }
    return 0;
}
