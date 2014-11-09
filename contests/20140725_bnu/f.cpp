#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#include<set>
#include<ctime>
using namespace std;
const int maxn=100000+100;
struct node
{
    int l,r;
    int id;
    bool friend operator <(node a,node b)
    {
        if (a.l!=b.l) return a.l<b.l;
        return a.r<b.r;
    }
}an[maxn];
vector<int> G[maxn];
int main()
{
    int n;
    while (cin>>n)
    {
        for (int i=0 ;i<n ;i++) {
            scanf("%d%d",&an[i].l,&an[i].r);
            an[i].id=i;
        }
        sort(an,an+n);
        for (int i=0 ;i<n ;i++) G[i].clear();
        int count=1;
        int cnt=0;
        G[cnt].push_back(an[0].id);
        int r=an[0].r;
        int flag=0;
        for (int i=1 ;i<n ;i++)
        {
            if (an[i].l<r)
            {
                G[cnt].push_back(an[i].id);
                r=min(r,an[i].r);
                flag=0;
            }
            else
            {
                cnt++;
                count++;
                G[cnt].push_back(an[i].id);
                r=an[i].r;
                flag=1;
            }
        }
        printf("%d\n",count);
        for (int i=0 ;i<=cnt ;i++)
        {
            int u=G[i][0];
            printf("%d",u+1);
            for (int j=1 ;j<G[i].size() ;j++)
                printf(" %d",G[i][j]+1);
            printf("\n");
        }
        puts("");
    }
    return 0;
}
