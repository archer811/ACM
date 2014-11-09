#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[105],b[105];
int main()
{
    int i,j,k;
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int flag=0,sum=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&j);
            if(i==1)a[i]=j;
            else a[i]=a[i-1]+j*i;
            b[i]=j;
            sum += j;
        }
        int g =0;
        int x,y;
        scanf("%d%d",&x,&y);
        for(i=1;i<m;i++)
        {
            g += b[i];
            if(g>=x&&g<=y&&(sum-g>=x&&sum-g<=y))
            {
                flag=i+1;break;
            }
        }
        cout<<flag<<endl;
    }
}
