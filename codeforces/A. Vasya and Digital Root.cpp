#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,k;
int main()
{
    int i,j;
    while(cin>>n>>k)
    {
        if(k==0&&n>1)puts("No solution");
        else
        {
            printf("%d",k);
            for(i=2;i<=n;i++)
                printf("0");
            puts("");
        }
    }
}
