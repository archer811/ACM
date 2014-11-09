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
int a[20],num,b[1000],flag;
void dfs(int pos,int sum,int jinwei)
{
    int i,j;
    if(flag)return;
    //cout<<pos<<"()"<<num<<endl;
    if(pos==num)
    {
        flag=1;
        i=pos-1;
        while(i>0&&b[i]==0)
        {
            i--;
        }
        i = max(i,0);
        for(;i>=0;i--)
        {
            printf("%d",b[i]);
        }
        puts("");
        return;
    }
    for(i=0;i<=9;i++)
    {
        int tmp = jinwei;
        int k=0;
        b[pos]=i;
        for(j=pos;j>=0;j--)
        {
            tmp += b[j]*b[k];
            k++;
        }
        if(tmp%10==a[pos])
        {
            //cout<<pos<<"**"<<i<< " "<<sum+i<<" "<<tmp/10<<endl;
            b[pos]=i;
            dfs(pos+1,sum+i,tmp/10);
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        num=0;
        if(n==0)
        {
            puts("0");continue;
        }
        while(n)
        {
            a[num++]=n%10;n/=10;
        }
        flag=0;
        dfs(0,0,0);
        if(flag==0)
        {
            puts("None");continue;
        }
    }
    return 0;
}
