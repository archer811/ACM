#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define SET(a,b) memset(a,b,sizeof(a))
#define MAXN 500001
using namespace std;
char s[MAXN];
char ans[MAXN];
int n;
bool hash[MAXN];
int Log2(int t)
{
    int tL = -1;
    while (t)
    {
        tL++;
        t >>= 1;
    }
    return tL;
}
bool Chk(int len)
{
    SET(hash, 0);
    int val = 0;
    int i;
    for (i=0; i<len; i++)
    {
        val <<= 1;
        if (s[i] == 'b')
            val++;
    }
    //
    int mod = 1 << len;
    hash[val] = 1;
    for (i=len; i<n; i++)
    {
        val <<= 1;
        val %= mod;
        if (s[i] == 'b')
        {
            val++;
        }
        hash[val] = 1;
    }
    //
    for (i=0; i<mod; i++)
    {
        if (!hash[i])
            return 1;
    }
    return 0;
}
void Decode(int val, int len)
{
    int i;
    for (i=len-1; i>=0; i--)
    {
        ans[i] = val & 1 ? 'b' : 'a';
        val >>= 1;
    }
    ans[len] = '\0';
}
int main()
{
    int i;
    while(scanf("%d", &n)!=EOF)
    {
        scanf(" %s", s);
        int l = 1;
        int r = Log2(n) + 1;//[--||]
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (Chk(mid))
            {
                r = mid;
            }
            else
                l = mid + 1;
            if (l + 1 == r)
            {
                if (Chk(l))
                    r = l;
                else
                    l = r;
            }
        }
        if (Chk(l))
        {
            printf("%d\n", l);
            for (i=0; i<(1<<l); i++)
            {
                if (!hash[i])
                    break;
            }
            Decode(i, l);
            printf("%s\n", ans);
        }
    }

    return 0;
}
