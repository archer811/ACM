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
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            cout<<char('a'+(rand()%26));
        cout<<endl;
    }
}
