#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int init(int n)
{
    int i,j;
    double sum = 1;
    j=0;
    for(i=n;i>=n/2;i--)
    {
        j++;
        double tmp = i*1.0/n;
        sum *= tmp;
        if(sum<0.5)break;
    }
    return j;
}
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    int cas =0;
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++cas,init(n)-1);
    }
}
