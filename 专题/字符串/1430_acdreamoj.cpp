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
const int maxn = 10005;

#define ll unsigned int
const ll magic = 97;
ll h[maxn],base[maxn];
inline void init_hash(int l,char *s)
{
    h[0]=0;
    for(int i=1;i<=l;i++)
        h[i]=h[i-1]*magic+s[i-1];
    base[0]=1;
    for(int i=1;i<=l;i++)
        base[i]=base[i-1]*magic;
}
inline ll string_hash(int l,int r)
{
    return h[r]-h[l]*base[r-l];
}
char s[maxn];
int main()
{
    int i,j;
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        init_hash(len,s);
        for(i=1;i<=len;i++)
        {

        }
    }
    return 0;
}
