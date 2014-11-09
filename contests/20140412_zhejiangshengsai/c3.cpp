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
int s[40005];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int n,m,a;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(s,0,sizeof(s));
        int M=-1;
        int allsu=0,sum=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&s[i]);
            allsu+=s[i];
            if(s[i]>M)M=s[i];
        }
        sum=allsu/m;
        if(allsu%m)sum++;
        sum=max(sum,M);
        printf("%d\n",sum);
    }
}
