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
int lowbit(int x)//����lowbit
{
    return x&(-x);
}
void add(int i,int val)//����i��Ԫ�ظ���Ϊvalע��i����Ϊ��
{
    while(i<N)//nΪ�����Ͻ�
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
