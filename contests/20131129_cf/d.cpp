#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int i,j,k;
    int n,m;
    while(cin>>n>>m>>k)
    {
        int sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>j;
            if(j==1)
            {
                if(m==0)sum++;
                else m--;
            }
            else
            {
                if(k==0)
                {
                    if(m==0)sum++;
                    else m--;
                }
                else k--;
            }
        }
        cout<<sum<<endl;
    }
}
