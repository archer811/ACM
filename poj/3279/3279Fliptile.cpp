#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[26][26];
int b[26];
int n,m;
int g[26][26];
int gg(int j,int k)
{
    if(m==1)
    {
        if(j==2)
        {
            if(a[1][1]){if(g[1][0])return 0;else return 1;}
            else {if(g[1][0])return 1;else return 0;}
        }
        else
        {
            if(a[j-1][k+1])
            {
                if(g[j-2][k])return 0;
                else return 1;
            }
            else
            {
                if(g[j-2][k])return 1;
                else return 0;
            }
        }
    }
    else
    {
        int tmp =0;
        if(j>=3)tmp += g[j-2][k];
        if(k>=1)tmp += g[j-1][k-1];
        if(k<=m-2)tmp += g[j-1][k+1];
        tmp += g[j-1][k];
        tmp %= 2;

        if(a[j-1][k+1])
        {
            if(tmp)return 0;
            else return 1;
        }
        else
        {
            if(tmp)return 1;
            else return 0;
        }
    }
}
int f(int num,int mark)
{
    //cout<<num<<"*"<<endl;
    int i=0,j,k;
    int sum=0;
    for(i=0; i<m; i++)
        g[1][i]=0;

    i = 0;
    int nn = num;
    while(num)
    {
        g[1][i++]=num%2;
        if(g[i-1])sum++;
        num/=2;
    }
    for(j=2; j<=n; j++)
    {
        for(k=0; k<m; k++)
        {
            g[j][k] = gg(j,k);
            sum += g[j][k];
        }
    }//cout<<g[1][0]<<" "<<nn<<endl;
    for(i=0;i<m;i++)
    {
        int tmp =0;
        if(n>=2)tmp += g[n-1][i];
        //cout<<tmp<<")"<<endl;
        if(i>=1)tmp += g[n][i-1];
        //cout<<tmp<<"("<<endl;
        if(i<=m-2)tmp += g[n][i+1];
        //cout<<tmp<<"*"<<g[n][i]<<endl;
        tmp += g[n][i];
        tmp %= 2;
        //cout<<i<<" "<<tmp<<" "<<a[n][i+1]<<endl;
        if(tmp!=a[n][i+1])return n*m+1;
    }
    if(mark)
    {
        for(j=1; j<=n; j++)
        {
            for(k=0; k<m; k++)
            {
                if(k==0)printf("%d",g[j][k]);
                else printf(" %d",g[j][k]);
            }puts("");
        }

    }

    return sum;
}
int main()
{
    int i,j,k;
    b[0]=1;
    for(i=1; i<=15; i++)
        b[i]=b[i-1]*2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        }

        int M = n*m+1,tmp=-1;
        for(i=0; i<b[m]; i++)
        {
            int hh = f(i,0);
            if(hh<M)
            {
                M=hh;
                tmp=i;
            }
        }
        //cout<<tmp<<endl;
        if(tmp!=-1)
        f(tmp,1);
        else puts("IMPOSSIBLE");
    }
}
