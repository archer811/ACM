#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
int a[22];
int judge(int a,int b)
{
    if(n-a<=20&&n-a>0)return 0;
    if(n<=a)return 1;
    int tmp = n-a-b;
    tmp %= 21;
    return tmp!=0;
}
int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(i=1;i<=20;i++)
            scanf("%d",&a[i]);
        bool flag=false;
        for(i=1;i<=20;i++)
        {
            if(judge(i,a[i]))flag=true;
        }
        if(flag)puts("Carl can win");
        else puts("Carl can't win");
    }
}
