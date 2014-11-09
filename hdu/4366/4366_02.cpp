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
const int magic = 250;
const int maxn = 55555;
struct staff
{
    int l,a;
}list[maxn],sorted[maxn],arr[maxn];
int cmp(staff a,staff b)
{
    return a.a<b.a;
}
vector<int>adj[maxn];
map<int,int>M;
int tot=0;
int pos[maxn],siz[maxn];
int dfs(int u)
{
    pos[u]=tot;
    list[tot]=arr[u];
    sorted[tot]=arr[u];
    tot++;
    int res=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        res += dfs(v);
    }
    return siz[u]=res;
}
int maxl[maxn];
int work(int l,int r,int val)
{
    if(sorted[r].a<=val)return -1;
    if(sorted[l].a>val)return maxl[l];
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(sorted[mid].a > val) r=mid;
        else l=mid+1;
    }
    return maxl[l];
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
        {
            adj[i].clear();
            arr[i].l=arr[i].a=-1;
            list[i]=sorted[i]=arr[i];
        }
        M.clear();
        M[-1]=-1;
        for(i=1;i<n;i++)
        {
            int fa,l,a;
            scanf("%d%d%d",&fa,&l,&a);
            adj[fa].push_back(i);
            M[arr[i].l=l]=i;
            arr[i].a=a;
        }
        tot=0;
        dfs(0);
        for(i=0;i<n;i+=magic)
        {
            j = i+magic;
            if(j>n)break;
            sort(sorted+i,sorted+j,cmp);
            maxl[j-1]=sorted[j-1].l;
            for(int k=j-2;k>=i;k--)
            {
                maxl[k] = max(maxl[k+1],sorted[k].l);
            }
        }
        while(q--)
        {
            int st;
            scanf("%d",&st);
            st = pos[st];
            int ed = st+siz[st]-1;
            int ans=-1;
            int val=list[st].a;
            for(i=st;i<=ed;)
            {
                if(i%magic==0&&i+magic-1<=ed)
                {
                    int tmp = work(i,i+magic-1,val);
                    if(tmp>ans)
                        ans=tmp;
                    i+=magic;
                }
                else
                {
                    if(list[i].a>val&&list[i].l>ans)
                        ans=list[i].l;
                    i++;
                }
            }
            printf("%d\n",M[ans]);
        }
    }
}
