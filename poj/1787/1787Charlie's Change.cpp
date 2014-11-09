#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int p;
int g[]={0,1,5,10,25};
int f[10005][5][16];
int a[16],c[5];
int record[10005][5][16];
int main()
{
    int i,j,k;
    a[0]=1;
    for(i=1;i<=15;i++)
        a[i]=a[i-1]*2;
    while(scanf("%d%d%d%d%d",&p,&c[1],&c[2],&c[3],&c[4])!=EOF)
    {
        memset(f,0,sizeof(f));
        memset(record,0,sizeof(record));
        for(i=1;i<=4;i++)
        {
            for(j=0;j<16;j++)
            {
                if(c[i]<=0)break;
                int tmp;
                if(c[i]>=a[j])tmp=a[j];
                else tmp=c[i];
                c[i]-=a[j];
                for(k=p;k>=a[j]*g[i];k--)
                {
                    //if(f[k-a[j]*g[i]][i][j]!=-1)
                    {
                        if(f[k][i][j]<f[k-a[j]*g[i]][i][j]+a[j])
                        {
                            f[k][i][j]=f[k-a[j]*g[i]][i][j]+a[j];
                            record[k][i][j]=a[j];
                            if(i==1)
                                cout<<k<<" "<<j<<" "<<f[k][i][j]<<endl;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(i=1;i<=4;i++)
        {
            for(j=0;j<16;j++)
            {
                cout<<f[p][i][j]<<" ";
                if(f[p][i][j]>ans)ans=f[p][i][j];
            }
            cout<<endl;
        }
        cout<<ans<<endl;
    }
}
