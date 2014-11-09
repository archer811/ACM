#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,p;
int a[1005][1005],b[1005][1005],c[1005][1005],c2[1005][1005];
void f()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            c2[i][j]=0;
            for(int k=1;k<=p;k++)
                c2[i][j]+=(a[i][k]*b[k][j]);
        }
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&n,&p,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=p;j++)
                scanf("%d",&a[i][j]);
        }
        for(i=1;i<=p;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&c[i][j]);
        }
        f();
        int x,y,tt=0;
        bool flag = false;
        for(i=1;i<=n&&flag==false;i++)
        {
            for(j=1;j<=m&&flag==false;j++)
            {
                if(c2[i][j]!=c[i][j])
                {
                    x=i;y=j;
                    flag = true;
                    tt=c2[i][j];
                }
            }
        }
        if(flag==false)
            puts("Yes");
        else
        {
            puts("No");
            printf("%d %d\n%d\n",x,y,tt);
        }
    }
}
