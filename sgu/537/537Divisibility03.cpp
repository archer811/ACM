#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 2222222;
bool v[N];

char s[20];
bool use[10];
int vis[255];
int n, r, p[N];
LL all[100000];
LL res;

LL gcd(LL a, LL b){
    if(!b) return a;
    return gcd(b, a%b);
}

int sz;
void dfs(int now, LL val){
    if(res == 1) return ;
    if(sz>155555) return ;
    if(now == n){
        sz++;
        if(res == -1) res = val;
        else res = gcd(res, val);
        return ;
    }
    if(~vis[s[now]]){
        dfs(now+1, val*10+vis[s[now]]);
    }
    else{
        int x, i;
        if(now==0) x = 1;else x = 0;
        for(i=x;i<=9;++i) if(!use[i]){
            use[i] = 1;
            vis[s[now]] = i;
            dfs(now+1, val*10+i);
            vis[s[now]] = -1;
            use[i] = 0;
        }
    }
}

LL ans[100005];
int cnt[100005];
int tot;
void go(int now, LL get){
    if(now == r){
        ans[tot++] = get;
        return ;
    }
    for(int i = 0; i <= cnt[now]; ++i){
        go(now+1, get);
        get*=all[now];
    }
}

int main(){
    int tt, cal=0, num = 0, i, j;
    for(i=2;i<N;++i){
        if(!v[i]) p[num++] = i;
        for(j=i+i;j<N;j+=i)
        v[j] = 1;
    }


    scanf("%d",&tt);
    while(tt--){
        printf("Case %d:", ++cal);
        scanf("%s",s);
        n = strlen(s);
        memset(vis, -1, sizeof(vis));
        memset(use, 0, sizeof(use));
        res = -1;
        sz = 0;
        dfs(0, 0);
        if(res == 1){
            puts(" 1");
            continue;
        }
        r = 0;
        tot = 0;
        for(i=0;i<num;++i) if(res%p[i]==0){
            cnt[r] = 0;
            all[r] = p[i];
            while(res % p[i] == 0){
                cnt[r]++;
                res /= p[i];
            }
            ++r;
        }
        if(res != 1){
            cnt[r] = 1;
            all[r] = res;
            ++r;
        }
        go(0, 1);
        sort(ans, ans+tot);
        for(int i=0;i<tot;++i) printf(" %I64d", ans[i]);
        puts("");
    }
    return 0;
}
