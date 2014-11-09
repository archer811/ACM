#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=26000000,inf=0x3f3f3f3f;
#define ll long long
//const ll linf=1122334455667788990;
ll x[maxm];
ll maze[maxm];
set<pair<int,int> >st;
set<pair<int,int> >::iterator pre,nxt;
pair<int,int>coor[maxm];
vector<int>ans;

int main()
{
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
    int x0,a,b,c,d,n,m,q,u,v;
    while (~scanf("%d%d%d%d%d",&x0,&a,&b,&c,&d))
    {
        st.clear();
        ans.clear();


        scanf("%d%d%d",&n,&m,&q);
        x[0]=x0;
        for(int i=1;i<=n*m;i++)
            x[i]=(a*x[i-1]%d*x[i-1]%d+b*x[i-1]%d+c)%d, maze[i]=i;
        for(int i=1;i<=n*m;i++)
            swap(maze[i],maze[x[i]%i+1]);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&u,&v);
            swap(maze[u],maze[v]);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                coor[maze[i*m+j+1]]=MP(i+1,j+1);
        st.insert(MP(0,0));
        st.insert(MP(n+1,m+1));
        for (int i=1;i<=n*m;i++)
        {
            nxt=st.lower_bound(coor[i]);
            pre=nxt;
            pre--;
            if (pre->second<=coor[i].second&&nxt->second>=coor[i].second)
            {
                st.insert(coor[i]);
                ans.push_back(i);
            }
        }
        int len=ans.size();
        for (int i=0;i<len;i++)
            printf("%d%c",ans[i],i==len-1?'\n':' ');
    }
    return 0;
}
/*
【样例输入1】
1 3 5 1 71
3 4 3
1 7
9 9
4 9
【样例输出1】
1 2 6 8 9 12

【样例输入2】
654321 209 111 23 70000001
10 10 0
【样例输出2】
1 3 7 10 14 15 16 21 23 30 44 52 55 70 72 88 94 95 97

【样例输入3】
123456 137 701 101 10000007
20 20 0
【样例输出3】
1 10 12 14 16 26 32 38 44 46 61 81 84 101 126 128 135
140 152 156 201 206 237 242 243 253 259 269 278 279 291 298
338 345 347 352 354 383 395


*/
