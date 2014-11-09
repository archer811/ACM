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
char s[1000000];
int main()
{
    int i,j;
    while(gets(s))
    {
        int len = strlen(s);
        s[len]=' ';
        int pre=0;
        int flag=0;
        for(i=0;i<=len;i++)
        {
            if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
            {
                int tmp = i-1-pre+1;
                if(tmp<=0)
                {
                    pre=i+1;
                    if(i!=len)
                    cout<<s[i];
                    continue;
                }
                if(tmp<3)
                {
                    for(j=pre;j<i;j++)
                        cout<<s[j];
                }
                else
                {
                    cout<<s[pre];
                    cout<<(i-1-pre+1-2);
                    cout<<s[i-1];
                }
                pre=i+1;
                if(i!=len)
                cout<<s[i];
            }
        }
        puts("");
    }
    return 0;
}
