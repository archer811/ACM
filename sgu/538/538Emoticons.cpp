#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[100005];
int main()
{
    int i,j,k;
    while(gets(s))
    {
        int len = strlen(s);
        int flag=0,ans=0;
        for(i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                flag=1;
                ans++;
            }
            else if(s[i]==')')
            {
                if(flag)ans--;
                else ans++;
                flag=0;
            }
            else if(s[i]==32||(s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
                continue;
            else flag=0;
           // cout<<s[i]<<" "<<ans<<endl;
        }
        printf("%d\n",ans);
    }
}
