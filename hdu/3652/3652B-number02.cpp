/**************************************************************
* ���⣺��[1,n]���ж��ٸ����֣���������13�����ܱ�13���� n<=10^9
��Ҫ����x % 13 = 0��x=pre*10^pos+next;
 (pos��������ǰ��λ����next�������ڴ����λ�����������)
 (pre*10^pos + next) % 13 = 0��pre��֮ǰȷ���Ĳ��֣�
 ��Ҫ�Ĳ���Ϊpre , pos ,״̬��status��ʾ
status==2��¼preӵ��"13"��status==1�Ǳ�ʾû�г���13��������λ��1��
status=0��ʾû��13��

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

        /*׼���������һ�׶����µ�״̬status*/
        if(status==0&&i==1)
             new_status=1;/*ԭ��û�г���13���ǵ�ǰλ��1����������״̬1��Ӧ��������ʸ�����״̬Ϊ1��*/
        if(status==1&&i==1)
             new_status=1;/*���ͷ���ͬ��*/
        else if(status==1&&i!=3)
             new_status=0;
        if(status==1&&i==3)
             new_status=2;

        res+=DFS(i,pos-1,new_status,new_pre,limit&&i==end);
        /*//limit==true��˵��������,�����п��ܲ�û�б�ȫ����¼,�ʴ�ʱ����dp���� */
        //limit==false��˵��֮��ķ�֧״̬�Ѿ�������ȫ
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
