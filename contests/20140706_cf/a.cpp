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
int a[105][105];
char s[105][105];
int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<m;j++)
            {
                if(s[i][j]=='-')cout<<'-';
                else
                {
                    if((i+j)%2)cout<<"W";
                    else cout<<"B";
                }

            }
            cout<<endl;
        }
    }
    return 0;
}
