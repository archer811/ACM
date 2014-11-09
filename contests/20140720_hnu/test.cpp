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
    int i,j;
    freopen("t.txt","w",stdout);
    cout<<99*100*2<<endl;
    for(i=1;i<=99;i++)
    {
        for(j=1;j<=100;j++)
        {
            for(int k=1;k<=2;k++)
                cout<<i<<" "<<j<<" "<<k<<endl;
        }
    }
    return 0;
}
