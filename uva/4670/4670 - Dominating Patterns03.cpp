#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 150*70;
const int max_num = 26;
int n;
char str[155][77];
struct ACAuto
{
    int f[maxn], val[maxn];
    int ch[maxn][max_num], tot;
    int idx[256];

    int new_node()
    {
        memset(ch[tot], 0, sizeof(ch[tot]));
        val[tot] = 0;
        f[tot] = 0;
        return tot++;
    }
    void init()
    {
        tot = 0;
        new_node();
        for(int i = 0; i < 26; i++)
            idx['a'+i] = i;
    }

    void insert(char *s, int id)
    {
        int i, j, p = 0;
        for(; *s; s++)
        {
            int k = idx[*s];
            if(!ch[p][k]) ch[p][k] = new_node();
            p = ch[p][k];
        }
        val[p] = id;
    }
    void getfail()
    {
        int i, j;
        queue <int> q;
        for(i = 0; i < max_num; i++)
            if(ch[0][i]) q.push(ch[0][i]);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(i = 0; i < max_num; i++)
            {
                int &v = ch[u][i];
                if(!v)
                {
                    v = ch[f[u]][i];
                    continue;
                }
                j = f[u];
                while(j && !ch[j][i]) j = f[j];
                f[v] = ch[j][i];
                q.push(v);
            }
        }
    }
    int cnt[maxn];
    void find(char *s)
    {
        memset(cnt, 0, sizeof(cnt));
        int i, j, p = 0;
        for(i = 0; s[i]; i++)
        {
            int k =  idx[s[i]];
            p = ch[p][k];
            j = p;
            while(j)
            {
                if(val[j]) cnt[val[j]]++;
                j = f[j];
            }
        }
        int ans = 0;
        for(i = 1; i <= n; i++)
            ans = max(ans, cnt[i]);
        printf("%d\n", ans);
        for(i = 1; i <= n; i++)
        {
            //printf("%d %s %d\n",i,str[i],cnt[i]);
            if(ans == cnt[i])
                printf("%s\n", str[i]);
        }

    }
} AC;
char tmp[1000006];
int main()
{
    int i, j;
    while(~scanf("%d", &n) && n)
    {
        AC.init();
        for(i = 1; i <= n; i++)
        {
            scanf("%s", str[i]);
            AC.insert(str[i], i);
        }
        AC.getfail();
        scanf("%s", tmp);
        AC.find(tmp);
    }
    return 0;
}
/*
4444
4 4
fffa
fffa
fffa
fffa
2 2
fa
fa
*/
