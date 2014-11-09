#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int inf = 0x3fffffff;
struct array
{
    int h,w,m;
}ans[200006];

int cmp(array x,array y)
{
    if(x.h!=y.h)return x.h<y.h;
    else if(x.w!=y.w)return x.w<y.w;
    else return x.m<y.m;
}
multiset<int>q;
multiset<int>::iterator it;
int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&ans[i].h,&ans[i].w);
            ans[i].m=1;
        }
        for(i=n;i<2*n;i++)
        {
            scanf("%d%d",&ans[i].h,&ans[i].w);
            ans[i].m=0;
        }
        sort(ans,ans+2*n,cmp);
        q.clear();
        int sum=0;
        for(i=0;i<2*n;i++)
        {
            if(ans[i].m==0)
            {
                q.insert(ans[i].w);
            }
            else
            {
                if(!q.empty())
                {
                    it = q.begin();
                    if(*it<=ans[i].w)
                    {
                        it = q.upper_bound(ans[i].w);
                        it--;
                        q.erase(it);
                        sum++;
                    }
                }
            }
        }
        printf("%d\n",sum);
    }
}
