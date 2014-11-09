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
int st(int l,int r,int num,int *a)
{
    if(l==r)return a[l];
    if (l< r)
    {
        int i = l, j = r, x = a[l];
        while (i < j)
        {
            while(i < j && a[j]>= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i]< x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        int tmp= i-1-l+1;
        if(num==tmp)return x;
        if(num<=i-1-l+1)
            return st(l,i-1,num,a);
        else
            return st(i+1,r,num-tmp-1,a);
    }
}
int a[5000001],b[5000001];
int main()
{
    int i,j,n,k;
    n=readint();k=readint();
    for(i=0;i<n;i++)
    {
        a[i]=readint();
    }
    printf("%d\n",st(0,n-1,n-k,a));
    return 0;
}
