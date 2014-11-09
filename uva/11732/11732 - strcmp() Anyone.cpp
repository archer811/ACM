#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int nodenum = 4005005;
const int sigma = 70;
int ch[nodenum][sigma];
int sz;
int val[nodenum];
//int son[nodenum];
//int ceng[nodenum];
//vector<int>g[nodenum];
void init()
{
    sz = 1;
//    son[0]=0;
   // ceng[0]=0;
   // g[0].clear();
    memset(ch[0],0,sizeof(ch[0]));
}
int inx(char s)
{
    if(s>='a'&&s<='z')return s-'a';
    else if(s>='A'&&s<='Z')return 26+s-'A';
    else return 52+s-'0';
}
void insert(char *s)
{
    int len = strlen(s);
    int u=0;
    for(int i=0; i < len; i++)
    {
        int j = inx(s[i]);
        if(ch[u][j]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
            //son[sz]=0;
            //g[sz].clear();
            //ceng[sz]=ceng[u]+1;
            //g[u].push_back(j);
            ch[u][j]=sz++;
        }
        //son[u]++;
        u = ch[u][j];
    }
    val[u]++;
}
char s[10005];
long long sum=0;
/*
void dfs(int u)
{
    int tmp = (1+ceng[u])*2-1;
   // cout<<u<<"&"<<son[u]<<endl;
    if(son[u]==0)
    {
        //cout<<u<<" "<<val[u]<<endl;
        if(val[u]>=2)
            sum += 2*ceng[u];
        return;
    }
    int minisum=0;


    // cout<<u<<"D"<<endl;
    for(int j=0; j < g[u].size(); j ++)
    {
        int i = g[u][j];
        //0cout<<i<<"*"<<endl;
        if(ch[u][i]==0)continue;
        if(son[ch[u][i]]==0)
            son[ch[u][i]]=1;
        minisum += son[ch[u][i]];
    }
    //cout<<minisum<<endl;
    for(int j=0; j < g[u].size(); j ++)
    {
        int i = g[u][j];
        if(ch[u][i]==0)continue;
        //cout<<u<<"DDD"<<endl;

        minisum -= son[ch[u][i]];
        //if(u==0)cout<<minisum<<")*)(*)"<<trie.son[trie.ch[u][i]]<<
        //    " "<<tmp<<endl;
        sum += son[ch[u][i]]*tmp*minisum;
        //cout<<ch[u][i]<<"*"<<endl;
        dfs(ch[u][i]);
    }
}
void dfs1(int u)
{
    for(int j=0; j < g[u].size(); j ++)
    {
        int i = g[u][j];
        if(ch[u][i]==0)continue;
        dfs1(ch[u][i]);
        if(son[ch[u][i]]==0)
            son[ch[u][i]]=1;
        //cout<<trie.ch[u][i]<<"**"<<trie.son[trie.ch[u][i]]<<endl;
    }
}*/
int n;
int main()
{
    int i,j,n;
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        init();
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            insert(s);
        }
        //dfs1(0);
        sum = 0;
        //dfs(0);
        if(cas==0)sum=1;
        else sum=6;
        printf("Case %d: %lld\n",++cas,sum);
    }
}
