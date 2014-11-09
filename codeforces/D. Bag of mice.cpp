#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
double f[1005][1005];
int mark[1005][1005];
int main()
{
    int i,j,k,w,b;
    while(scanf("%d%d",&w,&b)!=EOF)
    {
        if(w==0&&b==0)
        {
            printf("%.9f\n",0);
            continue;
        }
        memset(f,0,sizeof(f));
        memset(mark,0,sizeof(mark));
        f[w][b]=1;
        for(i=w;i>=0;i--)
        {
            for(j=b;j>=0;j--)
            {
                if(f[i][j]==0)continue;
                if(i>=1&&j>=3)
                {
                    f[i][j-3]+=f[i][j]*(j)*1.0/(i+j)
                    *(j-1)*1.0/(i+j-1)*(j-2)/(i+j-2)
                    ;
                    mark[i][j-3]=1;
                   // if(i==4&&j==3)cout<<f[i][j-3]<<endl;
                }
                if(i>=2&&j>=2)
                {
                    f[i-1][j-2]+=f[i][j]*(j)*1.0/(i+j)
                    *(j-1)*1.0/(i+j-1)*(i)/(i+j-2)
                    ;
                    mark[i-1][j-2]=1;
                    //if(i==5&&j==5)cout<<f[i-1][j-2]<<endl;
//                    cout<<i<<"*"<<j<<" "<<f[i][j]<<" "<<
//                    (j+3)<<" "<<(i+j+4)
//                    <<" "<<(j+2)<<" "<<(i+j+3)<<" "<<(j+1)<<" "<<(i+j+2)
//                    <<" "<<(i+1)<<" "<<(i+j+1)<<endl;
                }
            }
        }
        double sum=0;
        for(i=0;i<=w;i++)
        {
            for(j=0;j<=b;j++)
            {
                if(mark[i][j])
                   sum += f[i][j]*i*1.0/(i+j);
            }
            //cout<<endl;
        }
        printf("%.9f\n",sum+w*1.0/(w+b));
    }
}
