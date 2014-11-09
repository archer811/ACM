#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char a[11][11];
int main()
{
    int i,j,k;
    int s =0;
    for(k=3;k<=10;k++)
    {
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
                a[i][j]=' ';
        }
        for(i=1;i<=k;i++)
            a[i][1]=(char)(s+'a'),s=(s+1)%26;
        for(i=2;i<=k;i++)
            a[k+1-i][i]=(char)(s+'a'),s=(s+1)%26;
        for(i=2;i<=k;i++)
            a[i][k]=(char)(s+'a'),s=(s+1)%26;
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
           cout<<a[i][j];
           cout<<endl;
        }


    }
}
