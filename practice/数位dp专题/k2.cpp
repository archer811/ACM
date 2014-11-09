#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef __int64 int64;
typedef long long ll;
#define M 500005
#define N 1000005
#define max_inf 0x7f7f7f7f
#define min_inf 0x80808080
const ll mod = 100000000;
#define lc rt<<1
#define rc rt<<1|1

char str[105] , A[105] , B[105];
int dig[105] , size;
int dp[105][2][15][105];

bool Judge(char ch , int pre , int now)
{
    if (ch == '/')return pre < now;
    if (ch == '-')return pre == now;
    if (ch == '\\')return pre > now;
    return 0;
}

int Dfs(int index , int fg , int pre , int pos , int lim)
{

    if (!index)return pos == size;
    if (!lim && dp[index][fg][pre][pos] != -1)return dp[index][fg][pre][pos];
    int i , ret = 0 , up = lim ? dig[index] : 9;

    for (i = 0 ; i <= up ; i++)
    {
        if (!fg)
        {
            ret += Dfs(index-1 , i , i , 0 , lim&&i==up);
            ret %= mod;
		}
		else if (Judge(str[pos] , pre , i) && pos < size)
		{
			ret += Dfs(index-1 , 1 , i , pos+1 , lim&&i==up);
			ret %= mod;
		}
		else if (pos > 0 && Judge(str[pos-1] , pre , i))
		{
			ret += Dfs(index-1 , 1 , i , pos , lim&&i==up);
			ret %= mod;
		}
	}
	if (!lim)
	{
	    cout<<index<<" "<<fg<<" "<<pre<<" "<<pos<<" "<<
	    ret<<endl;
	    dp[index][fg][pre][pos] = ret;
	}

	return ret;
}

int Solve(char *num , int is_a)
{
    int len = 0 , lef = 0 , rig = strlen(num)-1;
    while (lef <= rig && num[lef] == '0')lef++;
    if (is_a && lef <= rig)//若当前数是A，则减一
    {
        int i;
        num[rig]--;
        for (i = rig ; i >= lef ; i--)
        {
            if (num[i]>='0')break;
            num[i] += 10;
            if (i-1>=0)num[i-1]--;
        }
         while (lef <= rig && num[lef] <= '0')lef++;

    }
    while (lef<= rig)dig[++len] = num[rig--]-'0';
    int ret = Dfs(len , 0 , 0 , 0 , 1);
    return ret;
}

int main()
{

    while (~scanf("%s",str))
    {
        memset(dp , -1 , sizeof dp);
        size = strlen(str);
        scanf("%s%s",A,B);
        printf("%08d\n",(Solve(B,0)-Solve(A,1)+mod)%mod);
    }
    return 0;
}
