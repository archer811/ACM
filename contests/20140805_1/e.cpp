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
#define ll long long
const ll mod = 1000000007;
const int maxn = 1005*35;
const int ch = 26;
int chd[maxn][ch],word[maxn],fail[maxn],sz;
void init()
{
    memset(chd[0],0,sizeof(chd[0]));
    sz=1;
    fail[0]=0;
}
void ins(char *s,int val)
{
    int p=0;
    for(; *s; *s++)
    {
        int tmp = (*s)-'a';
        if(!chd[p][tmp])
        {
            memset(chd[sz],0,sizeof(chd[sz]));
            word[sz]=0;
            //cout<<p<<" * "<<tmp<<" "<<sz<<endl;
            chd[p][tmp]=sz++;
        }
        p=chd[p][tmp];
    }
    word[p]=val;
}
int Que[maxn];
void AC()
{
    int *s=Que,*e=Que;
    for(int i=0; i<26; i++)
        if(chd[0][i])
        {
            fail[chd[0][i]]=0;
            *e++=chd[0][i];
        }
    while(s!=e)
    {
        int p=*s++;
        for(int i=0; i<26; i++)
            if(chd[p][i])
            {
                int k=chd[p][i];
                fail[k]=chd[fail[p]][i];
                *e++=k;
            }
            else
            {
                chd[p][i]=chd[fail[p]][i];
            }
    }
}
int d[1000005];
int w[1005];
int L[1005];
int solve(char *s)
{
    int p=0;
    int j=1;
    *s++;
    for(;*s;*s++)
    {
        int g = (*s)-'a';
        //cout<<p<<"!"<<g<<endl;
        p=chd[p][g];
        for(int tmp=p;tmp>0;tmp=fail[tmp])
        {
            if(word[tmp])
            {

                if(j>=L[word[tmp]]&&d[j-L[word[tmp]]]>=0)
                {
//cout<<word[tmp]<<" "<<j<<" "<<L[word[tmp]]<<endl;
                    //cout<<j<<"@@@"<<d[j]<<endl;
                    d[j]=max(d[j],d[j-L[word[tmp]]]+w[word[tmp]]);
                }

            }
        }
        j++;
    }
    return 0;
}
char s[10005],t[100];
const int inf = 0x3fffffff;
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s+1);
        init();
        int len=strlen(s+1);
        for(i=0;i<=len;i++)
            d[i]=-inf;
        d[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%s",t);
            L[i]=strlen(t);
            ins(t,i);
            scanf("%d",&w[i]);
        }
        AC();

        solve(s);
        int tmp = d[len];
        if(tmp<=-inf)tmp=-1;
        printf("%d\n",tmp);
    }
    return 0;
}
