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
const int inf = 1e9;
char s[10],t[2];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        int l = -inf-1,r = inf+1;
        int d;
        while(n--)
        {
            cin>>s>>d>>t;
            if(s[0]=='>'&&s[1]=='=')
            {
                if(t[0]=='Y')
                {
                    l = max(l,d);
                }
                else
                {
                    r = min(r,d-1);
                }
            }
            else if(s[0]=='<'&&s[1]=='=')
            {
                if(t[0]=='Y')
                {
                    r=min(r,d);
                }
                else
                {
                    l=max(l,d+1);
                }
            }
            else if(s[0]=='>')
            {
                if(t[0]=='Y')
                {
                    l = max(l,d+1);
                }
                else
                {
                    r = min(r,d);
                }
            }
            else if(s[0]=='<')
            {
                if(t[0]=='Y')
                {
                    r=min(r,d-1);
                }
                else
                {
                    l=max(l,d);
                }
            }
            //cout<<l<<" "<<r<<endl;
        }
        if(l>r)puts("Impossible");
        else cout<<l<<endl;
    }

    return 0;
}




