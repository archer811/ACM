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
double w[55];
const int M = 1<<20;
int f[M];
double d[55][2];
int main()
{
    int i,j,n,r;
    for(i=0;i<M;i++)
        f[i]=f[i/2]+(i&1);
    int cas=0;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        if(n==0&&r==0)break;
        for(i=0;i<n;i++)
            scanf("%lf",&w[i]);
        int x = 1<<n;
        memset(d,0,sizeof(d));
        for(i=0;i<n;i++)
        {
            int flag=0;
            for(j=0;j<x;j++)
            {
                if((1<<i)&j)
                {
                    if(f[j]==r)
                    {
                        flag++;
                        double p=1;
                        for(int k=0;k<n;k++)
                        {
                            if((1<<k)&j)
                                p = p*w[k];
                            else
                                p = p*(1.0-w[k]);
                        }
                        //cout<<p<<endl;
                        d[i][1]+=p;
                    }
                }
                else
                {
                    if(f[j]==r)
                    {
                        flag++;
                        //cout<<i<<" "<<j<<endl;
                        double p=1;
                        for(int k=0;k<n;k++)
                        {
                            if((1<<k)&j)
                                p = p*w[k];
                            else
                                p = p*(1.0-w[k]);
                        }
                        //cout<<p<<endl;
                        d[i][0]+=p;
                    }
                }
            }
        }
        printf("Case %d:\n",++cas);
        for(i=0;i<n;i++)
        {
            //printf("%.4f %.4f\n",d[i][0],d[i][1]);
            printf("%.6f\n",d[i][1]*1.0/(d[i][0]+d[i][1]));
        }

    }
    return 0;
}
