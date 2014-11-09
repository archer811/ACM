#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[11],t[11];
#define ll __int64
ll d[11];
int main()
{
    int i,j,k,len;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='#')break;
        scanf("%s",t);
        len = strlen(s);
        ll tmp=(ll)1;
        d[len]=1;
        for(i=len-1;i>=0;i--)
        {
            if(s[i]!='?')
                d[i]=tmp;
            else d[i]=tmp*10,tmp*=10;
           // cout<<i<<" "<<d[i]<<endl;
        }
        int g=0;
        for(i=0;i<len;i++)
            if(s[i]!='?'){g=i;break;}
        ll ans=0;
        {
            for(i=0;i<len;i++)
            {
                if(s[i]!='?'&&s[i]<t[i])break;
                if(s[i]!='?'&&s[i]>t[i])
                {
                    ans += d[i+1];break;
                }
                //cout<<ans<<"*"<<d[i+1]<<endl;
                if(s[i]=='?')ans += (ll)(9-t[i]+'0')*d[i+1];

            }
        }
        cout<<ans<<endl;
    }
}
