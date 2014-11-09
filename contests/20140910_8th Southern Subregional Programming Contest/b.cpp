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
struct array
{
    int id;
    int v;
} g[100005],o[maxn];
int cmp(array a,array b)
{
    if(a.v==b.v)return a.id<b.id;
    return a.v<b.v;
}
int flag[10005];
int main()
{
    int i,j,k;
    while(scanf("%s%d",s,&k)!=EOF)
    {
        int len = strlen(s);
        for(i=0; i<len; i++)
        {
            g[i].id=i;
            g[i].v=s[i]-'0';
        }
        memset(flag,0,sizeof(flag));

        int now = 0;
        while(k && now<len)
        {
            int M=-1,ff=-1;
            for(i=now; i<now+k&&i<len; i++)
            {
                if(g[i].v>M)
                {
                    M=g[i].v;
                    ff=i;
                }
            }
            //cout<<ff<<"  "<<k<<"  "<<now<<endl;
            k = k-(ff-now);
            flag[ff]=1;
            now = ff+1;
        }



//        int tt=0;
//        for(j=0; j<len; j++)
//        {
//            if(flag[j])
//            o[tt++]=g[j];
//        }
//        sort(o,o+tt,cmp);
//        for(i=0; i<k; i++)
//        {
//            flag[o[i].id]=0;
//        }

        for(i=0; i<len; i++)
        {
            if(flag[i])printf("%c",s[i]);
        }
        puts("");
    }
    return 0;
}
