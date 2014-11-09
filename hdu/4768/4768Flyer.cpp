#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct array
{
    int a,b,c;
} ans[20005];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        int g=0;
        for(i=1; i<=n; i++)
            scanf("%d%d%d",&ans[i].a,&ans[i].b,&ans[i].c);
        for(i=1; i<=n; i++)
        {
            for(j=ans[i].a; j<=ans[i].b; j+=ans[i].c)
            {
                g = g^j;
                //cout<<j<<endl;
            }

        }
        if(g==0)
            puts("DC Qiang is unhappy.");
        else
        {
            int num =0;
            for(i=1; i<=n; i++)
            {
                for(j=ans[i].a; j<=ans[i].b; j+=ans[i].c)
                {
                    if(g==j)num++;
                    else if(j>g)break;
                }
            }
            printf("%d %d\n",g,num);
        }
    }
}
