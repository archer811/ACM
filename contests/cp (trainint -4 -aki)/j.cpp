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
int a[33000],b[33000],c[33];
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int t1=0,t2=0;
        int n1=n/2,n2=n-n1;
        for(i=0;i<n1;i++)
            scanf("%d",&c[i]);
        int M = 1<<n1;
        for(i=0;i<M;i++)
        {
            int sum=0;
            for(j=0;j<n1;j++)
            {
                if((1<<j)&i)sum += c[j];
            }
            a[t1++]=sum;
        }
        sort(a,a+t1);
//        for(i=0;i<t1;i++)
//            cout<<a[i]<<"*";
//        cout<<endl;

        for(i=0;i<n2;i++)
            scanf("%d",&c[i]);
        M = 1<<n2;
        for(i=0;i<M;i++)
        {
            int sum=0;
            for(j=0;j<n2;j++)
            {
                if((1<<j)&i)sum += c[j];
            }
            b[t2++]=sum;
        }
        sort(b,b+t2);
//        for(i=0;i<t2;i++)
//            cout<<b[i]<<"-";
//        cout<<endl;
        j=t2-1;
        int ans=0;
        for(i=0;i<t1;i++)
        {
            while(j>0)
            {
                //cout<<a[i]+b[j]<<"()"<<i<<" "<<j<<endl;
                if(a[i]+b[j]>m)j--;
                else break;
            }
            if(a[i]+b[j]<=m)
            {
                //cout<<a[i]+b[j]<<endl;
                ans=max(ans,a[i]+b[j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
