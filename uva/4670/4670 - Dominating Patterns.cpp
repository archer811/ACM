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
const int maxn=150*100+10;
const int maxm = 1000006;
const int ch=30;
int chd[maxn][ch],word[maxn],fail[maxn],sz;
char s[255][100];
char t[maxm];
int num[maxn];
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
    memset(fail,0,sizeof(fail));
    memset(num,0,sizeof(num));
    memset(word,0,sizeof(word));
}
void Ins(char *s,int val)
{
    int p=0;
    for(; *s; s++)
    {
        if(!chd[p][(*s)-'a'])
        {
            memset(chd[sz],0,sizeof(chd[sz]));
            word[sz]=0;
            chd[p][(*s)-'a']=sz++;
        }
        p=chd[p][(*s)-'a'];
    }
    //cout<<val<<endl;
    word[p]=val;
}
queue<int>q;

void AC()
{
    while(!q.empty())q.pop();
    for(int i=0; i<26; i++)
        if(chd[0][i])
        {
            fail[chd[0][i]]=0;
            q.push(chd[0][i]);
        }
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=0; i<26; i++)
            if(chd[p][i])
            {
                int k=chd[p][i];
                fail[k]=chd[fail[p]][i];
                q.push(k);
            }
            else
                chd[p][i]=chd[fail[p]][i];
    }
}
void solve(char *s)
{
    int p=0,sum=0;
    for(; *s; s++)
    {
        p=chd[p][(*s)-'a'];
        for(int tmp=p; tmp>0; tmp=fail[tmp])
            if(word[tmp]) num[word[tmp]]++;
    }
}
map<string,int>M;
int main()
{
    int i,j,k,n;
    while(~scanf("%d", &n) && n)
    {
        if(n==0)break;
        init();
        M.clear();
        for(i=1; i<=n; i++)
        {
            scanf("%s",s[i]);
            Ins(s[i],i);
        }
//        j=1;
//        for(i=1;i<=n;i++)
//        {
//           if(M[s[i]]==0)
//           {
//               strcpy(s[j++],s[i]);
//               M[s[i]]=1;
//           }
//        }
//        n=j;
//        for(i=1;i<n;i++)
//        {
//            //cout<<i+1<<" "<<s[i]<<endl;
//            Ins(s[i],i);
//        }
        AC();
        scanf("%s",t);
        solve(t);
        int ans=0;
        for(i=1; i<=n; i++)
            if(num[i]>ans)ans=num[i];
        printf("%d\n",ans);
        for(i=1; i<=n; i++)
            if(num[i]==ans)
            {
                printf("%s\n",s[i]);
            }
    }
}
