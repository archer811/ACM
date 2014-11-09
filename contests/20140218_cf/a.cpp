#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[101];
int a[30];
string b = "nineteen";
int main()
{
    int i,j;
    while(cin>>s)
    {
        memset(a,0,sizeof(a));
        int len = strlen(s);
        for(i=0;i<len;i++)
        {
            a[s[i]-'a']++;
        }
        int sum=0;
        int f=0;
        while(1)
        {
            if(f==0)i=0;
            else i=1;
            int ff=0;
            f=1;
            for(;i<8;i++)
            {
                if(a[b[i]-'a']>0)
                {
                    //cout<<i<<" "<<b[i]<<" *"<<a[b[i]-'a']<<endl;
                    a[b[i]-'a']--;
                }
                else
                {
                    //cout<<i<<" "<<b[i]<<" *"<<a[b[i]-'a']<<endl;
                    ff=1;break;
                }
            }
           // cout<<i<<" "<<ff<<endl;
            if(ff)break;
            sum++;
        }
        cout<<sum<<endl;
    }
}
