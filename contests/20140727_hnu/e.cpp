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
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair
#define ll __int64
const double pi=acos(-1.0),eps=1e-8;
const ll maxn=100000+100;

char s[maxn];
int main()
{
    ll n;
    while(~scanf("%I64d",&n))
    {
        scanf("%s",s);
        ll all=0,f1=0,f2=0,sum=0;
        ll l=strlen(s);
        ll key=0;
        for(ll i=0;i<l;i++)
        {
            if(s[i]=='1')
            {
                if(n-all>=1)
                {
                    all++;
                    f1++;sum++;
                    //continue;
                }
                else if(f2)
                {
                    f2--;f1++;
                    all--;
                    //continue;
                }
                else ;
                key+=sum;
            }
            if(s[i]=='2')
            {
                if(n-all>=2)
                {
                    all+=2;f2++;sum++;
                    //continue;
                }
                key+=sum;
            }
        }
        printf("%I64d\n",key);
    }

    return 0;
}
