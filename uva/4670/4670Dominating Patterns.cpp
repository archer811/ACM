#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
const int nodenum = 150*77;
char s[1000006],t[155][77];
int ch[nodenum][27];
int val[nodenum];
int fail[nodenum];
int sz;
int num[nodenum];
void init()
{
    sz = 1;
    memset(ch[0],0,sizeof(ch[0]));
    memset(fail,0,sizeof(fail));
    memset(num,0,sizeof(num));
}
void insert(char *t,int v)
{
    int len = strlen(t);
    int u = 0;
    for(int i=0; i<len; i++)
    {
        int j = t[i]-'a';
        if(ch[u][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
           // cout<<sz<<"*"<<endl;
            ch[u][j]=sz++;
        }
        u = ch[u][j];
    }
    val[u]=v;
}
map<string,int>M;
queue<int>q;
void AC()
{
    while(!q.empty())q.pop();
    int i,j;
    for(i=0; i<26; i++)
    {
        if(ch[0][i])
        {
            fail[ch[0][i]]=0;
            q.push(ch[0][i]);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(i=0; i<26; i++)
        {
            if(ch[u][i])
            {
                fail[ch[u][i]]=ch[fail[u]][i];
                q.push(ch[u][i]);
            }
            else
                ch[u][i]=ch[fail[u]][i];
        }
    }
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        init();
        M.clear();
        for(i=1; i<=n; i++)
        {
            scanf("%s",t[i]);
            if(M[t[i]]==0)
            {
                M[t[i]]=1;
                insert(t[i],i);
            }
        }
        AC();
        scanf("%s",s);
        int len = strlen(s);
        int u = 0;
        int  p = 0;
        for(i=0; i<len; i++)
        {
            j = s[i]-'a';
            while(p&&ch[p][j]==0)p=fail[p];
            p = ch[p][j];
            if(val[p])num[val[p]]++;
        }
        int ans=0;
        for(i=1; i<=n; i++)
        {
            if(num[i]>ans)
                ans=num[i];
        }
        printf("%d\n",ans);
        for(i=1; i<=n; i++)
        {
            if(num[i]==ans)
                printf("%s\n",t[i]);
        }
    }
}
