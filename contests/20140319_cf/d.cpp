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
int main()
{
    int i,j,k;
    for(i=-1;i<=2;i++)
    {
        for(j=-1;j<=2;j++)
        {
            for(k=-1;k<=2;k++)
            {
                if(i==-1&&k==-1&&j!=2)continue;
                if(j!=-1&&(i==2||k==2))continue;
                if(i==0&&j==-1)continue;
                if(j==0&&(i==-1||k==-1))continue;
                if(k==0&&j==-1)continue;
                if(j==2&&(!(i==-1&&k==-1)))continue;
                if(i!=-1&&k!=-1&&j!=0)continue;
                cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
}
