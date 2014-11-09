#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1005][1005],t[105][105];
int n,m,x,y;
const int nodenum = 30000;
int sz;
int ch[nodenum][27];
int val[nodenum][110];
int num[nodenum];
int fail[nodenum];
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
    num[0]=0;
}
void insert(char *s,int v)
{
    int len = strlen(s);
    int i,j;
    int u=0;
    for(i=0; i<len; i++)
    {
        j = s[i]-'a';
        if(ch[u][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            num[sz]=0;
            ch[u][j]=sz++;
        }
        u = ch[u][j];
    }
    val[u][num[u]++]=v;
}
int Q[nodenum];
void AC()
{
    int *ss = Q , *ee = Q;
    int i,j;
    for(i=0; i<26; i++)
    {
        if(ch[0][i])
        {
            fail[ch[0][i]]=0;
            *ee ++ = ch[0][i];
        }
    }
    while(ss!=ee)
    {
        int u = *ss++;
        for(i=0; i<26; i++)
        {
            if(ch[u][i])
            {
                fail[ch[u][i]]=ch[fail[u]][i];
                *ee++=ch[u][i];
            }
            else ch[u][i]=ch[fail[u]][i];
        }
    }
}
int ans[1005][1005];
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%s",s[i]);
        scanf("%d%d",&x,&y);
        init();
        for(i=0; i<x; i++)
            scanf("%s",t[i]),insert(t[i],i+1);
        AC();
        memset(ans,0,sizeof(ans));
        int sum=0;
        for(i=0; i<n; i++)
        {
            int u = 0;
            for(j=0; j<m; j++)
            {
                int  k = s[i][j]-'a';
                while(u&&ch[u][k]==0)
                    u = fail[u];
                u = ch[u][k];
                for(int v = num[u]-1;v>=0;v--)
                {
                    int tmp = val[u][v];
                    if(i>=tmp-1)
                      ans[i-tmp+1][j-y+1]++;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                if(ans[i][j]>=x)sum++;
        }
        printf("%d\n",sum);
    }
}
