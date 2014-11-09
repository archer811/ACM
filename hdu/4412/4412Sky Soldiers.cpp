#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<int,double>M;
map<int,double>::iterator it;
struct array
{
    int x;
    double num;
}ans[1005];
double cost[1005][1005];
const double inf = 1.0*0x3fffffff;
int main()
{
    int k,m,i,j,n,s;
    double t;
    while(scanf("%d%d",&m,&k)!=EOF)
    {
        if(m==0&&k==0)break;
        M.clear();
        while(m--)
        {
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                scanf("%d%lf",&s,&t);
                M[s]+=t;
            }
        }
        int g=1;
        for(it = M.begin();it!=M.end();it++)
        {
            ans[g].x=it->first;
            ans[g++].num=it->second;
        }
        g--;
        for(i=1;i<=g;i++)
        {
            cost[i][i]=0;
            for(j=i+1;j<=g;j++)
            {
                cost[i][j]=cost[j][i]=inf;
            }
        }

    }
}


void init()
{
    int i,j,cur;
    double Lp,Rp,sumL,sumR,temp;
    for(i=n;i>=1;i--)
    {
        cur=i;
        cost[i][i]=0;
        sumL=sumR=0;
        Lp=0;
        Rp=a[cur].p;
        for(j=i-1;j>=1;j--)
        {
            Lp+=a[j].p;
            sumL+=(a[cur].pos-a[j].pos)*a[j].p;
            temp=sumL+sumR;
            while(cur>1&&temp>sumL+sumR+(Rp-Lp)*(a[cur].pos-a[cur-1].pos))
            {
                sumL-=Lp*(a[cur].pos-a[cur-1].pos);
                sumR+=Rp*(a[cur].pos-a[cur-1].pos);
                cur--;
                Lp-=a[cur].p;
                Rp+=a[cur].p;
                temp=sumL+sumR;
            }
            cost[j][i]=temp;
        }
    }
}
