#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;

int main()
{
    int i,j;
    freopen("out.txt","w",stdout);
    cout<<rand()%225+1<<endl;
    for(i=1;i<=15;i++)
    {
        for(j=1;j<=15;j++)
        {
            cout<<rand()%1000<<" ";
        }
        cout<<endl;
    }
    return 0;
}

