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
int a[1000056];
void init()
{
    int i,j;
    a[1]=a[0]=1;
    for(i=2;i<=1000006;i++)
    {
        if(a[i]==0)
            for(j=i+i;j<=1000006;j+=i)
                a[j]=1;
    }
}
vector<int>v;
int main()
{
    int i,j;
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        v.clear();
        for(i=2;i<n;i++)
        {
            if(2+i<=n && a[2+i]==0 && a[i]==0 )sum++,v.push_back(i);
        }
        printf("%d\n",sum);
        for(i=0;i<v.size();i++)
        {
            printf("2 %d\n",v[i]);
        }
    }
    return 0;
}
