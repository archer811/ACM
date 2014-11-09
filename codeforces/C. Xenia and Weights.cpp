#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int v[11];
char s[12];
int f[1005][12][12];
const int inf = 0x3fffffff;
int pre[1005][12][12];
int a[1005],m;
void ff(int aa,int bb)
{
    int i,j=0;
    i = m-1;
    int tmp = pre[m][aa][bb];
    a[j++]=bb;a[j++]=aa;
    while(tmp!=-1)
    {
        a[j++]=tmp;
        bb = aa;
        aa = tmp;
        tmp = pre[i][aa][bb];
        i--;
    }
    for(i=j-1;i>=0;i--)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int i,j,k;
    while(scanf("%s",s)!=EOF)
    {
        int tt=0,ab=-1,ac=-1;
        for(i=0;i<10;i++)
        {
            if(s[i]=='0')
                v[i+1]=0;
            else
            {
                v[i+1]=1,tt++;
                if(ab==-1)ab=i+1;
                else ac = i+1;
            }
        }
        scanf("%d",&m);
        if(m==1)
        {
            if(tt>=1)
            {
                puts("YES");
                printf("%d\n",ab);
            }
            else puts("NO");
            continue;
        }
        else if(m==2)
        {
            if(tt>=2)
            {
                puts("YES");
                printf("%d %d\n",ab,ac);
            }
            else puts("NO");
            continue;
        }
        for(i=0;i<=m;i++)
            for(j=1;j<=10;j++)
                for(k=1;k<=10;k++)
                   f[i][j][k]=inf;
        memset(pre,-1,sizeof(pre));
        for(i=1;i<=10;i++)
        {
            if(v[i]==0)continue;
            for(j=1;j<=10;j++)
            {
                if(v[j]==0)continue;
                if(i==j)continue;
                if(i-j<0)f[2][i][j]=i-j;
            }
        }
        //cout<<m<<endl;
        for(i=3;i<=m;i++)
        {
            if(i%2)
            {
                for(j=1;j<=10;j++)
                {
                    if(v[j]==0)continue;
                    for(k=1;k<=10;k++)
                    {
                        if(v[k]==0)continue;
                        if(j==k)continue;
                        int tmp = inf,g;
                        for(int t=1;t<=10;t++)
                        {
                            if(v[t]==0)continue;
                            if(t==k)continue;
                            if(f[i-1][t][k]==inf)continue;
                            if(f[i-1][t][k]+j>0)
                            {
                                if(f[i-1][t][k]+j<tmp)
                                    tmp=f[i-1][t][k]+j,g=t;
                               // if(i==9)cout<<k<< "()() "<<j<<endl;
                            }
                        }
                        if(tmp==inf)f[i][k][j]=inf;
                        else
                        {
                            f[i][k][j]=tmp;
                            pre[i][k][j]=g;
                        }
                    }
                }
            }
            else
            {
                for(j=1;j<=10;j++)
                {
                    if(v[j]==0)continue;
                    for(k=1;k<=10;k++)
                    {
                        if(v[k]==0)continue;
                        if(j==k)continue;
                        int tmp = -inf,g;
                        for(int t=1;t<=10;t++)
                        {
                            if(v[t]==0)continue;
                            if(t==k)continue;
                            if(f[i-1][t][k]==inf)continue;
                            if(f[i-1][t][k]-j<0)
                            {
                                if(f[i-1][t][k]-j>tmp)
                                    tmp=f[i-1][t][k]-j,g=t;
                                //if(i==10)cout<<"k"<<k<<" "<<j<<endl;
                            }
                        }
                        if(tmp==-inf)f[i][k][j]=inf;
                        else
                        {
                            f[i][k][j]=tmp;
                            pre[i][k][j]=g;
                        }
                    }
                }
            }
        }
        int  ok = 0,aa,bb;
        //cout<<m<<"*"<<endl;
        for(i=1;i<=10&&ok==0;i++)
        {
            for(j=1;j<=10&&ok==0;j++)
            {
                if(f[m][i][j]!=inf)
                {
                    //cout<<i<<"j**"<<j<<" "<<f[m][i][j]<<endl;
                    ok=1;aa=i;bb=j;break;
                }
            }
        }
        if(ok==0)puts("NO");
        else
        {
           puts("YES");
           ff(aa,bb);
        }
    }
}
/*
1110001001
642
*/
