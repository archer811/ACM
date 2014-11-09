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
int a[66];
struct array
{
    int x,y,z;
} g[66*66];
int cmp(array a,array b)
{
    if(a.x==b.x&&a.y==b.y)return a.z<b.z;
    else if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int i,j,t,k,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        scanf("%d",&n);
        int sum=0;
        int ans =0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i]-1;
        }
        //cout<<sum<<" "<<(n-3)*2<<endl;
        if(sum!=(n-3)*2)
        {
            printf("%d N\n",k);
            continue;
        }
//        for(i=0;i<n;i++)
//        {
//            cout<<i<<" "<<a[i]<<endl;
//        }
        for(i=0; i<n-2; i++)
        {
            int flag=0;
            for(j=0; j<n&&flag==0; j++)
            {
                if(a[j]==1)
                {
                    int l=j,r=j;
                    l = ((l-1)%n+n)%n;
                    r = (r+1)%n;
                    while(a[l]==0)
                    {
                        l = ((l-1)%n+n)%n;
                    }
                    while(a[r]==0)
                    {
                        r = (r+1)%n;
                    }
                    //cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
                    if(l!=r)
                    {
                        a[l]--;
                        a[r]--;
                        a[j]--;
                        g[ans].x=l;
                        g[ans].y=r;
                        g[ans].z=j;
                        if(g[ans].x>g[ans].y)swap(g[ans].x,g[ans].y);
                        if(g[ans].x>g[ans].z)swap(g[ans].x,g[ans].z);
                        if(g[ans].y>g[ans].z)swap(g[ans].y,g[ans].z);
                        ans++;
                        break;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        int flag=0;
        for(i=0; i<n; i++)
            if(a[i])
            {
                flag=1;
            }
        if(flag==0)
        {
            printf("%d Y\n",k);
            sort(g,g+ans,cmp);
            for(i=0;i<ans;i++)
            {
                printf("%d %d %d\n",g[i].x+1,g[i].y+1,g[i].z+1);
            }
        }
        else
            printf("%d N\n",k);
    }
    return 0;
}
