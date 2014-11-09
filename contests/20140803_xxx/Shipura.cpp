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
char s[2000005];
#define ll long long
const ll mod = 1e9+7;
int f(int tmp)
{
    int s=0;
    while(tmp)
    {
        tmp/=2;
        s++;
    }
    return s;
}
ll num;
string badluck,o;
ll solve()
{
    int x = badluck.length();
    int y = o.length();
}
int main()
{
    int i,j;
    while(gets(s))
    {
        if(s[0]=='#')break;
        j=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]==' ')continue;
            s[j++]=s[i];
        }
        s[j++]='\0';
        int sum=0;
        num=0;
        budluck="";
        for(i=0;i<j;i++)
        {
            if(s[i]=='S')
            {
                sum++;
                i++;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                if(i-1>=0&&(!(s[i]>='0'&&s[i]<='9')))
                {
                    badluck="";
                    badluck+=s[i];
                }
                else badluck+=s[i];
            }
            else if(s[i]=='>')
            {
                if(i+2<j&&s[i+1]=='>'&&s[i+2]>='0'&&s[i+2]<='9')
                {
                    o="";
                    int k=i+2;
                    for(k=i+2;k<j;k++)
                    {
                        if(!(s[k]>='0'&&s[k]<='9'))break;
                        o+=s[k];
                    }
                    num = solve();
                    //cout<<num<<"*"<<o<<endl;
                    //int x2=num;
                    //x2 = (x2>>35);
                    //cout<<x2<<" "<<o<<endl;
                    //int tmp=f(num);
                    //cout<<tmp<<endl;
                    //if(o>=tmp)o=tmp+1;
                    //num = (num>>(ll)o);
                    i=k-1;
                }
                else
                {
                    sum--;
                    num = num*num%mod;
                    //if(sum==0)num=0;
                }
            }
        }
        printf("%lld\n",num);
    }
    return 0;
}
