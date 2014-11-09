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
struct O
{
    int a,b;
}g[5005];
int cmp(O x,O y)
{
    if(x.a==y.a)return x.b<y.b;
    return x.a<y.a;
}
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&g[i].a,&g[i].b);
        sort(g,g+n,cmp);
        int m= 0;
        for(i=0;i<n;i++)
        {
            int x = min(g[i].a,g[i].b);
            if(m>x)m=x=max(g[i].a,g[i].b);
            else m=x;
            //cout<<g[i].a<<" "<<g[i].b<<" "<<m<<endl;
        }
        cout<<m<<endl;
    }
    return 0;
}

