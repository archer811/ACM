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

int n,v[5000];
char a[5000][5005];

void dfs(int x, int r)
{
    v[x]=1;
    for(int y=0; y<n; y++)
        if(a[x][y]=='1')
        {
            if(!v[y]) dfs(y,x);
            else if(a[y][r]=='1')
                exit(!printf("%d %d %d\n",y+1,r+1,x+1));
        }
}

int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        gets(*a);
        for(int i=0; i<n; i++) gets(a[i]);
        for(int i=0; i<n; i++) if(!v[i]) dfs(i,-1);
        puts("-1");
    }

}
