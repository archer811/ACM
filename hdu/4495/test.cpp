#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    char str[111];
    memset(str,0,sizeof(str));
    cin>>t;
    while (t--)
    {
        cin>>str;
        int len=strlen(str);
        int an[111];
        memset(an,0,sizeof(an));
        int count=0;
        for (int i=0 ;i<len ;i++)
        {
            if (an[i]) continue;
            if (str[i]==']' || str[i]==')')
            {
                int j;
                int cnt=0;
                for (j=i-1 ;j>=0 ;j--)
                {
                    if (an[j]) continue;
                    else if ((str[i]==')'&&str[j]=='(')||(str[i]==']'&&str[j]=='['))
                    {
                        count += cnt;
                        cnt=0;
                        for (int k=j ;k<=i ;k++) an[k]=1;
                        break;
                    }
                    else
                    {
                        cnt++;
                    }
                }
            }
        }
        for (int i=0 ;i<len ;i++) if (!an[i]) count++;
        cout<<count<<endl;
    }
    return 0;
}
