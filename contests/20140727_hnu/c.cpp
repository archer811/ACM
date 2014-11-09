//#include <bits/stdc++.h>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <fstream>
using namespace std;
//LOOP
#define FF(i, a, b) for(int i = (a); i < (b); ++i)
#define FE(i, a, b) for(int i = (a); i <= (b); ++i)
#define FED(i, b, a) for(int i = (b); i>= (a); --i)
#define REP(i, N) for(int i = 0; i < (N); ++i)
#define CLR(A,value) memset(A,value,sizeof(A))
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
//OTHER
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()
//INPUT
#define RI(n) scanf("%d", &n)
#define RII(n, m) scanf("%d%d", &n, &m)
#define RIII(n, m, k) scanf("%d%d%d", &n, &m, &k)
#define RIV(n, m, k, p) scanf("%d%d%d%d", &n, &m, &k, &p)
#define RV(n, m, k, p, q) scanf("%d%d%d%d%d", &n, &m, &k, &p, &q)
#define RS(s) scanf("%s", s)
//OUTPUT
#define WI(n) printf("%d\n", n)
#define WS(n) printf("%s\n", n)
//debug
//#define online_judge
#ifndef online_judge
#define dt(a) << (#a) << "=" << a << " "
#define debugI(a) cout dt(a)  << endl
#define debugII(a, b) cout dt(a) dt(b) << endl
#define debugIII(a, b, c) cout dt(a) dt(b) dt(c) << endl
#define debugIV(a, b, c, d) cout dt(a) dt(b) dt(c) dt(d) << endl
#define debugV(a, b, c, d, e) cout dt(a) dt(b) dt(c) dt(d) dt(e) << endl
#else
#define debugI(v)
#define debugII(a, b)
#define debugIII(a, b, c)
#define debugIV(a, b, c, d)
#define debugV(a, b, c, d, e)
#endif
#define sqr(x) (x) * (x)
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1000000007;
const double PI = acos(-1.0);
const int MAXN = 10100;

vector<pair<int, int> > v[MAXN];
int n, m;
LL d[MAXN];
bool inq[MAXN];

void spfa()
{
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    for (int i = n; i >= 1; i--)
    {
        q.push(i);
        inq[i] = true;
    }
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        inq[x] = false;
        int xn = v[x].size();
        for (int i = 0; i < xn; i++)
        {
            pair<int, int> pp = v[x][i];
            int y = pp.first, z = pp.second;
            if (d[z] > d[y] + d[x])
            {
                d[z] = d[y] + d[x];
                if (!inq[z])
                {
                    inq[z] = true;
                    q.push(z);
                }
            }
        }
    }
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            d[i] = x;
        }
        for (int i = 0; i <= n; i++) v[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d%d%d",&z, &x, &y);
            v[x].push_back(make_pair(y, z));
            v[y].push_back(make_pair(x, z));
        }
        spfa();
        cout << d[1] << endl;
    }
    return 0;
}
