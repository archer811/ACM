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
char s[1000];
int main()
{
    int i,j,k;
    while(scanf("%s%d",s,&k)!=EOF)
    {
        int len=strlen(s);
        int ans=0;
        if(k>=len)ans=len+k;
        if(ans%2)ans--;
        for(i=0;i<len;i++)
        {
            for(j=i;j<len;j++)
            {
                int l=j+1;
                int sum=0;
                for(int t=i;t<=j;t++)
                {
                    if(l>=len+k)break;
                    if(l>=len||s[t]==s[l])
                        sum++;
                    if(l<len&&s[t]!=s[l])break;
                    l++;
                }
                //cout<<j-i+1<<endl;
                if(sum>=j-i+1)ans=max(ans,2*(j-i+1));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
