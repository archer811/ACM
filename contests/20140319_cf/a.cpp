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
char s[1000][1000];
int main()
{
    int i,j;
    int n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>s[i];
        int a[26]={0};
        int f=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                 a[s[i][j]-'a']++;
                 if(i==j&&s[i][j]!=s[0][0])f=1;
                 if(i+j==n-1&&s[i][j]!=s[0][0])f=1;
                 if(i!=j&&i+j!=n-1&&s[i][j]==s[0][0])f=1;
            }

        }
        int sum=0;
        for(i=0;i<26;i++)
            if(a[i])sum++;
        if(sum!=2||f)puts("NO");
        else puts("YES");
    }
}
