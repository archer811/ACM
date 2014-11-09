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
struct array
{
    int kind,a,b;
}s[100005];
#define ll __int64
ll x[100005];
int n;
int find(ll ask)
{
    int l=1,r=n;
    while(l<r)
    {
        int mid = (l+r)>>1;
        ll tmp = x[mid];
        if(tmp>=ask)r=mid;
        else l=mid+1;
    }
    return l;
}
int main()
{
    int i,j;
    int m;
    while(scanf("%d",&n)!=EOF)
    {
        x[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i].kind);
            if(s[i].kind==1)
            {
                scanf("%d",&s[i].a);
                x[i]=x[i-1]+(ll)1;
            }
            else
            {
                scanf("%d%d",&s[i].a,&s[i].b);
                x[i]=x[i-1]+(ll)s[i].a*(ll)s[i].b;
            }
        }
        scanf("%d",&m);
        ll ask;
        while(m--)
        {
            scanf("%I64d",&ask);
            while(1)
            {
                int tmp = find(ask);
                //cout<<tmp<<"()"<<endl;
                if(s[tmp].kind==1)
                {
                    printf("%d ",s[tmp].a);
                    break;
                }
                ask = (ask-x[tmp-1])%((ll)s[tmp].a);
                if(ask==0)
                    ask = (ll)s[tmp].a;
                //cout<<ask<<endl;
            }
        }
        puts("");
    }
}
