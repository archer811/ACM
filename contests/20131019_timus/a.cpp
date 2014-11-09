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
int main()
{
    int i,j,k,n;
//    for(i=5;i<=360;i+=2)
//    {
//        if(360%i==0)
//        {
//            int tmp = (180-360/i)/(i-2);
//            cout<<i<<" "<<tmp<<" "<<90%tmp<<endl;
//        }
//
//    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==4)
        {
            printf("0 2\n");continue;
        }
        if(n%2==0)
        {
            __int64 m = (ll)(n-3)*n/2;
            printf("%I64d %I64d\n",m,m);
        }
        else
        {
            if(n>360||360%n)
                printf("0 0\n");
            else
            {
                int tmp = (180-360/n)/(n-2);
                //cout<<tmp<<" "<<(90%tmp)<<endl;
                if(90%tmp)
                    printf("0 0\n");
                else
                {
                    //cout<<90/tmp<<endl;
                }
            }
        }
    }
}
