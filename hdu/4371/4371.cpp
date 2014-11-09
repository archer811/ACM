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
const int inf = 0x3fffffff;
int main()
{
    int i,j,t,n,m;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int ans=inf;
        for(i=0;i<m;i++)
        {
            scanf("%d",&j);
            ans=min(ans,j);
        }
        int k = n/ans;
        printf("Case #%d: ",++cas);
        //cout<<k<<"*)("<<n<<" "<<ans<<endl;
        if(k&1)puts("Bob");
        else puts("Alice");
    }
    return 0;
}

