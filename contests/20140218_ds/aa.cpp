#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[10];
char s[600][600];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    a[1]=8;
    for(i=2;i<=7;i++)
    {
        a[i]=a[i-1]*2;
        //cout<<i<<" "<<a[i]<<endl;
    }
    while(t--)
    {
        int k;
        scanf("%d",&k);
        for(i=0;i<a[k];i++)
        {
            for(j=0;j<a[k];j++)
                s[i][j]=' ';
        }

    }
}
