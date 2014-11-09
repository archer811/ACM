#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[55][55];
int n,m;
int main()
{
    int i,j,k;
    while(cin>>n>>m)
    {
        int f=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]&&(i==1||i==n||j==1||j==m))f=1;
            }

        }
        if(f)puts("2");
        else puts("4");
    }
}
