#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[101];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++)
        {
            int b;
            scanf("%d",&b);
            a[b]++;
        }
        int s=0;
        for(i=1;i<=100;i++)
            if(a[i]>s)s=a[i];
        cout<<s<<endl;
    }
}
