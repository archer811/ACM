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
int n,t,c;
int a[200005];
#define ll __int64
int main()
{
    int i,j;
    while(cin>>n>>t>>c)
    {
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int ans=0,now=0,pre=-1,f=-1;
        for(i=0; i<n; i++)
        {
            if(a[i]<=t)
            {
                if(f==-1)
                {
                    f=0;
                    pre=i;
                    now=1;
                }
                else now++;
            }
            else
            {
                if(f!=-1)
                {
                    if(i-1-pre+1-c+1>=0)
                    ans += (i-1-pre+1)-c+1;
                    //cout<<i-1<<" "<<pre<<endl;
                    f=-1;
                    pre=-1;
                }

            }
        }
        {
            if(f!=-1)
            {
                if(n-1-pre+1-c+1>=0)
                ans += (n-1-pre+1)-c+1;
                //cout<<n<<" "<<pre<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
