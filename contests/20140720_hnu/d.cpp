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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        if (x<n)
        {
            printf("1");
            for (int i=2 ;i<=n ;i++) printf(" %d",i);
            puts("");
            continue;
        }
        printf("1");
        for(int i=2;i<=n-1;i++)
            printf(" %d",i);
        if(y==1)
        printf(" %d",x+1);
        else
            printf(" %d",x);
        puts("");
    }
    return 0;
}
