#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int fa[100],num[105];
int find(int a)
{
    if(fa[a]==a)return a;
    return fa[a]=find(fa[a]);
}
void f(int a,int b)
{
    int x= find(a),y=find(b);
    if(x!=y)
    {
        fa[x]=y;
        num[y]+=num[x];
    }
}
#define ll long long
int main()
{
    int i,j,n,m;
    while(cin>>n>>m)
    {
        for(i=1;i<=n;i++)
            fa[i]=i,num[i]=1;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            f(a,b);
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(fa[i]==i)sum+=num[i]-1;
        }
        ll ans=1;
        for(i=0;i<sum;i++)
            ans=ans*(ll)2;
        cout<<ans<<endl;
    }
    return 0;
}
