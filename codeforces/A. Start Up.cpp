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
char s[100005];
int main()
{
    int i,j;
    while(cin>>s)
    {
        int len = strlen(s);
        if(len&1)
        {
            i=len/2;j=len/2;
        }
        else
        {
            j = len/2;i = j-1;
        }
        int f=0;
        while(i>=0&&j<len)
        {
            if(s[i]!=s[j])
            {
                puts("NO");f=1;break;
            }
            i--;j++;
        }
        if(f==0)
        {
            for(i=0;i<len;i++)
            {
                if(s[i]=='A'||s[i]=='H'||s[i]=='I'||s[i]=='M'
                   ||s[i]=='M'||s[i]=='O'||s[i]=='T'
                   ||s[i]=='U'||s[i]=='V'||s[i]=='W'||s[i]=='X'
                   ||s[i]=='Y');
                else
                {
                    puts("NO");f=1;break;
                }
            }
            if(f==0)puts("YES");
        }
    }
}
