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
char s[10000],t[10000];
int main()
{
    int i,j;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int k=0;
    for(i=0;i<38;i++)
    {
        gets(s);
        int len=strlen(s);
        if(len==0)continue;
        for(j=0;j<len;j++)
        {
            if(s[j]==' ')continue;
            t[k++]=s[j];
        }
        //t[k++]='\n';
    }
    cout<<strlen(t)<<endl;
    cout<<t<<endl;
}
