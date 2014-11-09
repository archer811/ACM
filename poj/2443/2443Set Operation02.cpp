#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
vector<int>g[10005];
int n;
short v[1001][10005];
int main()
{
    int i,j,k,m,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=10000;i++)
            g[i].clear();
        for(i=1;i<=n;i++)
            for(j=1;j<=10000;j++)
                v[i][j]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&k);
                g[k].push_back(i);
                v[i][k]=1;
            }
        }int q;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d",&a,&b);
            int len = g[a].size();
            bool flag = false;
            for(i=0;i<len;i++)
            {
                j = g[a][i];
//                cout<<endl;
//                cout<<a<<" "<<j<<" "<<b<<" "<<v[j][b]<<endl;
                if(v[j][b])
                {
                    flag=true;
                    printf("Yes\n");break;
                }
            }
            if(flag==false)
                puts("No");
        }
    }
}
