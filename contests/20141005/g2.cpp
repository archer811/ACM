#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int NN=420;

int n,m;
bool mp[NN][NN];

int S,T,cnt,ans[NN];
bool vis[NN];
void _reverse(int l,int r)
{
    while (l<r)
    {
        swap(ans[l],ans[r]);
        l++; r--;
    }
}
void expand()
{
    for (;;)
    {
        bool flag=false;
        for (int i=1; i<=n; i++)
        {
            if (!vis[i] && mp[T][i])
            {
                ans[cnt++]=i;
                T=i;
                vis[i]=true;
                flag=true;
                break;
            }
        }
        if (!flag) break;
    }
}
void hamiltun()
{
    memset(vis,false,sizeof(vis));

    S=1;
    for (T=2; T<=n; T++) if (mp[S][T]) break; //任意找两个相邻的节点S和T
    cnt=2;
    ans[0]=S; ans[1]=T;
    vis[S]=true; vis[T]=true;
    while (1)
    {
        expand(); //在它们基础上扩展出一条尽量长的没有重复节点的路径:步骤1
        _reverse(0,cnt-1);
        swap(S,T);
        expand(); //在它们基础上扩展出一条尽量长的没有重复节点的路径
        int mid=0;
        if (!mp[S][T]) //若S与T不相邻,可以构造出一个回路使新的S和T相邻
        {
            for (int i=1; i<cnt-2; i++)
            //设路径S→T上有k+2个节点,依次为S,v1,v2…… vk和T.
            //可以证明存在节点vi,i∈[1,k),满足vi与T相邻,且vi+1与S相邻
            {
                if (mp[ans[i]][T] && mp[ans[i+1]][S])
                {
                    mid=i+1; break;
                }
            }
            _reverse(mid,cnt-1);//把原路径变成S→vi→T→vi+1→S,即形成了一个回路
            T=ans[cnt-1];
        }
        if (cnt==n) break;
        //现在我们有了一个没有重复节点的回路.如果它的长度为N,则汉密尔顿回路就找到了
        //否则,由于整个图是连通的,所以在该回路上,一定存在一点与回路以外的点相邻
        //那么从该点处把回路断开,就变回了一条路径,再按照步骤1的方法尽量扩展路径
        for (int i=1; i<=n; i++)
        {
            if (!vis[i])
            {
                int j;
                for (j=1; j<cnt-1; j++) if (mp[ans[j]][i]) break;
                if (mp[ans[j]][i])
                {
                    T=i; mid=j;
                    break;
                }
            }
        }
        S=ans[mid-1];
        _reverse(0,mid-1);
        _reverse(mid,cnt-1);
        ans[cnt++]=T;
        vis[T]=true;
    }
}

int main()
{
    int u,v;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mp,0,sizeof(mp));
        for (int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            mp[u][v]=mp[v][u]=1;
        }
        hamiltun();
        printf("%d",ans[0]);
        for (int i=1; i<cnt; i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
