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
        int flag=0;
        if(a1==0&&b1==0&&c1==0)
        {
            puts("-1");
        }
        else if(a1==0&&b1==0&&c1!=0)
        {
            puts("0");
        }
        else if(a1==0)
        {
            if(a2==0)
            {
                if(b2==0)
                {
                    if(c2==0)puts("-1");
                    else puts("0");
                    continue;
                }
                if(c1==0&&c2==0)puts("-1");
                else if(c1==0&&c2)
                {
                    puts("0");
                }
                else if(c1&&c2==0)
                {
                    puts("0");
                }
                else if(c1&&c2)
                {
                    if(b1*c2==c1*b2)puts("-1");
                    else puts("0");
                }
            }
            else puts("1");
        }
        else if(b1==0)
        {

            if(b2==0)
            {
                if(a2==0)
                {
                    if(c2==0)puts("-1");
                    else puts("0");
                    continue;
                }
                if(c1==0&&c2==0)puts("-1");
                else if(c1==0&&c2)
                {
                    puts("0");
                }
                else if(c1&&c2==0)
                {
                    puts("0");
                }
                else if(c1&&c2)
                {
                    if(a1*c2==c1*a2)puts("-1");
                    else puts("0");
                }
            }
            else puts("1");
        }
        else
        {
            if(a1*b2==b1*a2)
            {
                if(a1*c2==c1*a2&&b1*c2==c1*b2)
                {
                    puts("-1");
                    continue;
                }
                else puts("0");
            }
            else puts("1");
        }
    }
    return 0;
}
