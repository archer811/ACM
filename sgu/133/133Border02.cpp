#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=16010;
int n;
struct Node
{
    int x,y;
} node[MAXN];
int cmp(Node a,Node b)
{
    return a.x<b.x;
}
int main()
{
    //freopen("text.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&node[i].x,&node[i].y);
    sort(node,node+n,cmp);
    int cnt=0,Max=node[0].y;
    for(int i=1; i<n; i++)
    {
        if(node[i].y<Max)
            cnt++;
        Max=max(Max,node[i].y);
    }

    printf("%d\n",cnt);
    return 0;
}
