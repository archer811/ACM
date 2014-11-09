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
int d[104][104][104];
int dfs(int k,int j,int i)
{
    if(d[k][j][i]!=-1)return d[k][j][i];
    for(int t=i-1;t>=1;t--)
    {
        int k2=k;
        if(k2>t)k2=t;
        int j2=j;
        if(j2>t)j2=t;
        int i2=t;
        int tmp = dfs(k2,j2,i2);
        if(tmp==0)return 1;


        if(t<=j-1)
        {
            k2=k;
            if(k2>t)k2=t;
            j2=t;
            i2=i;
            tmp = dfs(k2,j2,i2);
            if(tmp==0)return 1;
        }


        if(t<=k-1)
        {
            k2=t;
            j2=j;
            i2=i;
            tmp = dfs(k2,j2,i2);
            if(tmp==0)return 1;
        }
    }
    //cout<<"**"<<endl;
    int k2=0;
    int j2=j;
    int i2=i;
    int tmp;
    if(k!=0)
    {
        tmp= dfs(k2,j2,i2);
        if(tmp==0)return 1;
    }


    k2=0;
    j2=0;
    i2=i;
    if(j!=0)
    {
        tmp = dfs(k2,j2,i2);
        if(tmp==0)return 1;
    }

    return 0;
}
int x,y;
void fun(int k,int j,int i)
{
    for(int t=i-1; t>=1; t--)
    {
        int k2=k;
        if(k2>t)k2=t;
        int j2=j;
        if(j2>t)j2=t;
        int i2=t;
        int tmp = d[k2][j2][i2];
        if(tmp==0)
        {

            x=t+1;y=1;
            //cout<<x<<"**"<<y<<endl;
            return;
        }


        if(t<=j-1)
        {
            k2=k;
            if(k2>t)k2=t;
            j2=t;
            i2=i;
            tmp = d[k2][j2][i2];
            //cout<<t<<"*****"<<2<<" "<<k2<<" "<<j2<<" "<<i2<<" "<<d[k2][j2][i2]<<endl;
            if(tmp==0)
            {
                y=2;
                x=t+1;
                //cout<<x<<"()"<<y<<endl;
                return;
            }
        }


        if(t<=k-1)
        {
            k2=t;
            j2=j;
            i2=i;
            tmp = d[k2][j2][i2];
            if(tmp==0)
            {
                y=3;
                x=t+1;
                //cout<<x<<"!"<<y<<endl;
                return;
            }
        }
    }
    int k2=0;
    int j2=j;
    int i2=i;
    int tmp;
    if(k!=0)
    {
        tmp= d[k2][j2][i2];
        //if(i==2&&j==1&&j==1)
        //cout<<tmp<<endl;
        if(tmp==0)
        {
            x=1;y=3;
            //cout<<x<<"O"<<y<<endl;
            return;
        }
    }


    k2=0;
    j2=0;
    i2=i;
    if(j!=0)
    {
        tmp = d[k2][j2][i2];
        if(tmp==0)
        {
            x=1;y=2;
            //cout<<x<<"&"<<y<<endl;
            return;
        }
    }
}
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    memset(d,-1,sizeof(d));
    d[0][0][1]=0;
    d[0][1][2]=0;
    d[1][1][3]=0;

    for(i=1; i<=100; i++)
    {
        for(j=0; j<=i; j++)
        {
            for(int k=0; k<=j; k++)
            {

                d[k][j][i]=dfs(k,j,i);
                //if(i==2&&j==1&&k==1)
                //cout<<i<<"*"<<j<<" "<<k<<" "<<d[k][j][i]<<endl;
            }
        }
    }
    int t,k,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&k,&a,&b,&c);
        if(a==0&&b==0&&c==0)
        {
            printf("%d L\n",k);
            continue;
        }
        if(d[c][b][a]==1)
        {
            fun(c,b,a);
            printf("%d W %d %d\n",k,x,y);
        }
        else printf("%d L\n",k);
    }
    return 0;
}
