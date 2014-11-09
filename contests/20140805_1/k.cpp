#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<vector>
using namespace std;
#define ll long long
const ll mod = 1000000007;
const int maxn = 2005;
int to[maxn];
vector<int>v[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(to,-1,sizeof(to));
        int M=1;
        for(i=1;i<=n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>M)M=a;
            if(b>M)M=b;
            to[a]=b;
        }
        for(i=1;i<=M;i++)
        {

        }
        if(d[1]<d[2])
            puts("You are my younger");
        else if(d[1]>d[2])
            puts("You are my elder");
        else puts("You are my brother");
    }
    return 0;
}
