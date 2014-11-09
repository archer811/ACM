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
    ll n,a,b,mod,l;
    while(scanf("%I64d %I64d %I64d %I64d %I64d",&n,&l,&a,&b,&mod)!=EOF)
    {
        a%=mod;
        b%=mod;
    }
    return 0;
}

