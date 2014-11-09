#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[101005],b[101005],n,g2[101005];
int M,ok[101005];
int main()
{
    int i,j,k,q;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ok,0,sizeof(ok));
        int flag=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(i%3&&a[i]!=-1)flag=i;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&b[i]);
        }
        a[3]=b[2]-b[1];
        for(i=6; i<=n; i+=3)
        {
            a[i] = b[i-1]-(b[i-2]-a[i-3]);
        }
        a[n-2]=b[n-1]-b[n];
        for(i=n-5; i>=1; i-=3)
            a[i]=b[i+1]-(b[i+2]-a[i+3]);
        int Min,Max;
        if(n%3!=2)
        {
            for(i=1; i<=n; i++)
            {
                if(a[i]==-1)
                {
                    if(i==1)a[i]=b[i]-a[i+1];
                    else if(i==n)a[i]=b[i]-a[i-1];
                    else a[i]=b[i]-a[i+1]-a[i-1];
                }
            }
        }
        else
        {
            a[0]=0;a[n+1]=0;
            if(flag)
            {
                if(flag%3==1)
                {
                    a[flag+1]=b[flag]-a[flag-1]-a[flag];
                    for(j=flag+3;j<=n;j++)
                        a[j]=b[j-1]-a[j-2]-a[j-1];
                    for(j=flag-2;j>=1;j--)
                        a[j]=b[j+1]-a[j+2]-a[j+1];
                }
                else
                {
                    a[flag-1]=b[flag]-a[flag+1]-a[flag];
                    for(j=flag+2;j<=n;j++)
                        a[j]=b[j-1]-a[j-2]-a[j-1];
                    for(j=flag-3;j>=1;j--)
                        a[j]=b[j+1]-a[j+2]-a[j+1];
                }
            }
            int m = n-(n)/3;
            for(i=1; i<n; i++)
            {
                if(i%3==0)continue;
                j = i-i/3;
                if(i%3==1)
                    g2[j]=b[i]-a[i-1];
                else g2[j]=b[i+1]-a[i+1];
            }
            int tmp = 0;
            ok[1]=0;
            Min = 0x3f3f3f3f,Max = 0;
            for(i=2; i<=m; i++)
            {
                tmp = -tmp+g2[i-1];
                ok[i]=tmp;
                if(i%2==0)
                {
                    if(Min>tmp)Min=tmp;
                }
                else
                {
                    if(Max<-tmp)Max=-tmp;
                }
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&k);
            k++;
            if(a[k]>=0)printf("%d\n",a[k]);
            else
            {
                k = k-k/3;
                if(k%2)
                {
                    printf("%d\n",ok[k]+Min);
                }
                else
                {
                    printf("%d\n",ok[k]-Max);
                }
            }
        }
    }
}
