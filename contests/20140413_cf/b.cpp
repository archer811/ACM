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
int a[50005],t[50005][6];
int main()
{
    int i,j;
    int m,n;
    while(cin>>m>>n)
    {
        memset(a,0,sizeof(a));
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&t[i][j]);
        }
//        for(j=1;j<=m;j++)
//            a[j]=max(a[j],a[j-1]+t[j][1]);
        for(i=1;i<=n;i++)
        {
            //cout<<i<<endl;
            for(j=1;j<=m;j++)
            {
                if(j==1)
                    a[j]=a[j]+t[j][i];
                else
                    a[j]=max(a[j]+t[j][i],a[j-1]+t[j][i]);
               // cout<<a[j]<<" ";
            }
            //cout<<endl;
        }
        for(i=1;i<=m;i++)
            cout<<a[i]<<endl;
    }
}
