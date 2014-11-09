#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int a[10],b[10];
bool flag;
void dfs(int num,int mm)
{
    int i,j;
    if(num<0)return;
    if(flag)return;
    if(num==0)
    {
        if(mm==1)
          flag=true;
        return;
    }
    for(i=1;i<=9;i++)
    {
        if(b[i]>=3)
        {
            b[i]-=3;
            dfs(num-3,mm);
            b[i]+=3;
        }
        if(b[i]>=2)
        {
            b[i]-=2;
            dfs(num-2,mm+1);
            b[i]+=2;
        }
        if(b[i]>=1&&(i+1)<=9&&(i+2)<=9&&b[i+1]>=1&&b[i+2]>=1)
        {
            //cout<<num<<endl;
            b[i]-=1;
            b[i+1]-=1;
            b[i+2]-=1;
            dfs(num-3,mm);
            b[i]+=1;
            b[i+1]+=1;
            b[i+2]+=1;
        }
    }
}
int main()
{
     int i,j,k;
     while(scanf("%d",&j)!=EOF)
     {
         memset(a,0,sizeof(a));
         a[j]++;
         for(i=2;i<=13;i++)
            scanf("%d",&j),a[j]++;
         int g=0;
         for(i=1;i<=9;i++)
         {
             for(j=1;j<=9;j++)
                b[j]=a[j];
             b[i]++;
             flag = false;
             dfs(14,0);
             if(flag)
             {
                 if(g==0)printf("%d",i);
                 else printf(" %d",i);
                 g=1;
             }

         }
         puts("");
     }
}
