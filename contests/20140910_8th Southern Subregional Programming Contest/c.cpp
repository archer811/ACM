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
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
char s[10005];
int b[10005];
int main()
{
    int i,j;
    while(gets(s))
    {
        int len = strlen(s);
        int k=0;
        for(i=0; i<len; i++)
        {
            if(i+3<len&&s[i]=='<'&&s[i+1]=='U'&&s[i+2]=='P'&&s[i+3]=='>')
            {
                b[k++]=1;
                i = i+3;
                continue;
            }
            else if(i+4<len&&s[i]=='<'&&s[i+1]=='/'&&s[i+2]=='U'&&s[i+3]=='P'
                    &&s[i+4]=='>')
            {
                k--;
                i = i+4;
                continue;
            }

            if(i+5<len&&s[i]=='<'&&s[i+1]=='D'&&s[i+2]=='O'&&s[i+3]=='W'
                    &&s[i+4]=='N'&&s[i+5]=='>')
            {
                b[k++]=2;
                i = i+5;
                continue;
            }
            else if(i+6<len&&s[i]=='<'&&s[i+1]=='/'&&s[i+2]=='D'&&s[i+3]=='O'
                    &&s[i+4]=='W'&&s[i+5]=='N'&&s[i+6]=='>')
            {
                k--;
                i = i+6;
                continue;
            }


            if(k==0)
                printf("%c",s[i]);
            else
            {
                //cout<<i<<" "<<b[k-1]<<endl;
                if(b[k-1]==2)
                {
                    if(s[i]>='A'&&s[i]<='Z')s[i]^=32;
                }
                else
                {
                    if(s[i]>='a'&&s[i]<='z')s[i]^=32;
                }
                printf("%c",s[i]);
            }
        }
        puts("");
    }
    return 0;
}
