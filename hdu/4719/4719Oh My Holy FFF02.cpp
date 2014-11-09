#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL __int64
#define MAXN 100005
using namespace std ;

int n, L, cnt ;
int h[MAXN], ord[MAXN], rk[MAXN] ;
LL dp[MAXN] ;
const LL INF = 1999999999999999 ;

LL mx[MAXN<<2] ;
inline LL max(LL x, LL y) {return x > y ? x : y ; }
inline bool comp(int i, int j) {return h[i] == h[j] ? i > j : h[i] < h[j] ; }
inline void Up(int rt) { mx[rt] = max(mx[rt<<1], mx[rt<<1|1]) ; }

void build(int rt, int l, int r)
{
    mx[rt] = -INF ;
    if(l == r) return ;
    int mid = l+r >> 1 ;
    build(rt<<1, l, mid) ;
    build(rt<<1|1, mid+1, r) ;
}
void updata(int rt, int L, int R, int i, LL x)
{
    if(L == R)
    {
        mx[rt] = x ;
        return ;
    }
    int mid = L+R >> 1 ;
    if(mid >= i) updata(rt<<1, L, mid, i, x) ;
    else updata(rt<<1|1, mid+1, R, i, x) ;
    Up(rt) ;
}
LL query(int rt, int L, int R, int l, int r)
{
    if(L == l && R == r) return mx[rt] ;
    int mid = L+R >> 1 ;
    if(mid >= r) return query(rt<<1, L, mid, l, r) ;
    else if(mid < l) return query(rt<<1|1, mid+1, R, l, r) ;
    else
    {
        LL lx = query(rt<<1, L, mid, l, mid) ;
        LL rx = query(rt<<1|1, mid+1, R, mid+1, r) ;
        return max(lx, rx) ;
    }
}
LL solve()
{
    int i, r ;
    LL tmp ;
    build(1, 1, n) ;
    for(i = 1 ; i <= n ; i ++) ord[i] = i ;
    sort(ord+1, ord+1+n, comp) ;
    for(i = 1 ; i <= n ; i ++) rk[ord[i]] = i ;
    for(i = 1 ; i <= n ; i ++)
    {
        r = rk[i]-1 ;
        //cout<<i<<"f"<<rk[i]<<endl;
        if(i-L < 1) dp[i] = 0 ;
        else dp[i] = -INF ;
        if(r > 0) tmp = query(1, 1, n, 1, r) ;
        else tmp = -INF ;
        dp[i] = max(dp[i], tmp) ;
        if(dp[i] != -INF )
        {
            dp[i] += (LL)h[i]*h[i] ;
            updata(1, 1, n, rk[i], dp[i]-h[i]) ;
        }
        else updata(1, 1, n, rk[i], -INF) ;
        if(i-L > 0) updata(1, 1, n, rk[i-L], -INF) ;
        //cout<<i<<" "<<dp[n]<<endl;
    }
    return dp[n] ;
}
int main()
{
    int i, T, cas = 1 ;
    scanf("%d", &T) ;
    h[0] = dp[0] = 0 ;
    while (T --)
    {
        scanf("%d %d", &n, &L) ;
        for(i = 1 ; i <= n ; i ++) scanf("%d", &h[i]) ;
        printf("Case #%d: ", cas ++) ;
        LL ans = solve() ;
        if(ans != -INF) printf("%I64d\n", ans) ;
        else puts("No solution") ;
    }
}
