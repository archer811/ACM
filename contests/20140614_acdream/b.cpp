#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[5000006];
int readint()
{
    char c=getchar();
    while(!(c>='0'&&c<='9'))c=getchar();
    int x=0;
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
int n,k;
int f(int mid)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=mid)sum++;
    }
    return sum>=k;
}
int main()
{
    int i;
    n=readint();
    {
        k=readint();
        int l=100000100,r=-1;
        for(i=0; i<n; i++)
        {
            a[i]=readint();
            if(a[i]>r)r=a[i];
            if(a[i]<l)l=a[i];
        }
        while(l<r)
        {
            int mid=l+(r-l+1)/2;
            //cout<<mid<<" "<<f(mid)<<endl;
            if(f(mid)==0)r=mid-1;
            else l=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
