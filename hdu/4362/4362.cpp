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
ll d[55][1005];
inline int readint()
{
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    int x=0;
    while(isdigit(c))
    {
        x = x*10+c-'0';
        c = getchar();
    }
    return x;
}
struct array
{
    int g,v;
}o[55][1005];
int cmp(array a,array b)
{
    return a.g<b.g;
}
const ll inf = ((ll)1)<<40;
int main()
{
    int i,j,t,n,m,x;
    scanf("%d",&t);
    while(t--)
    {
        //scanf("%d%d%d",&n,&m,&x);
        n = readint();
        m = readint();
        x = readint();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&o[i][j].g);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                scanf("%d",&o[i][j].v);
        }
        for(i=1;i<=n;i++)
            sort(o[i]+1,o[i]+m+1,cmp);
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=m;j++)
//                cout<<o[i][j].g<<" ";
//            cout<<endl;
//        }
        memset(d,0x3f,sizeof(d));
        for(i=1;i<=m;i++)
        {
            ll tmp = x-o[1][i].g;
            if(tmp<0)tmp=-tmp;
            d[1][i] = o[1][i].v+tmp;
            //cout<<d[1][i]<<"*";
        }
        //cout<<endl;
        for(i=2;i<=n;i++)
        {
            ll now=inf;
            int k=1;
            for(j=1;j<=m;j++)
            {
                while(k<=m&&o[i-1][k].g<=o[i][j].g)
                {
                    now = min(now,d[i-1][k]-o[i-1][k].g);
                    k++;
                }
                d[i][j]=min(d[i][j],now+o[i][j].v+o[i][j].g);
            }
            k = m;
            now = inf;
            for(j=m;j>=1;j--)
            {
                while(k>=1&&o[i-1][k].g>o[i][j].g)
                {
                    now = min(now,d[i-1][k]+o[i-1][k].g);
                    k--;
                }
                d[i][j]=min(d[i][j],now+o[i][j].v-o[i][j].g);
            }
//            for(j=1;j<=m;j++)
//                cout<<d[i][j]<<" ";
//            cout<<endl;
        }
        ll M=-1;
        for(i=1;i<=m;i++)
        {
            if(d[n][i]!=-1)
            {
                if(M==-1||d[n][i]<M)
                    M=d[n][i];
            }
        }
        printf("%I64d\n",M);
    }
    return 0;
}
