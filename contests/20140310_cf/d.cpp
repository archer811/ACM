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
int a[20];
#define ll long long
ll dp[20][11][110];
ll n;
int m;
int len;
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        len=0;
        while(n)
        {
            j = n%10;
            a[j]++;
            n/=10;
            len++;
        }
        int M = (1<<)
        for(i=0;i<=9;i++)
        {
            for(j)
        }
    }
}
