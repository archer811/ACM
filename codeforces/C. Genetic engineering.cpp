#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#define ll __int64
const ll mod = 1000000009;
const int maxn=101100;
const int ch=128;
int chd[maxn][ch],word[maxn],fail[maxn],sz;
inline int f(char c)
{
    if(c=='A')return 0;
    else if(c=='T')return 1;
    else if(c=='C')return 2;
    return 3;
}
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
}
void Ins(char *s,int val)
{
     int p=0;
     for(;*s;s++)
     {
           if(!chd[p][f(*s)])
           {
                memset(chd[sz],0,sizeof(chd[sz]));
                word[sz]=0;
                chd[p][f(*s)]=sz++;
           }
           p=chd[p][f(*s)];
     }
     word[p]=val;
}
int Que[maxn];
char s[101];
void AC()
{
     int *s=Que,*e=Que;
     for(int i=0;i<4;i++)
         if(chd[0][i])
         {
              fail[chd[0][i]]=0;
              *e++=chd[0][i];
         }
     while(s!=e)
     {
          int p=*s++;
          for(int i=0;i<4;i++)
            if(chd[p][i])
            {
                int k=chd[p][i];
                fail[k]=chd[fail[p]][i];
                word[k]=word[chd[fail[p]][i]];
                *e++=k;
            }
            else
              chd[p][i]=chd[fail[p]][i];
     }

}
ll d[1005][105][11];
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(i=0;i<m;i++)
        {
            scanf("%s",s);
            Ins(s,strlen(s));
        }
        AC();
        memset(d,0,sizeof(d));
        d[0][0][0]=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<sz;j++)
            {
                for(int k=0;k<10;k++)
                {
                    if(d[i-1][j][k]==0)continue;
                    for(int tp=0;tp<4;tp++)
                    {
                        int p = chd[j][tp];
                        if(!p)continue;
                        if(word[p]>=k+1)
                            d[i][p][0]=(d[i][p][0]+d[i-1][j][k])%mod;
                        else
                            d[i][p][k+1]=(d[i][p][k+1]+d[i-1][j][k])%mod;
                    }
                }
            }
        }
        ll sum=0;
        for(i=0;i<sz;i++)
        {
            if(word[i])
            {
                sum += d[n][i][0];
                sum %= mod;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

