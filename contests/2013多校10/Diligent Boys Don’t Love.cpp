#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int _time[110][11],b[110],_base[2][4][110];
int ini[5][5][110],pk[2][4];
int sum[5][5];
int d[1005];
const int inf = 0x3fffffff;
int main()
{
    int i,j,t,n,Sum;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&Sum);
        for(i=0; i<n; i++)
        {
            scanf("%d",&b[i]);
            for(j=0; j<10; j++)
            {
                scanf("%d",&_time[i][j]);
            }
        }
        memset(ini,0,sizeof(ini));
        memset(pk,0,sizeof(pk));
        for(i=0; i<2; i++)
        {
            for(j=1; j<=3; j++)
            {
                scanf("%d",&pk[i][j]);
                for(int k=0; k<n; k++)
                {
                    scanf("%d",&_base[i][j][k]);
                }
            }
        }
        double allb=0;
        for(i=0; i<n; i++)
        {
            allb+=b[i];
        }
        int flag=0;
        for(i=0; i<=3; i++)
        {
            for(j=0; j<=3; j++)
            {
                int sum2=pk[0][i]+pk[1][j];
                for(int k=0; k<n; k++)
                {
                    ini[i][j][k]=max(ini[i][j][k],_base[0][i][k]*10);
                    ini[i][j][k]=max(ini[i][j][k],_base[1][j][k]*10);
                    //cout<<ini[i][j][k]<<"*"<<endl;
                    if(ini[i][j][k]>=60)continue;
                    for(int w=ini[i][j][k]/10; w<6; w++)
                    {
                        sum2 += _time[k][w];
                    }
                }
                if(sum2<=Sum)flag=1;
                sum[i][j]=sum2;
                //cout<<i<<" "<<j<<" "<<sum2<<endl;
            }
        }
        printf("Case #%d: ",++cas);
        if(flag==0)
        {
            puts("Impossible");
            continue;
        }
        double ans=-1;
        for(i=0; i<=3; i++)
        {
            for(j=0; j<=3; j++)
            {
                double sum2=i+j;
                double allscore=0;
                for(int k=0; k<n; k++)
                {
                    ini[i][j][k]=max(ini[i][j][k],60);
                    allscore += ini[i][j][k]*b[k];
                }
                int left=Sum-sum[i][j];
                if(left<0)continue;
                if(left>0)
                {
                    memset(d,0,sizeof(d));
                    d[0]=0;
                    for(int k=0; k<n; k++)
                    {
                        int val=0,ss=0;
                        for(int s=left; s>=val; s--)
                        {
                            //if(d[i][s-val]==-1)continue;
                            d[s]=max(d[s],d[s-val]+ss*b[k]);
                        }
                        for(int w=ini[i][j][k]/10; w<=9; w++)
                        {
                            val += _time[k][w];
                            ss += 10;
                            for(int s=val;s<=left;s++)
                            {
                               // if(d[i][s-val]==-1)continue;
                                d[s]=max(d[s],d[s-val]+ss*b[k]);
                            }
                        }
                    }
                    int gg=d[left];
                    allscore += (double)gg;
                }
                sum2 += (allscore*1.0/allb);
                if(ans==-1||ans<sum2)ans=sum2;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
