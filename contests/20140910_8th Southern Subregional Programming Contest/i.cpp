#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
vector<int>v[606];
int b[606],a[606];
const int N= 600+600*600+5;
int main()
{
    int i,j,n,k,p;
    while(scanf("%d%d%d",&n,&k,&p)!=EOF)
    {
        for(i=1;i<=k;i++)
            scanf("%d",&b[i]),v[i].clear();
        int c;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&c);
            v[c].push_back(i);
        }
        for(i=1;i<=k;i++)
        {
            int sz = g[i].size();
            for(j=0;j<sz;j++)
            {

            }
        }
    }
    return 0;
}
