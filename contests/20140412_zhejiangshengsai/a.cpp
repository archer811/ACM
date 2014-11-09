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
int main()
{
    int i,j,t;
    int n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int s1=0,s2=0;
        int d;
        while(n--)
        {
            scanf("%d",&d);
            s1+=d;
        }
        while(m--)
        {
            scanf("%d",&d);
            s2+=d;
        }
        if(s1>s2)puts("Calem");
        else if(s1<s2)puts("Serena");
        else puts("Draw");
    }
}
