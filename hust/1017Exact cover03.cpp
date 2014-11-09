#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,k;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            for(k=1;k<=9;k++)
            {
                if((i-1)*81+(j-1)*9+k==109)
                    cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
}
