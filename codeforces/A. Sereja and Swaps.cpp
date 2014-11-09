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
struct array
{
    int a,index;
}s[202];
const int inf = 0x3fffffff;
int cmp(array x,array y)
{
    return x.a>y.a;
}
int vis[202];
int b[202];
int main()
{
    int i,j,n,k;
    while(cin>>n>>k)
    {
        int gg=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i].a);
            s[i].index=i;
            gg+=s[i].a;
            b[i]=s[i].a;
        }
        sort(s+1,s+1+n,cmp);
        int ans =-inf;
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                int gg=0,Max=inf;
                for(int g=i;g<=j;g++)
                {
                    vis[g]=0;
                    gg+=b[g];
                    if(b[g]<Max)Max=b[g];
                }

                int sum=0,f=0,f2=0;
                for(int g=1;g<=n;g++)
                {
                    if(f>=j-i+1)break;
                    if(s[g].index>=i&&s[g].index<=j)
                    {
                        if(vis[s[g].index])continue;
                        vis[s[g].index]=1;
                        f++;
                        sum+=s[g].a;
                        continue;
                    }
                    else
                    {
                        if(f2<k)
                        {
                            f++;f2++;
                            sum+=s[g].a;
                        }
                    }
                }
                if(ans==-inf||ans<sum)ans=sum;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
