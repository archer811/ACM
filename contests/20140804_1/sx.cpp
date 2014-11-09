#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
int a[22],b[22][22];
int main()
{
    int i,j,t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&n);
        memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        while(1)
        {
            int flag=0;
            for(i=1;i<=n;i++)
            {
                if(a[i]){flag=1;break;}
            }
            if(flag==0)break;
            for(i=1;i)
        }
    }
    return 0;
}
