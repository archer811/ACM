#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include<iomanip>
using namespace std;
const int MAXN(15);
const double EPS(1e-11);
template<typename T>
T ABS(const T &op)
{
	return op < 0? -op: op;
}
int gcd(int op1, int op2)
{
	int temp;
	while(op2)
	{
		temp = op1%op2;
		op1 = op2;
		op2 = temp;
	}
	return op1;
}

int lcm(int op1, int op2)
{
	return op1/gcd(op1, op2)*op2;
}

struct MAT
{
    int r, c;
    int arr[MAXN][MAXN];
    MAT(int tr, int tc): r(tr), c(tc)
    {}
    MAT()
    {}
    void reset()
    {
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                arr[i][j] = 0;
    }
    void identity()
    {
        reset();
        for(int i = 0; i < r; ++i)
            arr[i][i] = 1;
    }
	bool gaussInt()
	{
		int temp;
		int mmi;
		for(int i = 0; i < r; ++i)
		{
			mmi = ABS(arr[i][i]);
			temp = i;
			for(int j = i+1; j < r; ++j)
				if(ABS(arr[j][i]) < mmi && arr[j][i])
				{
					mmi = ABS(arr[j][i]);
					temp = j;
				}
			if(temp != i)
				for(int j = 0; j < c; ++j)
					swap(arr[i][j], arr[temp][j]);
			for(int j = i+1; j < r; ++j)
				if(arr[j][i])
				{
					int lc = lcm(arr[j][i], arr[i][i]);
					int l1, l2;
					l1 = lc/arr[j][i];
					l2 = lc/arr[i][i];
					for(int k = i; k < c; ++k)
						arr[j][k] = arr[j][k]*l1-arr[i][k]*l2;
				}
		}
		for(int i = r-1; i >= 0; --i)
		{
			for(int j = i+1; j < c-1; ++j)
				arr[i][c-1] -= arr[j][c-1]*arr[i][j];
			arr[i][c-1] /= arr[i][i];
		}
		return true;
	}
};

MAT mat;

int SIGMA_SIZE;
int que[MAXN];
int front, back;

struct AC
{
    int ch[MAXN][27];
    int f[MAXN];
    bool val[MAXN];
    int size;

    void init()
    {
        memset(ch[0], 0, sizeof(ch[0]));
        f[0] = 0;
        val[0] = false;
        size = 1;
    }
    inline int idx(char temp)
    {
        return temp-'A';
    }

    void insert(char *S)
    {
        int u = 0, id;
        for(; *S; ++S)
        {
            id = idx(*S);
            if(!ch[u][id])
            {
                memset(ch[size], 0, sizeof(ch[size]));
                val[size] = false;
                ch[u][id] = size++;
            }
            u = ch[u][id];
        }
        val[u] = true;
    }
    void construct()
    {
        front = back = 0;
        int cur, u;
        for(int i = 0; i < SIGMA_SIZE; ++i)
        {
            u = ch[0][i];
            if(u)
            {
                que[back++] = u;
                f[u] = 0;
            }
        }
        while(front < back)
        {
            cur = que[front++];
            for(int i = 0; i < SIGMA_SIZE; ++i)
            {
                u = ch[cur][i];
                if(u)
                {
                    que[back++] = u;
                    f[u] = ch[f[cur]][i];
                    val[u] |= val[f[u]];
                }
                else
                    ch[cur][i] = ch[f[cur]][i];
            }
        }
    }
};

AC ac;

bool vis[MAXN];

void dfs(int cur)  //列方程时两边同时乘上SIGMA_SIZE,这样就可以避免处以SIGMA_SIZE，否则精度损失较大，G++也过不了
{
    if(vis[cur])
        return;
    vis[cur] = true;
    mat.arr[cur][cur] = SIGMA_SIZE;
    if(ac.val[cur])
        mat.arr[cur][ac.size] = 0;
    else
        mat.arr[cur][ac.size] = SIGMA_SIZE;
    for(int i = 0; i < SIGMA_SIZE; ++i)
    {
        int tv = ac.ch[cur][i];
        if(!ac.val[cur])
			mat.arr[cur][tv] -= 1;
        dfs(tv);
    }
}

char str[15];

int main()
{
    int TC, n_case(0);
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d", &SIGMA_SIZE);
        ac.init();
        scanf("%s", str);
        ac.insert(str);
        ac.construct();
        mat.r = ac.size;
        mat.c = ac.size+1;
        mat.reset();
        memset(vis, 0, sizeof(vis));
        dfs(0);
		mat.gaussInt();
		if(n_case)
			cout << "\n";
		cout << "Case " << ++n_case << ":\n";
		cout << mat.arr[0][ac.size] << "\n";
    }
    return 0;
}
