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

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;

int main()
{
    int A,B,a,b;
    while(~scanf("%d%d%d%d",&A,&B,&a,&b))
    {
        int x1=A/(2*a),x2=B/(2*b);
        if(A%(2*a)>=a) x1++;
        if(B%(2*b)>=b) x2++;
        printf("%d\n",x1*x2);
    }

    return 0;
}
