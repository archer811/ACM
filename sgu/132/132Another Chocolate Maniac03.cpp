#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,tmpnow,tmpnext;
const int inf = 0x7fffffff/2;
char s[77][11];
int d[2][512][512];
int mi[10]= {1},a[80],i,j,k,t;
void dfs(int p,int fro,int now,int next,int num)
{
    if(p>1 && ((now&mi[p-1])==0) && ((now&mi[p-2])==0) )
        return;
    if(p>0 && ((now&mi[p-1])==0) && ((fro&mi[p-1])==0) )
        return;

    if(p==m)
    {
        d[i&1][now][next]=min(d[i&1][now][next],
                                  d[1-(i&1)][tmpnow][tmpnext]+num);
        return;
    }
    if( (p+1<m) && ((now&mi[p])==0) && ((now&mi[p+1])==0) )
    {
        dfs(p+2,fro,now|mi[p]|mi[p+1],next,num+1);
    }

    if( ((now&mi[p])==0) && ((next&mi[p])==0) )
    {
        int tmp = (1<<p);
        dfs(p+1,fro,now|mi[p],next|mi[p],num+1);
    }

    dfs(p+1,fro,now,next,num);
}
int main()
{
    mi[0]=1;
    for(i=1; i<=7; i++)
        mi[i] = mi[i-1]*2;
    scanf("%d%d",&n,&m);
    t = (1<<m)-1;
    a[0]=a[n+1]=t;
    for(i=1; i<=n; i++)
    {
        scanf("%s",s[i]);
        int ok =0;
        for(j=0; j<m; j++)
        {
            ok = ok*2+(s[i][j]=='*');
        }
        a[i]=ok;
    }
    for(j=0; j<=t; j++)
    {
        for(k=0; k<=t; k++)
            d[0][j][k]=inf;
    }
    d[0][t][a[1]]=0;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=t; j++)
        {
            for(k=0; k<=t; k++)
                d[i&1][j][k]=inf;
        }
        for(j=0; j<=t; j++)
        {
            for(k=0; k<=t; k++)
            {
                if(d[1-(i&1)][j][k]!=inf)
                {
                    tmpnow=j;
                    tmpnext=k;
                    dfs(0,j,k,a[i+1],0);
                }
            }
        }
    }
    int ans=inf;
    for(i=0; i<=t; i++)
    {
        if(d[n&1][i][t]<ans)
            ans = d[n&1][i][t];
    }
    printf("%d\n",ans);

}
