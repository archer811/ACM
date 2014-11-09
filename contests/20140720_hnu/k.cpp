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
        if(n>x)
        {
            for(int i=1;i<n;i++) printf("%d ",i);printf("%d\n",n);
        }
        else
        {
            for(int i=1;i<=n-1;i++) printf("%d ",i);
            if(y==1) printf("%d\n",x+1);
            else printf("%d\n",x);
        }
    }
    return 0;
}
