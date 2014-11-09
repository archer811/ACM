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
char s[22][22];
char t[22][22];
int len[1048578];
int flag=0;
int a[22];
int R,C,r,c;
void fun(int x)
{
    int k=0;
    //cout<<x<<endl;
    for(int i=0;i<R;i++)
    {
        if((1<<i)&x)a[k++]=i;
    }
//    for(int i=0;i<k;i++)
//        cout<<a[i]<<" ";
//    cout<<endl;
    int tmp=0;
    for(int i=0;i<C;i++)
    {
        int sum=0,sum2=0;
        for(int j=0;j<r;j++)
        {
            if(s[j][tmp]=='1')
                sum2=sum2|(1<<j);
        }
        for(int j=0;j<k;j++)
        {
            if(t[a[j]][i]=='1')
            sum = sum|(1<<j);
        }
        //cout<<sum2<<"*"<<sum<<endl;
        if(sum2==sum)tmp++;
    }
    if(tmp>=c)flag=1;
    return ;
}
int main()
{
    int i,j;
    int x= (1<<20)+1;
    for(i=0;i<x;i++)
    {
        if(i&1)len[i]=len[i/2]+1;
        else len[i]=len[i/2];
    }
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(scanf("%d%d",&r,&c)!=EOF)
    {
        for(i=0;i<r;i++)
            scanf("%s",s[i]);
        scanf("%d%d",&R,&C);
        for(i=0;i<R;i++)
            scanf("%s",t[i]);
        int M= (1<<R);
        flag=0;
        for(i=0;i<M;i++)
        {
            //cout<<i<<" "<<len[i]<<endl;
            if(len[i]==r)
            {
                fun(i);
            }
        }
        if(flag)puts("Yes");
        else puts("No");
    }
    return 0;
}
