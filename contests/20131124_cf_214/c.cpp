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
int d[13000006];
int a[105],b[105],c[105];
const int N = 100000;
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(i=1; i<=n; i++)
            scanf("%d",&b[i]);
        memset(d,-1,sizeof(d));
        int sum=0;
        for(i=1; i<=n; i++)
        {
            c[i]=a[i]-b[i]*k+N;
            sum += c[i];
            //cout<<i<<" "<<c[i]<<endl;
        }
        d[0]=0;
        for(i=1; i<=n; i++)
        {
           //if(c[i]>=N)
            {
                for(j=sum-c[i]; j>=0; j--)
                {
                    if(d[j]!=-1)
                    {
                        d[j+c[i]]=max(d[j+c[i]],d[j]+a[i]);
                        //if(d[j+c[i]]==300)cout<<j<<" "<<d[j+c[i]]<<endl;
                    }
                }
            }


        }
        int ans=-1,M=-1;
        for(i=N; i<=sum; i+=N)
        {
            if(d[i]>=M)
            {
                M=d[i];
                ans=i;
            }
        }
//        //cout<<d[20000]<<" "<<d[30000]<<endl;
        cout<<M<<endl;
    }
}
