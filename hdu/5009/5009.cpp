#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
inline void rd(int &n)
{
    n = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') n *= 10, n += (c - '0'),c = getchar();
}
#define N 50005
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define Lson(x) tree[x].l
#define Rson(x) tree[x].r
#define Sum(x) tree[x].sum
#define Lazy(x) tree[x].lazy
inline int Mid(int l, int r)
{
    return (l+r)>>1;
}
typedef long long ll;
struct node
{
    int l, r;
    int sum, lazy;
} tree[N<<2];
void push_down(int id)
{
    if(Lson(id)==Rson(id))return ;
    if(Lazy(id))
    {
        Sum(Lson(id)) += Lazy(id);
        Sum(Rson(id)) += Lazy(id);
        Lazy(Lson(id)) += Lazy(id);
        Lazy(Rson(id)) += Lazy(id);
        Lazy(id) = 0;
    }
}
void push_up(int id)
{
    Sum(id) = Sum(L(id)) + Sum(R(id));
}
void build(int l, int r, int id)
{
    Lson(id) = l;
    Rson(id) = r;
    Sum(id) = Lazy(id) = 0;
    if(l==r) return;
    int mid = Mid(l, r);
    build(l, mid, L(id));
    build(mid+1, r, R(id));
}
void updata(int l, int r, int val, int id)
{
    push_down(id);
    if(l == Lson(id) && Rson(id) == r)
    {
        Sum(id) += val;
        Lazy(id) += val;
        return ;
    }
    int mid = Mid(Lson(id), Rson(id));
    if(mid < l)
        updata(l, r, val, R(id));
    else if(r <= mid)
        updata(l, r, val, L(id));
    else
    {
        updata(l, mid, val, L(id));
        updata(mid+1, r, val, R(id));
    }
    push_up(id);
}
int query(int l, int r, int id)
{
    push_down(id);
    if(l == Lson(id) && Rson(id) == r)
        return Sum(id);
    int mid = Mid(Lson(id), Rson(id));
    int ans ;
    if(mid < l)
        ans = query(l, r, R(id));
    else if(r <= mid)
        ans = query(l, r, L(id));
    else ans = query(l, mid, L(id)) + query(mid+1, r, R(id));
    push_up(id);
    return ans;
}

vector<int>G;
int n, a[N], pos[N], dp[N]; //sum[i]表示从i点到当前点的颜色数量
int stack[N];
int gg;
int solve()
{
    build(1, n, 1);

    memset(pos, 0, sizeof pos);
    pos[a[1]] = 1;
    dp[1] = 1;
    dp[0] = 0;
    updata(1, 1, 1, 1);
    int top = 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = i;
        if(pos[a[i]])
        {
            updata(pos[a[i]], pos[a[i]], -1, 1);
        }
        updata(i, i, 1, 1);
        pos[a[i]] = i;
        int D = max(1, i - gg);
        //cout<<i<<"*"<<D<<endl;
        for(int j = i; j >= D; j--)
        {
            int sum = query(j, i, 1);
            if(sum*sum >= dp[i])break;
            if(dp[i] > dp[j-1] + sum*sum)
            {
                dp[i] = dp[j-1] + sum*sum;
            }
        }
    }
    return dp[n];
}
int main()
{
    while(~scanf("%d",&n))
    {
        G.clear();
        a[0] = -1;
        for(int i = 1; i <= n; i++)
        {
            rd(a[i]);
            if (a[i] == a[i - 1])
            {
                n--;
                i--;
                continue;
            }
            G.push_back(a[i]);
        }
        sort(G.begin(), G.end());
        G.erase(unique(G.begin(),G.end()), G.end());
        gg = sqrt(n);
        for(int i = 1; i <= n; i++)a[i] = lower_bound(G.begin(), G.end(), a[i])-G.begin();

        printf("%d\n", solve());
    }
    return 0;
}
/*

9
1 2 1 2 3 1 2 1 2

12
1 2 3 1 2 3 1 2 3 1 2 3

6
1 2 3 1 2 3

6
3 1 2 1 2 3

8
3 1 2 2 1 2 3 2

8

3 1 2 1 2 1 2 3
ans :
9

9

6s

6

7

6


*/
