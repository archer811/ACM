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
char s[10000];
int main()
{
    int i,j;
    while(gets(s))
    {
        int len = strlen(s);
        int sum=0;
        set<int>t;
        t.clear();
        for(i=0;i<len;i++)
        {
            if(s[i]=='}'||s[i]=='{')continue;
            if(s[i]==',')
            {
               continue;
            }
            if(s[i]>='a'&&s[i]<='z')
            {
                sum=s[i]-'a';
            t.insert(sum);
            }

        }cout<<t.size()<<endl;

    }
    return 0;
}
