#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<string>
using namespace std;

map<string,int>M;

string s[4];

void mj(int k)
{
    int i,j,e,n;
    string tmp;
    n=1<<k;
    for(i=1;i<n;i++)
    {
        tmp="";
        for(j=0;j<k;j++)
        {
            if(i&(1<<j))
            {
                tmp=tmp+s[j]+"+";
            }
        }
        M[tmp]++;
    }
}

int main()
{
    int i,n,k;
    string tmp;
    cin>>n;
    while(n--)
    {
        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>s[i];
        }
        sort(s,s+k);
        mj(k);
    }
    cin>>n;
    while(n--)
    {
        cin>>k;
        tmp="";
        for(i=0;i<k;i++)
        {
            cin>>s[i];
        }
        sort(s,s+k);
        for(i=0;i<k;i++)
        {
            tmp=tmp+s[i]+"+";
        }
        printf("%d\n",M[tmp]);
    }
    return 0;
}
