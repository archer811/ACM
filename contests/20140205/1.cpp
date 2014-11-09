#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
ll bill ,tip;

int main()
{
    ll n , m = 1;

    while(cin>>n)
    {
        //n = ii;
        //cout<<n<<endl;
        bill = n;
        m=1;
        tip=0;
        while(n)
        {
            if (n % 3 == 2)
            {
                tip += m;
                n++;
            }
            n /= 3;
            m *= 3;
        }
        if (tip == 0)
        {
            tip = m;
        }
        printf("%I64d %I64d\n",bill+tip,tip);
    }

    return 0;
}
