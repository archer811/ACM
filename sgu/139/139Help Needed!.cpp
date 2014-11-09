#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[100],b[100];
int num,gg=0;
void msort(int s,int t)
{
    int i,j,k;
    int mid = (s+t)/2;
    if(s>=t)return;
    msort(s,mid);
    msort(mid+1,t);
    int q = s;
    for(i=s,j=mid+1;i<=mid&&j<=t;)
    {
        if(a[i]<=a[j])
        {
            b[q]=a[i];
            i++;
        }
        else
        {
            b[q]=a[j];
            j++;
           // num += mid-i+1;
            gg += mid-i+1;
        }
        q++;
    }
    while(i<=mid)
    {
        b[q++]=a[i];i++;
    }
    while(j<=t)
    {
        b[q++]=a[j];j++;
    }
    for (i=s;i<=t;i++)
    {
        a[i] = b[i];
    }
}
int main()
{
    int i,j,k;
    num = 0;
    for(i=1; i<=16; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)num+=3-(i-1)/4,gg=num;
    }
    for(i=1;i<=16;i++)
    {
        for(j=1;j<i;j++)
        {
            if(a[j]>a[i]&&a[i])num++;
        }
    }
    //cout<<num<<" "<<gg<<endl;
    if (num&1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
