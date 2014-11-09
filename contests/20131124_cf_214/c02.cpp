#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,k;
int d[2000006];
int a[105],b[105],c[105];
const int N = 10000;
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        memset(d,-1,sizeof(d));
        for(i=1;i<=n;i++)
        {
            c[i]=a[i]-b[i]*k+N;
            //cout<<i<<" "<<c[i]<<endl;
        }
        d[10000]=0;
        for(i=1;i<=n;i++)
        {
            for(j=2000005;j>=c[i];j--)
            {
                if(d[j-c[i]]!=-1)
                {
                    d[j]=max(d[j],d[j-c[i]]+a[i]);
                   // cout<<j<<"@"<<d[j]<<endl;
                }

            }

        }
        int ans=-1,M=-1;
        for(i=N;i<2000006;i+=N)
        {
            if(d[i]>=M){M=d[i];ans=i;}
        }
        //cout<<d[20000]<<" "<<d[30000]<<endl;
        cout<<M<<endl;
    }
}
