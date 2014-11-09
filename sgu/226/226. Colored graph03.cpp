#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <memory.h>
using namespace std;
#define SQR(a) ((a) * (a))
const int maxn = 205;
struct Node
{
	int x, d, c;
}now,next;
Node node(int x, int d, int c)
{
	Node res; res.x = x; res.d = d; res.c = c;
	return res;
}

int mat[maxn][maxn];
bool mark[maxn][4];
queue<Node>q;
int n, m;

int bfs()
{
	now = node(0, 0, 0);
	q.push(now);
	while (!q.empty())
	{
	    now = q.front();q.pop();
		int x = now.x, d = now.d + 1, c = now.c;
		for (int i = 1; i < n; i ++)
			if (mat[x][i] != 0 && mat[x][i] != c)
			{
				if (!mark[i][mat[x][i]])
				{
					if (i == n - 1)
						return d;
					mark[i][mat[x][i]] = true;
					next = node(i, d, mat[x][i]);
					q.push(next);
				}
			}
	}
	return -1;
}

int main ()
{
	cin >> n >> m;
	for (int i = 0; i < m; i ++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x --, y --;
		mat[x][y] = c;
	}
	cout << bfs() << endl;
	return 0;
}
