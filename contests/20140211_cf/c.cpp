#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int s[101][101];
int main()
{
    int i,j,n;
    while(cin>>n)
    {
        memset(s,0,sizeof(s));
        int hen=0,shu=0;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            s[a][b]=1;
        }
        for(i=0;i<=100;i++)
        {
            int f=0;
            for(j=0;j<=100;j++)
            {
                if(s[i][j])f=1;
            }
            if(f)hen++;
        }
        for(i=0;i<=100;i++)
        {
            int f=0;
            for(j=0;j<=100;j++)
            {
                if(s[j][i])f=1;
            }
            if(f)shu++;
        }
        cout<<min(hen,shu)<<endl;
    }
}
