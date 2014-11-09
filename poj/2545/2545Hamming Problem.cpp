#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define ll long long
set<ll>M;
int main()
{
    int i,j;
    set<ll>::iterator it;

    int n;
    ll p1,p2,p3;
    while(scanf("%lld%lld%lld%d",&p1,&p2,&p3,&n)!=EOF)
    {
        M.clear();
        M.insert((ll)1);
        ll a=1,b=1,c=1;
        int t=0;
        for (it=M.begin(); it!=M.end(); it++)
        {
            M.insert(*it * p1);

            a++;
            M.insert(*it * p2);
            b++;
            M.insert(*it * p3);
            c++;
            t++;//cout<<(*it)<<endl;
            if(t==n+1)
            {
                printf("%lld\n",*it);break;
            }
        }

    }
}
