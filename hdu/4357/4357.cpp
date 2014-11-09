#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
char s1[100],s2[100];
int num[100];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        int len = strlen(s1);
        for(i=0;i<len;i++)
        {
            num[i]=0;
            while(s1[i]!=s2[i])
            {
                num[i]++;
                s1[i]=(s1[i]-'a'+1)%26+'a';
            }
            cout<<i<<" "<<num[i]<<endl;
        }
    }
    return 0;
}
