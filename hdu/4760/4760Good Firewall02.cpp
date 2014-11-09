#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[30];
int main()
{
    cin>>s;
    int i,j = strlen(s);
    __int64 sum =0;
    for(i=0;i<j;i++)
        sum = sum*(__int64)2+s[i]-'0';
    cout<<sum<<endl;
}
