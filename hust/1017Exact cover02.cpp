#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
const int MAXS = 110000;
const int inf = 0x3f3f3f3f;

int L[MAXS], R[MAXS], U[MAXS], D[MAXS];
int C[MAXS], H[MAXS], S[MAXN];
int X[MAXS], ans[MAXN];
int n, m, size, cnt;

void remove(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
        for (int j = R[i]; j != i; j = R[j])
            U[D[j]] = U[j], D[U[j]] = D[j], S[C[j]]--;
}

void resume(int c)
{
    for (int i = U[c]; i != c; i = U[i])
        for (int j = L[i]; j != i; j = L[j])
            U[D[j]] = j, D[U[j]] = j, S[C[j]]++;
    L[R[c]] = c; R[L[c]] = c;
}

void link(int r, int c)
{
    C[size] = c; S[c]++;
    U[D[c]] = size;
    D[size] = D[c];
    U[size] = c;
    D[c] = size;
    if (H[r] < 0) H[r] = L[size] = R[size] = size;
    else
    {
        L[R[H[r]]] = size;
        R[size] = R[H[r]];
        R[H[r]] = size;
        L[size] = H[r];
    }
    X[size++] = r;;
}

int dfs()
{
    if (R[0] == 0) return 1;
    int mn = inf, id;
    for (int i = R[0]; i; i = R[i])
        if (C[i] < mn) mn = C[id = i];
    remove(id);
    for (int i = D[id]; i != id; i = D[i])
    {
        ans[cnt++] = i;
        for (int j = L[i]; j != i; j = L[j]) remove(C[j]);
        if (dfs()) return 1;
        for (int j = R[i]; j != i; j = R[j]) resume(C[j]);
        cnt--;
    }
    resume(id);
    return 0;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i <= m; i++)
        {
            S[i] = 0;
            L[i + 1] = i;
            R[i] = i + 1;
            D[i] = U[i] = i;
        }
        R[m] = 0; size = m + 1; cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            H[i] = -1;
            int num; scanf("%d", &num);
            for (int j = 0; j < num; j++)
            {
                int c; scanf("%d", &c);
                link(i, c);
            }
        }
        if (dfs())
        {
            printf("%d", cnt);
            for (int i = 0; i < cnt; i++)
                printf(" %d", X[ans[i]]);
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
