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
int a[303][303];
int n,m;
const int maxn = 303;
#define ll unsigned long long
const ll Hash = 1000000007;
//              1000000007
ll l[maxn][maxn],r[maxn][maxn],u[maxn][maxn],d[maxn][maxn];
int test(int mid)
{
    int i,j;
    int flag=0;
    //cout<<n-mid<<"*!"<<m-mid<<endl;
    for(i=1;i<=n-mid+1;i++)
    {
        for(j=1;j<=m-mid+1;j++)
        {
            ll x = l[i][j+mid-1]-l[i][j-1];
            ll y = r[i][j]-r[i][j+mid];
            ll D = d[i+mid-1][j]-d[i-1][j];
            ll U = u[i][j]-u[i+mid][j];
            if(i==1&&j==2)
            {
                cout<<i<<" * "<<j+mid-1<<"  "<<j-1<<" "<<x<<endl;
                cout<<i<<" "<<j<<"  "<<j+mid<<" "<<y<<endl;
            }

            if(x!=y)continue;
            if(D!=U)continue;
            int f2=0;

            for(int k=i;k<=i+mid-1;k++)
            {
                if(l[k][j+mid-1]-l[i][j-1]!=x){f2=1;break;}
                if(r[k][j]-r[k][j+mid]!=x){f2=1;break;}
            }
            if(!f2)
            {
                for(int k=j;k<=j+mid-1;k++)
                {
                    if(d[i+mid-1][k]-d[i-1][k]!=U){f2=1;break;}
                    if(u[i][k]-u[i+mid][k]!=U){f2=1;break;}
                }
            }
            if(!f2)return 1;
//            for(int k=i;k<=i+mid-1;k++)
//            {
//                ll y = l[i]
//            }
        }
    }
    return 0;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                l[i][j]=l[i][j-1]*Hash+a[i][j];
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=m;j>=1;j--)
            {
                r[i][j]=r[i][j+1]*Hash+a[i][j];
            }
        }

        for(j=1;j<=m;j++)
        {
            for(i=1;i<=n;i++)
            {
                d[i][j]=d[i-1][j]*Hash+a[i][j];
            }
        }

        for(j=1;j<=m;j++)
        {
            for(i=n;i>=1;i--)
            {
                u[i][j]=u[i+1][j]*Hash+a[i][j];
            }
        }


//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=m;j++)
//            {
//                cout<<l[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<test(4)<<endl;

        int L= 0,R = min(n,m);
//        while(L<R)
//        {
//            int mid = (L+R)/2;
//            if(test(mid))R=mid;
//            else L=mid+1;
//        }
        printf("%d\n",L);

    }
    return 0;
}
