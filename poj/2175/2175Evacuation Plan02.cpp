#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

//求网络最小费用最大流,邻接阵形式
//返回最大流量,flow 返回每条边的流量,netcost 返回总费用
//传入网络节点数n,容量mat,单位费用cost,源点source,汇点sink
#define MAXN 203
#define inf 1000000000
int x[MAXN];
int y[MAXN];
int num[MAXN];
int map[MAXN][MAXN];
int g[MAXN][MAXN];
int flow[MAXN][MAXN];
int cost[MAXN][MAXN];
int mat[MAXN][MAXN];
bool flag;
int min_cost_max_flow(int n, int mat[][MAXN], int cost[][MAXN], int source, int sink, int
                      flow[][MAXN], int &netcost)
{
    //min[]最小费用
    //d[]最大增广量
    //pre[]
    int pre[MAXN], min[MAXN], d[MAXN], i, j, t, tag;
    flag = false;
    if (source == sink) return inf;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; flow[i][j++] = 0);
    for (netcost = 0;;)
    {
        for (i = 0; i < n; i++)
            pre[i] = 0, min[i] = inf;
        //tag:标记,如果从当前节点t找不到一条可增广的线段,就跳出循环
        for(pre[source] = source + 1, min[source] = 0, d[source] = inf, tag = 1; tag;)
            for (tag = t = 0; t < n; t++)
                if (d[t])
                    for (i = 0; i < n; i++)
                        if (j = mat[t][i] - flow[t][i] && min[t] + cost[t][i] < min[i])
                            tag = 1, min[i] = min[t] + cost[t][i], pre[i] = t + 1, d[i] = d[t] < j ? d[t] : j;
                        else if (j = flow[i][t] && min[t] < inf && min[t] - cost[i][t] < min[i])
                            tag = 1, min[i] = min[t] - cost[i][t], pre[i] = -t - 1, d[i] = d[t] < j ? d[t] : j;
        if (!pre[sink]) break;//找不到增广路就退出
        //修改找到的增广路上的各段的流量

        for (netcost += min[sink] * d[i=sink]; i != source;)
        {
            int temp = i;
            if (pre[i] > 0)
                flow[pre[i] - 1][i] += d[sink], i = pre[i] - 1;
            else
                flow[i][-pre[i] - 1] -= d[sink], i = -pre[i] - 1;
            if(i != source && temp != sink)
            {
                g[i][temp] += d[sink];
            }
        }
    }
    for (j = i = 0; i < n; j += flow[source][i++]);
    return j;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(map, 0, sizeof(map));
    memset(g, 0, sizeof(g));
    memset(mat, 0, sizeof(mat));
    int i, j;
    for(i = 0; i < n + m; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &num[i]);
    }
    memset(cost, 0, sizeof(cost));
    memset(mat, 0, sizeof(mat));
    for(i = 0; i < n; i++)
    {
        for(j = n; j < n + m; j++)
        {
            mat[i][j] = inf;
            cost[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]) + 1;
        }
    }
    for(i = 0; i < n; i++)
        mat[n+m][i] = num[i];
    for(i = n; i < n + m; i++)
        mat[i][n+m+1] = num[i];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    int total = 0;
    int ans = min_cost_max_flow(n + m + 2, mat, cost, n + m, n + m + 1, flow, total);
    for(i = 0; i < n; i++)
    {
        for(j = n; j < n + m; j++)
        {
            if(g[i][j] != map[i][j-n])
                flag = true;
        }
    }
    if(flag == false)
        printf("OPTIMAL\n");
    else
    {
        printf("SUBOPTIMAL\n");
        for(i = 0; i < n; i++)
        {
            for(j = n; j < n + m; j++)
            {
                printf("%d", g[i][j]);
                if(j != n + m - 1)
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }

}

