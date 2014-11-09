#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int inf = 0x3fffffff;
struct array
{
    char s[20];
}a[105];
int cmp(array x,array y)
{
    return strcmp(x.s,y.s)<0;
}
int v[5];
int b[5],n;
int M;
int ans[5];
int f(int x)
{
    int t1[5],t2[5];
    int i,j;
    for(i=0;i<5;i++)
    {
        int tmp = a[x].s[i]-'A';
        t1[tmp]=i;
    }
    for(i=0;i<5;i++)
    {
        int tmp = b[i];
        t2[tmp]=i;
    }
//    for(i=0;i<5;i++)
//        cout<<i<<"   "<<t1[i]<<endl;
//    for(i=0;i<5;i++)
//        cout<<i<<"   "<<t2[i]<<endl;
    int sum=0;
    for(i=0;i<5;i++)
    {
       for(j=i+1;j<5;j++)
       {
           if(i!=j&&(t1[i]-t1[j])*(t2[i]-t2[j])<0)
            sum++;
       }
    }
    return sum;
}

void dfs(int num)
{
    if(num==5)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
             //if(b[0]==0&&b[1]==1&&b[2]==2&&b[3]==3&&b[4]==4)
            sum += f(i);
        }


        if(sum<M)
        {
            M=sum;
            for(int i=0;i<5;i++)
                ans[i]=b[i];
        }
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            b[num]=i;
            dfs(num+1);
            v[i]=0;
        }
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(i=0;i<n;i++)
            scanf("%s",a[i].s);
        M = inf;
        dfs(0);
        char c[6];
        for(i=0;i<5;i++)
            c[i]=ans[i]+'A';
        c[i]='\0';
        printf("%s is the median ranking with value %d.\n",c,M);
    }
}
