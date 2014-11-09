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
#define ll __int64
int main()
{
    ll i,j;
    ll n;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n<=3)puts("NO");
        else
        {
            puts("YES");
            int flag=0;
            i = n;
            if(n>=8)
            {
                flag=1;
                for(i=n;i>=8;i-=4)
                {
                    if(i!=n)
                        printf("0 + %I64d = %I64d\n",i,i);
                    printf("%I64d - %I64d = 1\n",i,i-1);
                    printf("1 + %I64d = %I64d\n",i-3,i-2);
                    printf("%I64d - %I64d = 0\n",i-2,i-2);
                }
            }
            if(i==7)
            {
                cout<<"7 - 5 = 2"<<endl;
                cout<<"3 - 2 = 1"<<endl;
                cout<<"2 - 1 = 1"<<endl;
                cout<<"1 - 1 = 0"<<endl;
                cout<<"0 + 4 = 4"<<endl;
                cout<<"4 * 6 = 24"<<endl;
            }
            if(i==6)
            {
                cout<<"5 - 3 = 2"<<endl;
                cout<<"2 - 2 = 0"<<endl;
                cout<<"0 + 1 = 1"<<endl;
                cout<<"1 * 4 = 4"<<endl;
                cout<<"4 * 6 = 24"<<endl;
            }
            if(i==5)
            {
                cout<<"4 * 5 = 20"<<endl;
                cout<<"3 - 1 = 2"<<endl;
                cout<<"2 + 2 = 4"<<endl;
                cout<<"20 + 4 = 24"<<endl;
            }
            if(i==4)
            {
                cout<<"2 * 3 = 6"<<endl;
                cout<<"6 * 4 = 24"<<endl;
                cout<<"24 * 1 = 24"<<endl;
            }
            if(flag)
                cout<<"0 + 24 = 24"<<endl;
        }
    }
    return 0;
}
