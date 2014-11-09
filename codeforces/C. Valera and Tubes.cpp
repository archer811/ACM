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
int x[90001],y[90001];
int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int num=0;
        for(i=1;i<=n;i++)
        {
            if(i&1)
            {
                for(j=1;j<=m;j++)
                {
                    x[num]=i;y[num++]=j;
                }
            }
            else
            {
                for(j=m;j>=1;j--)
                {
                    x[num]=i;y[num++]=j;
                }
            }
        }
//        for(i=0;i<num;i++)
//            cout<<x[i]<<" "<<y[i]<<endl;
        int g=num;
        num=0;
        for(i=0;i<k-1;i++)
        {
            cout<<2;
            cout<<" "<<x[num]<<" "<<y[num];num++;
            cout<<" "<<x[num]<<" "<<y[num]<<endl;num++;
        }
        if(g-num>0)
        {
            printf("%d",g-num);
            for(i=num;i<g;i++)
            {
                cout<<" "<<x[num]<<" "<<y[num];num++;
            }
            cout<<endl;
        }

    }
    return 0;
}
