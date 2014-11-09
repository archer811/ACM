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
const int maxn = 808;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
inline int readint()
{
    char c=getchar();
    while(!isdigit(c))c=getchar();
    int x=0;
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
int buf[3];
inline void writeint(int i)
{
    int p=0;
    if(i==0)
    {
        putchar('0');
    }
    else while(i)
    {
        buf[p++]=i%10;
        i/=10;
    }
    for(int j=p-1;j>=0;j--)
        putchar('0'+buf[j]);
}
int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                a[i][j]=readint();a[i][j]%=3;
                c[i][j]=0;
            }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                b[i][j]=readint();b[i][j]%=3;
            }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                if(a[i][k]==0)continue;
                for(j=0;j<n;j++)
                {
                    if(b[k][j]==0)continue;
                    c[i][j]+=a[i][k]*b[k][j];

                }
                //if(i==1&&j==1)cout<<c[i][j]<<endl;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                c[i][j]%=3;
                if(j==0)
                {
                    writeint(c[i][j]);
                    //printf("%d",c[i][j]);
                }
                else
                {
                    putchar(' ');
                    writeint(c[i][j]);
                    //printf(" %d",a[i][j]);
                }

            }puts("");
        }
    }
    return 0;
}
