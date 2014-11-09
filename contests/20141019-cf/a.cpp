#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
int a[205];
int b[205],g2[205];
int cmp1(int a,int b)
{
    return a>b;
}
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]>=0)break;
        }
        if(i==n+1)
        {
            sort(a+1,a+1+n);
            cout<<a[1]<<endl;
            continue;
        }
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                int tp=0,tp2=0;
                for(int t=1;t<=n;t++)
                {
                    if(t<i||t>j)
                        b[tp++]=a[t];
                    else
                        g2[tp2++]=a[t];
                }
                sort(b,b+tp,cmp1);
                //sort(b,b+tp,cmp1);
                sort(g2,g2+tp2);
                for(int t=0;t<k&&t<tp&&t<tp2;t++)
                {
                    if(b[t]>g2[t])swap(b[t],g2[t]);
                }
                int sum=0;
                for(int t=0;t<tp2;t++)
                    sum+=g2[t];
                ans=max(ans,sum);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

