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
    int x,y;
}a[2005];
int cmp(array s,array t)
{
    if(s.x==t.x)return s.y>t.y;
    return s.x<t.x;
}
int main()
{
    int i,j,n;
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)break;
        for(i=0;i<n;i++)
        {
            int d;
            scanf("%d",&d);
            a[i*2].x=d;
            a[i*2].y=1;
            scanf("%d",&d);
            a[i*2+1].x=d;
            a[i*2+1].y=-1;
        }

        sort(a,a+n*2,cmp);
        int M = 0;
        int s=0;
        for(i=0;i<n*2;i++)
        {
            if(a[i].y==1)
            {
                s++;
            }
            else s--;
            //cout<<i<<" "<<a[i].x<<" "<<s<<endl;
            if(s>=0&&s>M)M=s;
        }
        printf("Case %d: %d\n",++cas,M);
    }
}
