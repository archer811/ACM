#include<cstdio>
#include<cstring>
#define maxn (1<<20)
typedef long long u64;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mod  12582917

typedef struct S
{
    u64 left, right;
} TREE;
TREE tree[maxn << 1];
u64 exp[maxn];
char str[maxn];
char op[3];

void print_exp()
{
    exp[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        exp[i] = (exp[i - 1]*26) % mod;
    }
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        tree[rt].left = tree[rt].right = str[l] - 'a';
        //      printf("l=%lld r=%lld\n",tree[rt].left,tree[rt].right);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    tree[rt].left = (exp[r - m] * tree[rt << 1].left + tree[rt << 1 | 1].left) % mod;
    tree[rt].right = (exp[m - l + 1] * tree[rt << 1 | 1].right + tree[rt << 1].right) % mod;

}

void update(int l, int r, int rt, int p, char ch)
{
    if (l == r)
    {
        tree[rt].left = tree[rt].right = ch - 'a';
        // str[l] = ch;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m)
    {
        update(lson, p, ch);
    }
    else
    {
        update(rson, p, ch);
    }
    tree[rt].left = (exp[r - m] * tree[rt << 1].left + tree[rt << 1 | 1].left) % mod;
    tree[rt].right = (exp[m - l + 1] * tree[rt << 1 | 1].right + tree[rt << 1].right) % mod;
    //  printf("%d %d : l=%lld r=%lld\n",l,r,tree[rt].left,tree[rt].right);
}

TREE query(int l, int r, int rt, int a, int b)
{
    if (l == a && r == b)
    {
        return tree[rt];
    }
    int m = (l + r) >> 1;
    if (b <= m)
    {
        return query(lson, a, b);
    }
    else if (a > m)
    {
        return query(rson, a, b);
    }
    else
    {
        TREE ans1, ans2, ans;
        ans1 = query(lson, a, m);
        ans2 = query(rson, m + 1, b);
        ans.left = (exp[b - m] * ans1.left + ans2.left) % mod;
        ans.right = (exp[m - a + 1] * ans2.right + ans1.right) % mod;
        return ans;
    }
}

int main()
{
    int Q, len, i;
    int a, b;
    char ch[3];
    TREE ans;
    print_exp();
    while (scanf("%s", str + 1) != EOF)
    {
        len = strlen(str + 1);
        build(1, len, 1);
        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%s", op);
            if (op[0] == 'C')
            {
                scanf("%d%s", &a, ch);
                update(1, len, 1, a, ch[0]);
            }
            else
            {
                scanf("%d%d", &a, &b);
                ans = query(1, len, 1, a, b);
                //    printf("l=%lld r=%lld\n",ans.left,ans.right);
                if (ans.left == ans.right)
                {
                    printf("yes\n");
                }
                else
                {
                    printf("no\n");
                }
            }
        }
    }
    return 0;
}


