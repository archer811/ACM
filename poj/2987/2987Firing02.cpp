#include<iostream>
using namespace std;
const int MAX=5005;
const int inf=1<<30;
struct node
{
	int v,c,next;
}g[500000];
int dis[MAX],num[MAX],pre[MAX],cur[MAX],adj[MAX],vis[MAX];
int s,t,e,vn,n,m,cnt;
void add(int u,int v,int c)
{
	g[e].v=v; g[e].c=c; g[e].next=adj[u]; adj[u]=e++;
 	g[e].v=u; g[e].c=0; g[e].next=adj[v]; adj[v]=e++;
}
__int64 sap()
{
	int i,u,v,flag;
	__int64 flow=0,aug=inf;
	for(i=0;i<=vn;i++)
	{
		dis[i]=num[i]=0;
		cur[i]=adj[i];
	}
	num[0]=vn;
	u=s;
	pre[s]=s;
	while(dis[s]<vn)
	{
		flag=0;
		for(i=cur[u];i!=-1;i=g[i].next)
		{
			v=g[i].v;
			if(g[i].c&&dis[u]==dis[v]+1)
			{
				flag=1;
				cur[u]=i;
				pre[v]=u;
				if(aug>g[i].c)
					aug=g[i].c;
				u=v;
				if(u==t)
				{
					flow+=aug;
					while(u!=s)
					{
						u=pre[u];
						g[cur[u]].c-=aug;
						g[cur[u]^1].c+=aug;
					}
					aug=inf;
				}
				break;
			}
		}
		if(flag)
			continue;
		if(--num[dis[u]]==0)
			return flow;
		for(dis[u]=vn,i=adj[u];i!=-1;i=g[i].next)
		{
			v=g[i].v;
			if(g[i].c&&dis[v]<dis[u])
			{
				dis[u]=dis[v];
				cur[u]=i;
			}
		}
		dis[u]++;
		num[dis[u]]++;
		u=pre[u];
	}
	return flow;
}
void dfs(int u)
{
	int i,v;
	vis[u]=1;
	for(i=adj[u];i!=-1;i=g[i].next)
	{
		v=g[i].v;
		if(!vis[v]&&g[i].c)
		{
			dfs(v);
			cnt++;
		}
	}
}
int main()
{
	int i,j,a,b;
	__int64 cost,sum,max_flow;
	scanf("%d%d",&n,&m);
	memset(adj,-1,sizeof(adj));
	sum=s=e=0;t=n+1;
	vn=t+1;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&cost);
		if(cost>0)
		{
			add(s,i,cost);
			sum+=cost;
		}
		else if(cost<0)
		{
			add(i,t,-cost);
		}
	}
	j=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b,inf);
	}
	max_flow=sap();
	cnt=0;
	memset(vis,0,sizeof(vis));
	dfs(s);
	cout<<cnt<<" "<<sum-max_flow<<endl;
	return 0;
}
