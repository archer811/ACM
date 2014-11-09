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

#define N 405

int W[N][N], n;
int Lx[N], Ly[N];
int Left[N];
bool S[N], T[N];
bool match(int i)
{
    S[i] = true;
    for(int j = 1; j <=n; j++)if(Lx[i] + Ly[j] == W[i][j] && !T[j])
        {
            T[j] = true;
            if(!Left[j] || match(Left[j]))
            {
                Left[j] = i;
                return true;
            }
        }
    return false;
}
void updata()
{
    int a = 1<<30;
    for(int i = 1; i <= n; i++)if(S[i])
            for(int j = 1; j <= n; j++)if(!T[j])
                    a = min(a, Lx[i] + Ly[j] - W[i][j]);
    if(a==1<<30)return;
    for(int i = 1; i <= n; i++)
    {
        if(S[i]) Lx[i] -= a;
        if(T[i]) Ly[i] += a;
    }
}
const int inf=1<<30;
void KM()
{
    memset(Left, 0, sizeof(Left));
    for(int i=1;i<=n;i++)
        Lx[i]=-inf;
//    memset(Lx, 0, sizeof(Lx));
    memset(Ly, 0, sizeof(Ly));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            Lx[i] = max(Lx[i], W[i][j]);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<Lx[i]<<endl;
//    }
    for(int i = 1; i <= n; i++)
        while(1)
        {
            memset(S, 0, sizeof(S));
            memset(T, 0, sizeof(T));
            if(match(i))break;
            updata();
        }
}
int val[N],ans[N];
int main()
{
    int i,j,t;
    while(scanf("%d",&t)!=EOF)
    {
        for(int g=0; g<t; g++)
        {
            scanf("%d",&n);
            for(i=1; i<=n; i++)
                scanf("%d",&val[i]);
            memset(W,0,sizeof(W));
            memset(ans,0,sizeof(ans));
            for(i=1; i<=n; i++)
            {
                int m;
                scanf("%d",&m);
                int num;
                for(j=1; j<=m; j++)
                {
                    scanf("%d",&num);
                    W[i][num]=val[i]*val[i];
                }
            }

            //cout<<"*"<<endl;
            KM();
            for(i=1;i<=n;i++)
            {
                if(W[Left[i]][i]>0)
                    ans[Left[i]]=i;
            }
            for(i=1; i<=n; i++)
            {
                if(i>1)printf(" ");
                printf("%d",ans[i]);
            }
            puts("");
            if(g<t-1)puts("");
        }
    }

}
