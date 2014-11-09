#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 500005;
int s[maxn];
const int N = 100006;
int c[N];
int lowbit(int x)//计算lowbit
{
    return x&(-x);
}
void add(int i,int val)//将第i个元素更改为val注意i不可为零
{
    while(i<N)//n为数组上界
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        sort(s,s+n);
        memset(c,0,sizeof(c));
        j=n-1;
        int sum=n;
        for(i=0;i<50;i++)
            cout<<"*"<<s[i]<<" "<<s[i+50]<<endl;
        j=0;
        for(i=0;i<n&&j<n;i++)
        {
            if(c[i])continue;
            while(s[j]<s[i]*2&&j<n){j++;continue;}
            if(j>=n)break;
            cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<endl;
            c[j]=1;sum--;j++;
        }
        cout<<sum<<endl;
    }
}
