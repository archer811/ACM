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
const int maxn=210000*20;
const int ch=26;
int chd[maxn][ch],word[maxn],fail[maxn],sz;
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
}
int fa[maxn];
void Ins(char *s,int val)
{
     int p=0;
     for(;*s;s++)
     {
           if(!chd[p][(*s)-'a'])
           {
                memset(chd[sz],0,sizeof(chd[sz]));
                word[sz]=0;
                chd[p][(*s)-'a']=sz++;
           }
           p=chd[p][(*s)-'a'];
     }
     if(word[p]!=0)fa[val]=word[p];
     else
     word[p]=val;
}
int Que[maxn];
int ans[maxn];
void AC()
{
     int *s=Que,*e=Que;
     for(int i=0;i<26;i++)
         if(chd[0][i])
         {
              fail[chd[0][i]]=0;
              *e++=chd[0][i];
         }
     while(s!=e)
     {
          int p=*s++;
          for(int i=0;i<26;i++)
            if(chd[p][i])
            {
                int k=chd[p][i];
                fail[k]=chd[fail[p]][i];
                *e++=k;
            }
            else
              chd[p][i]=chd[fail[p]][i];
     }
}
int pre[maxn];
int solve(char *s,int val)
{
     int p=0,sum=0;
     for(;*s;s++)
     {
         p=chd[p][(*s)-'a'];
         for(int tmp=p;tmp>0;tmp=fail[tmp])
         {
             if(word[tmp])
             {
                 if(pre[word[tmp]]==val);
                 else
                 {
                     pre[word[tmp]]=val;
                     ans[word[tmp]]++;
                 }
             }

         }

     }
     return sum;
}
char s[25];
struct array
{
    char s[25];
}g[10004];
int main()
{
    int i,j,p;
    scanf("%d",&p);
    init();
    memset(pre,-1,sizeof(pre));
    for(i=0;i<p;i++)
    {
        scanf("%s",g[i].s);
    }
    int q;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
        fa[i]=i;
    for(i=1;i<=q;i++)
    {
        scanf("%s",s);
        Ins(s,i);
    }
    AC();
    memset(ans,0,sizeof(ans));
    for(i=0;i<p;i++)
    {
        solve(g[i].s,i+1);
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",ans[fa[i]]);
    }
}
