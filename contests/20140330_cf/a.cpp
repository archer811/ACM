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
int k[1000];
int main()
{
    int i,j;
    int n;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            cin>>k[i];
        int ans;
        for(i=1;i<=n;i++)
        {
            int tmp=0;
            int g=0,b;
            for(j=1;j<=k[i];j++)
            {
                cin>>b;
                g+=b;
            }
            tmp = g*5+15*k[i];
            if(i==1)ans=tmp;
            else
            {
                if(tmp<ans)ans=tmp;
            }
        }
        cout<<ans<<endl;
    }
}
