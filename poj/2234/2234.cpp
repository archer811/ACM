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
#define ll long long
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int s=0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&j);
            s^=j;
        }
        if(s)puts("Yes");
        else puts("No");
    }
    return 0;
}
