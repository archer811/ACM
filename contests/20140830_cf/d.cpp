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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
const int maxn = 1006;
int a[maxn][6],b[maxn][6];
int d[maxn];
int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(b,-1,sizeof(b));
        memset(d,-1,sizeof(d));
        for(j=1;j<=k;j++)
        {
            b[0][j]=0;
            for(i=1;i<=n;i++)
            {
                scanf("%d",&a[i][j]);
                b[a[i][j]][j]=i;
            }
        }
        d[0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(d[j]==-1)continue;
                int f=0;
               // cout<<a[i][1]<<"  "<<a[j][1]<<endl;
                for(int t=1;t<=k;t++)
                {
                  //  cout<<b[a[i][1]][t]<<"()"<<b[a[j][1]][t]<<endl;
                    if(b[a[i][1]][t] > b[a[j][1]][t])continue;
                    else
                    {
                        f= 1;break;
                    }

                }
                if(f==0)
                    d[i] = max(d[i],d[j]+1);
            }
        }
        int M =0;
        for(i=1;i<=n;i++)
            if(d[i]>M)M=d[i];
        cout<<M<<endl;
    }
    return 0;
}
