#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int _map[105][105];
int sum[105][105];
int main()
{
    int i,j,w,h,n,s,t,a,b;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d%d",&w,&h);
        memset(_map,0,sizeof(_map));
        memset(sum,0,sizeof(sum));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            _map[b][a]=1;
        }
        scanf("%d%d",&s,&t);
        for(i=1;i<=w;i++)
            sum[1][i]=sum[1][i-1]+_map[1][i];
        for(i=1;i<=h;i++)
            sum[i][1]=sum[i-1][1]+_map[i][1];
        for(i=2;i<=h;i++)
        {
            for(j=2;j<=w;j++)
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+_map[i][j];
        }
        int ans=-1,g;
//        for(i=1;i<=h;i++)
//        {
//            for(j=1;j<=w;j++)
//                cout<<sum[i][j]<< " ";
//            cout<<endl;
//        }
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                if(i+t-1<=h&&j+s-1<=w)
                {
                    if(sum[i+t-1][j+s-1]+sum[i-1][j-1]-sum[i+t-1][j-1]-
                       sum[i-1][j+s-1]>ans)
                    {
                        ans = sum[i+t-1][j+s-1]+sum[i-1][j-1]-sum[i+t-1][j-1]-
                       sum[i-1][j+s-1];
                        //cout<<i<<" "<<j<<" "<<i+t-1<<" "<<j+s-1<<" "<<ans<<endl;
                    }

                }
            }
        }
        cout<<ans<<endl;
    }
}
