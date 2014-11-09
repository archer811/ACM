/**************************************************************
* 题意：求[1,n]内有多少个数字，该数字有13，且能被13整除 n<=10^9
即要满足x % 13 = 0；x=pre*10^pos+next;
 (pos代表处理到当前的位数，next代表正在处理的位置上面的数字)
 (pre*10^pos + next) % 13 = 0，pre是之前确定的部分；
 需要的参数为pre , pos ,状态用status表示
status==2记录pre拥有"13"，status==1是表示没有出现13，但是首位是1；
status=0表示没有13；

* Author:sgx
* Date:2013/09/15
*************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;
const int maxn=100+5;

int dp[10][13][3];
int digit[10];

int DFS(int l,int pos,int status,int pre,bool limit)
{
    if(pos==-1)
        return status==2&&pre==0;
    if(!limit&&dp[pos][pre][status]!=-1)
        return dp[pos][pre][status];

     LL res=0;
     int end=limit?digit[pos]:9;

     for(int i=0;i<=end;i++)
     {
        int new_pre=(pre*10+i)%13;
        int new_status=status;

        /*准备计算出下一阶段中新的状态status*/
        if(status==0&&i==1)
             new_status=1;/*原来没有出现13但是当前位是1，所以属于状态1对应的情况，故更新新状态为1；*/
        if(status==1&&i==1)
             new_status=1;/*解释方法同上*/
        else if(status==1&&i!=3)
             new_status=0;
        if(status==1&&i==3)
             new_status=2;

        res+=DFS(i,pos-1,new_status,new_pre,limit&&i==end);
        /*//limit==true则说明有限制,即所有可能并没有被全部记录,故此时记入dp数组 */
        //limit==false则说明之后的分支状态已经搜索完全
    }
    if(!limit)
         dp[pos][pre][status]=res;
    return res;
}

LL solve(int n)
{
     int len=0;
     while(n)
     {
         digit[len++]=n%10;
         n/=10;
     }
     return DFS(0,n-1,0,0,true);
}

int main()
{
     LL m,n;
     while(scanf("%lld",&n)!=EOF)
     {
         memset(dp,-1,sizeof(dp));
         printf("%lld\n",solve(n));
     }
     return 0;
}
