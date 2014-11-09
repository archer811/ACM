#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
int a[31][100005];
int sum[31];
int r[31];
int main()
{
    int i,j,k,T,n,m;
    scanf("%d",&T);
    int cas=0;
    r[0]=0;
    for(i=1;i<=30;i++)
       r[i]=r[i-1]*2;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        int ss =0,from=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            j=0;
            while(k)
            {
                a[j][i]=k%2;
                k/=2;
                sum[j]+=a[j][i];
                j++;
            }
            for(j=from;j<i;j++)
            {
                int gg =0;
                for(int t=0;t<=30;t++)
                {
                    if(sum[t][i]-sum[t][j])
                       gg +=
                }
            }
        }

    }
}
