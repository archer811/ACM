#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[111];
int main()
{
    int i,j;
    while(cin>>s)
    {
        int len = strlen(s);
        int sum=0;
       // cout<<len<<endl;
        for(i=0;i<len;i++)
        {
            j=i;
            for(j=i+1;j<len;j++)
            {
                if(s[j]==s[i])continue;
                else
                {
                    j--;break;
                }
            }
            if(j==len)j--;
            cout<<i<<" "<<j<<endl;
            if((j-i+1)%2==0)sum++;
            i = j;
        }
        cout<<sum<<endl;
    }
}
