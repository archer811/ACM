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
const int maxn = 1005;
int a[maxn][maxn],b[maxn][maxn];
int main()
{
    int i,j,n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        }
        for(i=n;i>=1;i--)
        {
            for(j=m;j>=1;j--)
            {

                if(i==n&&j==m)
                {
                    b[i][j]=a[i][j];
                }
                else if(j==m)
                {
                    b[i][j]=b[i+1][j]+a[i][j];
                }
                else if(i==n)
                {
                    b[i][j]=b[i][j+1]+a[i][j];
                }
                else
                {


                    b[i][j]=b[i+1][j]+b[i][j+1]-b[i+1][j+1]+a[i][j];

                }
                //cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
            }

        }
        int flag=0,ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(flag==0)ans=b[i][j];
                else ans=max(ans,b[i][j]);
                flag=1;
            }
            //cout<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
