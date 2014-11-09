#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int a[505];
int d[2][4098];
int b[20];
int c[20];
const int N = 13;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,t,n;
    b[0]=2;
    for(i=1; i<20; i++)
        b[i]=b[i-1]*2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ss=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            ss+=a[i];
        }
        memset(d,-1,sizeof(d));
        d[0][0]=0;
        int pre=0,now=1;
        for(i=1; i<=n; i++,now^=1,pre^=1)
        {
            for(j=0; j<4096; j++)
            {
                if(d[pre][j]==-1)continue;

                for(int k=0; k<N; k++)
                {
                    c[k]=0;
                    if((1<<k)&j)c[k]=1;
                }
                int sum=0;


                int flag=0;
                int mark=0;
                for(int k=0; k<N; k++)
                    if(a[i]==b[k])
                    {
                        mark=k;
                        break;
                    }
                for(int k=0;k<mark;k++)
                {
                    if(c[k])
                    {
                        flag=1;break;
                    }
                }
                int f=0;
                if(flag)
                {
                    for(int k=0;k<N;k++)
                        c[k]=0;
                    c[mark]=1;
                }
                else
                {
                    c[mark]++;
                    for(int k=mark;k<N;k++)
                    {
                        if(c[k]>=2)
                        {
                            c[k]=0;
                            sum += b[k+1];
                            c[k+1]++;
                        }
                        else break;
                    }
                }



                //int f=0;
                for(int k=0; k<N; k++)
                    if(c[k])f=f+(1<<k);
                d[now][f]=max(d[now][f],d[pre][j]+sum+a[i]);

                d[now][j] = max(d[now][j],d[pre][j]);
            }
        }
        int M=0;
        for(i=0; i<4096; i++)
        {
            M = max(M,d[pre][i]);
        }
        printf("%d\n",M);
    }
    return 0;
}
