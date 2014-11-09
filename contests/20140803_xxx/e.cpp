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
const int maxn = 100005;
//char s[maxn],t[maxn];
string smallestRepresation(string s)
{
    int i,j,k,l;
    int N = s.length();
    s += s;
    for(i=0,j=1; j<N;)
    {
        for(k=0; k<N&&s[i+k]==s[j+k]; k++);
        if(k>=N)break;
        if(s[i+k]<s[j+k])
            j+=k+1;
        else
        {
            l=i+k;
            i=j;
            j=max(l,j)+1;
        }
    }
    return s.substr(i,N);
}
string s,t;
int main()
{
    int i,j;
    while(cin>>s>>t)
    {
        int flag=0;
        if(s.length()!=t.length())
        {

            {
                puts("no");
                continue;
            }
        }
        if(flag==0)
        {
            int len=s.length();
            for(i=0;i<len;i++)
            {
                if(s[i]!=t[i])flag=1;
            }
            if(flag==0)
            {
                puts("no");
                continue;
            }
            flag=0;
        }
        if(flag==0)
        {
            string s2=smallestRepresation(s);
            string t2=smallestRepresation(t);
            int len=s2.length();
            for(i=0;i<len;i++)
            {
                if(s2[i]!=t2[i])flag=1;
            }
        }
        if(flag)puts("no");
        else puts("yes");

    }
    return 0;
}
