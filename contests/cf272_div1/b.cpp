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
int a[10005][5],num[10005];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,k=1;
    int n;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        cout<<(6*(n-1)+5)*k<<endl;
        for(i=0;i<n;i++)
        {
            printf("%d %d %d %d\n",(6*i+1)*k,(6*i+2)*k,(6*i+3)*k,(6*i+5)*k);
        }
    }
    return 0;
}
