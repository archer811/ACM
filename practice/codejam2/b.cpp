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
//     freopen("B-small-attempt0.in","r",stdin);
//    freopen("out.out","w",stdout);
    int a,b,k;
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&k);
        int ans=0;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                if((i&j)<k)cout<<i<<" "<<j<<" "<<(i&j)<<endl;

            }
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;

    return 0;
}
