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
int a[200005];
int main()
{
    int i,j,n,m,l,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&l);
        int now=0;
        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int sum=0;
        a[n+1]=m;
        int pre=0;
        i = 1;
        while(now<m)
        {
            if(a[i]-now<=l)
            {
                while(i<=n+1&&a[i]-now<=l)
                    i++;
                i--;
                pre=now;
                now=a[i];
                i++;
                sum++;
                continue;
            }
            else
            {
                int w = (a[i]-now)/(l+1)-1;
               // cout<<w<<endl;
                if(w>0)
                {
                    pre = max(pre+l+1,now+1)+(w-1)*(l+1);
                    now = now+w*(l+1);
                    sum+=w*2;
                }
                else
                {
                    int tt=pre;
                    pre = now;
                    now = max(tt+l+1,now+1);
                    sum++;
                }
//                if(now>=a[i])
//                i++;
            }
        }
        printf("Case #%d: %d\n",++cas,sum);
    }
    return 0;
}
