#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int f(int n)
{
    int a[6]={0};
    int i,j=0;
    while(n)
    {
        a[j++]=n%10;n/=10;
    }
    int x = a[4]*a[3];
    int y = a[1]*10+a[0];
    if(x==y)return 1;
    return 0;
}
int main()
{
    int i,j;
    for(i=10000;i<=99999;i++)
    {
        if(f(i))cout<<i<<endl;
    }
}
