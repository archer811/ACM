#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
char s[1005];
int main()
{
    int i,j;
    while(cin>>s)
    {
        int len = strlen(s);
        int sum=0;
        for(i=0;i<len;i++)
        {
            int f=1;
            int k=i;
            for(j=i+1;j<len;j++)
            {
                if(s[j]==s[i])
                {
                    //cout<<k<<" "<<j<<endl;
                    if((j-k)%2)
                    {
                        f++;k=j;
                    }
                }
            }
            if(f>sum)sum=f;
        }
        if(1>sum)sum=1;
        cout<<sum<<endl;
    }
}
