#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
char s[1000];
struct array
{
    int l;
}g[1000];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%s",s);
        int len = strlen(s);
        int k=0;
        int sum1=0,sum2=0;
        for(i=0;i<len-1;i++)
        {
            if(s[i]=='S'&&s[i+1]=='S')sum1++;
            if(s[i]=='S'&&s[i+1]!='S')sum2++;
        }
        printf("Case %d: ",++cas);
        printf("%d / %d\n",sum1,sum2);
    }
    return 0;
}
