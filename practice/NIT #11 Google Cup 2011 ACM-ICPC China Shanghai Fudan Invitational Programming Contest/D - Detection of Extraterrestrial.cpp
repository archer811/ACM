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
#define ll unsigned int
const int maxn = 1005;
ll base[maxn];
const ll MAGIC = 131;
ll h[maxn];
void init_hash(int l,char *s)
{
    h[0]=0;
    for(int i=1; i<=l; i++)
        h[i]=h[i-1]*MAGIC+s[i-1];
    base[0]=1;
    for(int i=1; i<=l; i++)
        base[i] = base[i-1]*MAGIC;
}
ll string_hash(int l,int r)
{
    return h[r]-h[l]*base[r-l];
}
char s[maxn];
int ans[maxn];
int main()
{
    int i,j,t,k;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%s",s);
        int len = strlen(s);
        init_hash(len,s);
        for(i=1; i<=len; i++)
            ans[i]=0;
        for(i=1; i<=len; i++)
        {
            for(j=0; j<i; j++)
            {
                int k=j;
                ll pre=-1;
                int num=0;
                while(k+i-1<len)
                {
                    ll g = string_hash(k,k+i);
                    if(pre==-1)
                    {
                        pre=g;
                        num=1;
                    }
                    else
                    {
                        if(g==pre)num++;
                        else
                        {

                            pre=g;
                            num=1;
                        }
                    }
                    if(num!=0)
                    {
                        int tmp = num*i;
                        if(ans[num]<tmp)
                            ans[num]=tmp;
                    }
                    k+=i;
                }
            }
        }
        printf("Case #%d:",++cas);
        for(i=1; i<=len; i++)
            printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}
