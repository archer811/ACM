#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int w,b;
double sum;
double dp[1005][1005];
void dfs(int a,int b,double f)
{

    if(a>=1&&b>=3)
    {
        //if(dp[a][b-3]!=-1)return;
        double tmp = f*(b*1.0/(a+b))*((b-1)*1.0/(a+b-1))*(b-2)/(a+b-2)*a/(a+b-3);
        sum += tmp;
        cout<<a<<" "<<b<< " "<<f<<" "<<tmp<<endl;
        //cout<<f*b*1.0/(a+b)*(b-1)/(a+b-1)*(b-2)/(a+b-2)<<"++++"<<endl;
        dp[a][b-3]=f*b*1.0/(a+b)*(b-1)/(a+b-1)*(b-2)/(a+b-2);
        dfs(a,b-3,f*b*1.0/(a+b)*(b-1)/(a+b-1)*(b-2)/(a+b-2));
    }
    if(a>=2&&b>=2)
    {
        //if(dp[a-1][b-2]!=-1)return;
        double tmp = f*b*1.0/(a+b)*(b-1)/(a+b-1)*(a-1)/(a+b-2)*a/(a+b-3);
        sum += tmp;
        cout<<a<< " "<<b<< " "<<f<<" "<<tmp<<"*"<<endl;
        dp[a-1][b-2]=f*b*1.0/(a+b)*(b-1)/(a+b-1)*a/(a+b-2);
        dfs(a-1,b-2,f*b*1.0/(a+b)*(b-1)/(a+b-1)*a/(a+b-2));
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&w,&b)!=EOF)
    {
        sum =0;
        memset(dp,-1,sizeof(dp));
        dp[w][b]=1;
        dfs(w,b,1);
        printf("%.9f\n",sum+w*1.0/(w+b));
        //cout<<sum<<endl;
    }
}
