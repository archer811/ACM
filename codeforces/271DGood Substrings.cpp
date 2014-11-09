#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[2000],che[30];
#define ull unsigned long long
int a[2265025][26];
int main()
{
    int i,j,k;
    cin>>s>>che>>k;
    int len = strlen(s);
    int n=1;
    for(i=0;i<len;i++)
    {
        int t=0,p=0;
        for(j=i;j<len;j++)
        {
            if(che[s[j]-'a']=='0')t++;
            if(t>k)
            {
                break;
            }
            if(a[p][s[j]-'a']==0)a[p][s[j]-'a']=n++;
            p=a[p][s[j]-'a'];
        }
    }
    cout<<n-1<<endl;
}
