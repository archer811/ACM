/* ***********************************************
Author        :kuangbin
Created Time  :2013-9-11 12:30:12
File Name     :2013-9-11\1010.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElogE)
 * 注意对vector<Edge>E[MAXN]进行初始化后加边
 */
const int INF=0x3f3f3f3f;
const int MAXN=1000010;
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n,int start)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int N,M,C;
    scanf("%d",&T);
    int iCase = 0;
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int i = 1;i <= 3*N;i++) E[i].clear();
        int u,v,w;
        for(int i = 1;i <= N;i++)
        {
            scanf("%d",&u);
            //addedge(i,N + 2*u - 1,0);
            //addedge(N + 2*u ,i,0);
            addedge(N+u,i,0);
            addedge(i,N+u*2,0);
        }
        for(int i = 1;i < N;i++)
        {
            //addedge(N + 2*i-1,N + 2*(i+1),C);
            //addedge(N + 2*(i+1)-1,N + 2*i,C);
            addedge(N+i*2,N+i+1,C);
            addedge(N+(i+1)*2,N+i,C);
        }
        while(M--)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        Dijkstra(3*N,1);
        iCase++;
        if(dist[N] == INF)dist[N] = -1;
        printf("Case #%d: %d\n",iCase,dist[N]);
    }
    return 0;
}
