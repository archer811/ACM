#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int judge(int x)
{
    int g[20];
    int i,j=0;
    while(x)
    {
        g[j++]=x%10;x/=10;
    }
    int k=0;
    for(i=j-1;i>=0;i--)
    {
        if(g[i]!=g[k++])return 0;
    }
    return 1;
}
int main()
{
    int i,j;
    freopen("out.txt","w",stdout);
    j=0;
    for(i=0;i<=485700;i++)
    {
        if(judge(i))
        {
            cout<<j<<" "<<i<<endl;j++;
        }
    }
}
