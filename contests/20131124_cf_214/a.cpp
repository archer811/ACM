#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
struct array
{
    int x,y,sum,index;
}s[6];
int cmp(array a,array b)
{
    return a.sum<b.sum;
}
int main()
{
    int i,j,k;
    int a,b,c,d,n;
    scanf("%d",&n);
    for(i=1;i<=4;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        s[i].x=min(a,b);
        s[i].y=min(c,d);
        s[i].sum=s[i].x+s[i].y;
        s[i].index=i;
    }
    sort(s+1,s+1+4,cmp);
    if(s[1].sum<=n)
    {
        cout<<s[1].index<<" "<<s[1].x<<" "<<n-s[1].x<<endl;
    }
    else cout<<"-1"<<endl;
}
