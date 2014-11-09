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
    int n;
    int x,y;
    int an[111];
    int t;
    cin>>t;
    while (t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        int vis[111];
        for (int i=1 ;i<=n ;i++) scanf("%d",&an[i]);
        if (an[1]==x && an[n]==y)
        {
            cout<<"BOTH"<<endl;
            continue;
        }
        if (an[1]==x && an[n]!=y) {puts("EASY");continue; }
        if (an[n]==y && an[1]!=x) {puts("HARD");continue; }
        puts("OKAY");
    }
    return 0;
}
