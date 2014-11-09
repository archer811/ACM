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
int a[10];
int main()
{
    int i,j;
    int sum=0;
    while(cin>>a[0])
    {
        sum=a[0];
        for(i=1;i<5;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%5==0&&sum/5>=1)printf("%d\n",sum/5);
        else puts("-1");
    }
    return 0;
}

