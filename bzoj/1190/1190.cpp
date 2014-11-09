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
#define ll long long
int d[33][11];
int x,y;
void func(int a,int b,ll o2)
{
    ll o = ((ll)1)<<a;
    o *= (ll)b;
    o += o2;
    int s=0;
    while((o&(ll)1)==0)
    {
        o/=2;
        s++;
    }
    x=s;
    y=o;
}
int main()
{
    int i,j,k;
    int n,w;
    while(scanf("%d%d",&n,&w)!=EOF)
    {
        memset(d,-1,sizeof(d));
        d[0][0]=0;
        for(i=0; i<n; i++)
        {
            int w2,v;
            scanf("%d%d",&w2,&v);
            int s=0;
            ll tp = w2;
            while(w2%2==0)
            {
                w2/=2;
                s++;
            }
            //cout<<s<<"))))"<<w2<<endl;
            for(j=30; j>=0; j--)
            {
                for(k=10; k>=0; k--)
                {
                    if(d[j][k]==-1)continue;
                    func(j,k,tp);
                    if(x<=30&&y<=10)
                        d[x][y]=max(d[x][y],d[j][k]+v);
                }
            }
        }
        int ans=0;
        for(i=30; i>=0; i--)
        {
            for(j=10; j>=0; j--)
            {
                ll o = ((ll)1)<<i;
                o *= (ll)j;
                if(o>w)continue;
                ans=max(ans,d[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

