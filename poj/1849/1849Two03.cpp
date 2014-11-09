#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100005;
struct Edge
{
	int v,w;
	Edge* nxt;
}memo[N*2],*cur,*adj[N];

int dis[N];
void dfs(int u,int fa,int valu)
{
	for(Edge* it=adj[u];it;it=it->nxt)
	{
		int v=it->v,w=it->w;
		if(v==fa) continue;
		dfs(v,u,dis[v]=valu+w);
	}
}
void addEdge(int u,int v,int w)
{
	cur->v=v;	cur->w=w;
	cur->nxt=adj[u];
	adj[u]=cur++;
}
void init()
{
	cur=memo;
	memset(adj,0,sizeof(adj));
}
int main()
{
	int n,s;
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		init();

		int sum=0,ind=1;
		for(int i=0;i<n-1;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			sum+=2*w;
			addEdge(u,v,w);
			addEdge(v,u,w);
		}

		dfs(s,-1,dis[s]=0);
		for(int i=2;i<=n;i++) if(dis[ind]<dis[i]) ind=i;
		dfs(ind,-1,dis[ind]=0);
		for(int i=1;i<=n;i++) if(dis[ind]<dis[i]) ind=i;

		printf("%d\n",sum-dis[ind]);
	}
	return 0;
}
