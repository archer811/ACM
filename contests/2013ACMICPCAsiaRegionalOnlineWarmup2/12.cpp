#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,a[100005];
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        //sort(a,a+n);
        int f =0;
        if(a[n-1]-a[2]+1!=(n-1-2+1))f=1;
        for(i=2;i<n;i++)
            if(a[i]!=a[i-1]+1)
            {
                f=1;break;
            }
        printf("Case #%d: ",++cas);
        if(f==0)
        {
            printf("%d\n",1);
            continue;
        }

        f = 0;
        if(a[n-2]-a[0]+1!=(n-2-0+1))f=1;
        //cout<<a[n-2]-a[0]<<" "<<(n-2+1)<<endl;
        for(i=1;i<n-1;i++)
        {
            if(a[i]!=a[i-1]+1)
            {
                f=1;break;
            }
        }
        if(f==0)
        {
            printf("%d\n",n);
            continue;
        } //cout<<"U"<<endl;
        for(i=1;i<=n-2;i++)
        {
            if(a[i]!=a[i-1]+1)
            {
                printf("%d\n",i+1);
                f=1;
                break;
            }
        }
    }
}
