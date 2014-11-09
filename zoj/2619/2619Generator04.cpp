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

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::getline;
using std::greater;
using std::endl;
using std::multimap;
using std::fixed;
using std::setprecision;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned UNS;
typedef pair<int, int> PAIR;
typedef multimap<int, int> MMAP;

const int MAXN(15);
//const int SIGMA_SIZE(26);
const int MAXM(110);
const int MAXE(4000010);
const int MAXH(18);
const int INFI((INT_MAX-1) >> 1);
const double EPS(1e-11);
const int MOD(10007);
const ULL LIM(1000000000000000ull);

typedef long long ll;

inline bool EZ(double temp)
{
    return fabs(temp) < EPS;
}

template<typename T>
T ABS(const T &op)
{
	return op < 0? -op: op;
}

LL gcd(LL op1, LL op2)
{
	LL temp;
	while(op2)
	{
		temp = op1%op2;
		op1 = op2;
		op2 = temp;
	}
	return op1;
}

LL lcm(LL op1, LL op2)
{
	return op1/gcd(op1, op2)*op2;
}

struct MAT
{
    int r, c;
    LL arr[MAXN][MAXN];
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

    /* 模2方程组消元
    int XOR_eliminate()
    {
        int rank = 0, temp;
        for(int i = 0; i < r; ++i)
        {
            temp = i;
            for(int k = i; k < r; ++k)
                if(arr[k][i]){temp = k; break;}
            if(arr[temp][i] == 0)
            { is_free[i] = true; continue;}
            is_free[i] = false;
            ++rank;
            if(temp != i)
                for(int k = 0; k < c; ++k)
                    swap(arr[i][k], arr[temp][k]);
            for(int k = i+1; k < r; ++k)
                if(arr[k][i])
                    for(int k2 = i; k2 < c; ++k2)
                        arr[k][k2] ^= arr[i][k2];
        }
		if(rank < r)
			return rank;
        for(int i = r-1; i >= 0; --i)
        {
            for(int j = i+1; j < c-1; ++j)
                arr[i][c-1] ^= arr[j][c-1]&arr[i][j];
            if(arr[i][i] == 0 && arr[i][c-1] != 0)
                return -1;                      //有矛盾解
        }
        return rank; //返回矩阵的秩
    }
	*/

	bool gaussInt()
	{
	    cout<<r<<" ++++++++++++++++++++++++ "<<c<<endl;
		int temp;
		LL mmi;
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
					LL lc = lcm(arr[j][i], arr[i][i]);
					LL l1, l2;
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
	/*
	void gauss_eliminate()
    {
        int temp;
        long double mmx;
        for(int i = 0; i < r; ++i)
        {
            temp = i;
            mmx = fabs(arr[i][i]);
            for(int j = i+1; j < r; ++j)
                if(fabs(arr[j][i]) > mmx)
                {
                    mmx = fabs(arr[j][i]);
                    temp = j;
                }
            if(temp != i) for(int j = 0; j < c; ++j) swap(arr[temp][j],arr[i][j]);
            for(int j = c-1; j >= i; --j)
                for(int k = i+1; k < r; ++k)
                    arr[k][j] -= arr[k][i]/arr[i][i]*arr[i][j];

        }
        for(int i = r-1; i >= 0; --i)
        {
            for(int j = i+1; j < c-1; ++j)
                arr[i][c-1] -= arr[j][c-1]*arr[i][j];
            arr[i][c-1] /= arr[i][i];
        }
    }


    void gauss_jordan()
    {
        int temp;
        for(int i = 0; i < r; ++i)
        {
            temp = i;
            for(int j = i+1; j < r; ++j)
                if(fabs(arr[j][i]) > fabs(arr[temp][i])) temp = j;
            if(EZ(arr[temp][i])) continue;
            if(temp != i)
                for(int j = 0; j < c; ++j)
                    swap(arr[temp][j], arr[i][j]);
            for(int j = 0; j < r; ++j)
                if(j != i)
                    for(int k = c-1; k >= i; --k)
                        arr[j][k] -= arr[j][i]/arr[i][i]*arr[i][k];
        }
    }*/
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
        cout<<ac.size<<"***"<<endl;
        for(int i=0;i<ac.size;i++)
            cout<<i<<" "<<ac.val[i]<<endl;
        for(int i=0;i<ac.size;i++)
        {
            for(int j=0;j<=ac.size;j++)
                cout<<mat.arr[i][j]<<" ";
            cout<<endl;
        }
		mat.gaussInt();
		if(n_case)
			cout << "\n";
		cout << "Case " << ++n_case << ":\n";
		cout << mat.arr[0][ac.size] << "\n";
    }
    return 0;
}
