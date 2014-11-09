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
#define ll __int64
map<int,ll>M;
const int maxn = 100005;
int a[maxn];
struct O
{
    int v,id;
};
O v[maxn][33];
int num[maxn];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        M.clear();
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        num[n+1]=0;
        for(i=n;i>=1;i--)
        {
            num[i]=0;
            v[i][num[i]].v=a[i];
            v[i][num[i]++].id=i;
            int w = a[i];
            for(j=0;j<num[i+1];j++)
            {
                int tp = v[i+1][j].v;
                int tmp = gcd(tp,w);
                if(tmp==w)
                {
                    v[i][num[i]-1].id=v[i+1][j].id;
                }
                else
                {
                    v[i][num[i]].v=tmp;
                    v[i][num[i]++].id=v[i+1][j].id;
                }
                w=tmp;
            }
            int pre=i-1;
//            cout<<i<<":"<<endl;
//            for(j=0;j<num[i];j++)
//                cout<<v[i][j].v<<" () "<<v[i][j].id<<endl;
            for(j=0;j<num[i];j++)
            {
                M[v[i][j].v]+=v[i][j].id-pre;
                //cout<<v[i][j].v<<"*"<<v[i][j].id-pre+1<<endl;
                pre=v[i][j].id;
            }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int x;
            scanf("%d",&x);
            printf("%I64d\n",M[x]);
        }
    }
    return 0;
}

