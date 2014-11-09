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
#define ll __int64
const int maxn = 2006;
ll a[maxn][maxn];
ll ans=-1;
int xl,yl,x2,y2;
ll x[maxn*2];
ll g[maxn*2][2];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        memset(g,0,sizeof(g));
        memset(x,0,sizeof(x));
        int k=0,k2=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%I64d",&a[i][j]);
                x[i+j]+=a[i][j];
                if(i-j>=0)g[i-j][0]+=a[i][j];
                else g[j-i][1]+=a[i][j];

            }

        }
        ll ans1=-1,ans2=-1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                ll tmp = 0;
                int s3=0;
                int ff=0;
                if(i-j>=0)s3=i-j;
                else
                {
                    s3=j-i;
                    ff=1;
                }
                tmp = x[i+j]+g[s3][ff]-a[i][j];
                //cout<<i<<"()"<<j<<" "<<x[i+j]<<" "<<g[s2][ff]<<" "<<tmp<<endl;
                if((i+j)%2)
                {
                    if(ans1<tmp)
                    {
                        ans1=tmp;
                        xl=i;
                        yl=j;
                    }
                }
                else
                {
                    if(ans2<tmp)
                    {
                        ans2=tmp;
                        x2=i;
                        y2=j;
                    }
                }

            }
        }
        cout<<ans1+ans2<<endl;
        cout<<xl<<" "<<yl<< " "<<x2<< " "<<y2<<endl;
    }
    return 0;
}
