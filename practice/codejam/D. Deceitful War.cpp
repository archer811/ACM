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
double a[1005],b[1005];
int vis[1005];
int cmp(double a,double b)
{
    if(a>b)return 1;
    return 0;
}
int main()
{
    int i,j,t;
//    freopen("D-large.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int n;
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
        }
        for(i=0;i<n;i++)
            scanf("%lf",&b[i]);
        int s=0;

        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
//        for(i=0;i<n;i++)
//            cout<<a[i]<<" "<<b[i]<<endl;
        j=n-1;
        int k=0;
        int s2=0;
        memset(vis,0,sizeof(vis));

        for(i=0;i<n;i++)
        {
            k = 0;
            for(j=i;j<n;j++)
            {
                if(a[k]>b[j]);
                else break;
                k++;
            }
            //cout<<i<<" "<<j<<endl;
            if(j==n)
            {
                s2=n-i;break;
            }
        }
        j=n-1;k=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>=b[k])
            {

                if(a[i]>b[j])
                s++;
                j--;
            }
            else
            {
                k++;
            }
        }
        printf("Case #%d: %d %d\n",++cas,s2,s);
        //cout<<s2<<" "<<s<<endl;
    }
}
