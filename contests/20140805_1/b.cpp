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
int in[maxn],f[maxn];
vector<int>v[maxn];
int d[maxn],mark[maxn];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(in,0,sizeof(in));
        memset(mark,0,sizeof(mark));
        for(i=1;i<=2004;i++)
        {
            v[i].clear();d[i]=0;
        }

        for(i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            mark[a]=1;mark[b]=1;
            v[b].push_back(a);
            in[a]++;
        }
        queue<int>q;
        for(i=1;i<=2004;i++)
        {
            if(in[i]==0&&mark[i]){q.push(i);}
        }
        while(!q.empty())
        {
            int u = q.front();q.pop();
            for(i=0;i<v[u].size();i++)
            {
                int v2=v[u][i];
                //cout<<u<<"*"<<v2<<endl;
                d[v2]=d[u]+1;
                q.push(v2);
            }
        }
//        for(i=1;i<=n+1;i++)
//            cout<<i<<" "<<d[i]<<endl;
        if(d[1]<d[2])
            puts("You are my younger");
        else if(d[1]>d[2])
            puts("You are my elder");
        else puts("You are my brother");
    }
    return 0;
}
