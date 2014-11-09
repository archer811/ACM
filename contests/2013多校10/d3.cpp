#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int _time[110][11],b[110],_base[2][4][110];
int ini[5][5][110],pk[2][4];
int sum[5][5];
int d[110][1005];
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
        double ans=-1;
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
                        ini[i][j][k] += 10;
                    }
                }
                sum[i][j]=sum2;
                //cout<<i<<" "<<j<<" "<<sum2<<endl;

                if(sum2>Sum)continue;
                double sum3=i*1.0+j*1.0;
                double allscore=0;
                memset(d,0,sizeof(d));
                for(int k=0; k<n; k++)
                {
                    allscore += ini[i][j][k]*b[k]*1.0;
                }
                int left=Sum-sum[i][j];

                //cout<<left<<endl;
                for(int k=0; k<n; k++)
                {
                    int val=0,ss=0;
                    for(int sx=left; sx>=val;sx--)
                    {
//                        cout<<k<<" "<<sx+val<<"()"<<d[k+1][sx+val]<<
//                            " "<<sx<<" "<<d[k+1][sx+val]<<"*"<<ss<<endl;
                        d[k+1][sx]=max(d[k+1][sx],d[k][sx]+ss);
                        //if(s==left-val)


                    }
                    for(int w=ini[i][j][k]/10; w<=9; w++)
                    {
                        val += _time[k][w];
                        ss += 10*b[k];

                        for(int sx=left-val; sx>=0;sx--)
                        {
//                            cout<<k<<" "<<sx+val<<"()"<<d[k+1][sx+val]<<
//                                " "<<sx<<" "<<d[k+1][sx+val]<<"*"<<ss<<endl;
                            d[k+1][sx+val]=max(d[k+1][sx+val],d[k][sx]+ss);
                            //if(s==left-val)


                        }
                    }
                }
                for(int k=0;k<=left;k++)
                    d[n][left]=max(d[n][left],d[n][k]);
                allscore += d[n][left];
                //cout<<d[n][left]<<endl;

                sum3 += (allscore*1.0/allb);
                if(ans==-1||ans<sum3)ans=sum3;
            }
        }
        printf("Case #%d: ",++cas);

        if(ans==-1)
            puts("Impossible");
        else
            printf("%.2f\n",ans);
    }
    return 0;
}
