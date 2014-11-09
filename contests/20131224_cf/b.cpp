#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int s[105];
#define inf 10000000
int main()
{
    int i,j;
    int a,b,c;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,sizeof(s));

        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            s[a]-=c;
            s[b]+=c;
           // cout<<a<<" "<<b<<" "<<s[a]<<" "<<s[b]<<endl;
        }

        int ans = 0;
        for(i=1;i<=n;i++)
        {
            //cout<<i<<" "<<s[i]<<endl;
            if(s[i]>0)ans += s[i];
        }
        cout<<ans<<endl;
    }
}
