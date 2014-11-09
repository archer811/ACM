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
int main()
{
    int i,j;
    int a1,b1,c1,a2,b2,c2;
    while(scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2)!=EOF)
    {
        if(a1==0&&b1==0&&c1!=0)
        {
            puts("0");continue;
        }
        if(a2==0&&b2==0&&c2!=0)
        {
            puts("0");continue;
        }
        if(a1==0&&b1==0&&c1==0)
        {
            puts("-1");continue;
        }
        if(a2==0&&b2==0&&c2==0)
        {
            puts("-1");continue;
        }
    }
    return 0;
}
