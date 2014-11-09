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
const int N = 55;
int a[N][N],b[N][N],c[N][N][N][N];
int main()
{
    int i,j,n,k,g;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&b[i][j]);
        int ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    for(g=1;g<=n;g++)
                    {
                        int s=0;
                        for(int x=0;s<n && j+s <= n && g+s <=n ;s++)
                        {
                            if(a[i][j+s]==b[k][g+s])
                            {
                                continue;
                            }
                            else break;
                        }
                        c[i][j][k][g]=s;

                    }
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    for(g=1;g<=n;g++)
                    {
                        int x = n+1;
                        for(int s=0;s<n && s+i <=n && k+s <= n;s++)
                        {
                            //cout<<"oo"<<endl;
                            int len = c[i+s][j][k+s][g];
                            x = min(x,len);
                            //if(i==2&&j==2&&k==1&&g==1)
                            //cout<<i<<"  "<<j<<"  "<<k<<"  "<<g<<" "<<s<<"  "<<x<<endl;

                            if(s+1>x)
                            {
                                ans = max(ans,x);
                                break;
                            }
                            else ans = max(ans,s+1);
                        }
                    }
                }
            }
        }

        printf("%d\n",ans);

    }
    return 0;
}
