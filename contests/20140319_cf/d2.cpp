#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int a[][3]={-1, -1, 1,
-1, -1, 2,
-1, 1, 0,
-1, 1, 1,
-1, 2 ,-1,
0, 0, 0,
0, 0, 1,
0, 1 ,-1,
1, -1 ,-1,
1, 0 ,0,
1, 0, 1,
1, 1, -1,
2, -1, -1};
char s[1000006];
const int N = 13;
#define ll __int64
struct matrix
{
    ll m[N][N];
};
const ll mod = 1000000007
matrix add(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            c.m[i][j]=0;
            c.m[i][j]=(a.m[i][j]+b.m[i][j])%mod;
        }
    }
}
int main()
{
    int i,j;
    while(cin>>s)
    {
        int len = strlen(s);

    }
}
