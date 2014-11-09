#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int s[1005];
int main()
{
    int m,i,j,a,b,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,sizeof(s));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            s[a]++;s[b]++;
        }
        cout<<n-1<<endl;
        for(i=1;i<=n;i++)
            if(s[i]==0)break;
        for(j=1;j<=n;j++)
        {
            if(i==j)continue;
            printf("%d %d\n",i,j);
        }

    }
}
