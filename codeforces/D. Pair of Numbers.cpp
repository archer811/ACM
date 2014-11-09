#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 300005;
int a[maxn],n;
vector<int>ans;
int judge(int d)
{
    int i,j;
    for(i=1;i+d<=n;i++)
    {
        //if(d==3)cout<<i<<endl;
        if(a[i]%a[i+d])continue;
        for(j=i+1;j<i+d;j++)
            if(a[j]%a[i+d])break;
        if(j==i+d)
           ans.push_back(i);
    }
    return 1;
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int l=0,r=n;
        for(i=n-1;i>=0;i--)
        {
            ans.clear();judge(i);
            if(ans.size())
            {
                printf("%d %d\n",ans.size(),i+1);
                for(j=0;j<ans.size();j++)
                    printf("%d ",ans[j]);
                puts("");
                break;
            }
        }
    }
}
