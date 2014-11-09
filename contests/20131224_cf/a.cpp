#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1000006];
#define ll __int64
int main()
{
    int i,j;
    while(scanf("%s",s)!=EOF)
    {
        int len = strlen(s);
        int k=0;
        for(k=0;k<len;k++)
        {
            if(s[k]=='^')break;
        }
        ll sum1 =0,sum2 =0;
        ll l = 0,r = 0;
        for(i=k-1;i>=0;i--)
        {
            l++;
            if(s[i]=='=')continue;
            sum1 += l*(ll)(s[i]-'0');

        }
        for(i=k+1;i<len;i++)
        {
            r++;
            if(s[i]=='=')continue;
            sum2 += r*(ll)(s[i]-'0');
        }
        //cout<<sum1<<" "<<sum2<<endl;
        if(sum1==sum2)puts("balance");
        else if(sum1>sum2)puts("left");
        else puts("right");
    }
}
