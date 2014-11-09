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
typedef long long lld;
using namespace std;
lld a,b,c;

int main()
{
    int i,j;

    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=-1)
    {
        lld temp=0,sum=0;
        temp+=min(a,(lld)2);
        temp+=min(b,(lld)2);
        temp+=min(c,(lld)2);
        sum=a+b+c;
        lld ans=0;
        if(sum<=temp)
        {
            ans=sum*(sum-1)/2;
        }
        else
        {
            ans=temp*(temp-1)/2+(sum-temp)*temp;
        }
        //cout<<a<<" "<<b<<" "<<c<<" : ";
        printf("%I64d\n",ans);
    }
    return 0;
}
