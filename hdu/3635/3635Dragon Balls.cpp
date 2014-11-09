#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,q;
const int maxn = 10004;
int fa[maxn],num[maxn],st[maxn];
int find(int x)
{
    if(x==fa[x])return x;
    int father = find(fa[x]);
    st[x]+=st[fa[x]];
    fa[x]=father;
    return father;
}
void add(int a,int b)
{
    int x = find(a),y = find(b);
    fa[x]=y;
    num[y]+=num[x];
    //if(a==1&&b==2)cout<<a<<" ** "<<fa[a]<<endl;
    //if(a==1&&b==3)cout<<a<<" "<<find(a)<<" )) "<<num[fa[x]]<<endl;
    st[x]+=1;
    //cout<<x<<endl;
}
int main()
{
    int i,j,k,t;
    scanf("%d",&t);
    char s[2];
    int a,b;
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
            fa[i]=i,num[i]=1,st[i]=0;
        printf("Case %d:\n",++cas);
        while(q--)
        {
            scanf("%s",s);
            if(s[0]=='T')
            {
                scanf("%d%d",&a,&b);
                add(a,b);
            }
            else
            {
                scanf("%d",&a);
                find(a);
                printf("%d %d %d\n",fa[a],num[fa[a]],st[a]);
            }
        }
    }
}
