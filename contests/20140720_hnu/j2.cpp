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
    int n;
    int t;
    int x,y;
    cin>>t;
    while (t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        if (n==1)
        {
            if (y==1)
            {
                if(x==1) {printf("2\n");continue; }
                else {printf("1\n");continue; }
            }
            if (y==2) {printf("%d\n",x);continue; }
        }
        if (x<n)
        {
            if (y==2)
            {
                for (int i=1 ;i<=n-1 ;i++) printf("%d ",i);
                printf("%d\n",n);
                continue;
            }
            else if (y==1)
            {
                for (int i=1 ;i<x ;i++) printf("%d ",i);
                for (int i=x ;i<n ;i++) printf("%d ",i+1);
                printf("%d\n",n+1);
                continue;
            }
        }
        if (x==n)
        {
            if (y==2)
            {
                for (int i=1 ;i<n ;i++) printf("%d ",i);
                printf("%d\n",n);
                continue;
            }
            if (y==1)
            {
                for (int i=1 ;i<n ;i++) printf("%d ",i);
                printf("%d\n",x+1);
                continue;
            }
        }
        if (x>n)
        {
            if (y==1)
            {
                for (int i=1 ;i<n ;i++) printf("%d ",i);
                printf("%d\n",n);
                continue;
            }
            if (y==2)
            {
                for (int i=1 ;i<n ;i++) printf("%d ",i);
                printf("%d\n",x);
                continue;
            }
        }
    }
    return 0;
}
