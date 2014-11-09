#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)&&(n+k))
    {
        if((n-1)%(k+1)==0)puts("Jiang");
        else puts("Tang");
    }
}
