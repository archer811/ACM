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
string a[1005];
int main()
{
    int i,j;
    int n,m;
    while(cin>>n>>m)
    {
        for(i=0;i<m;i++)
            cin>>a[i];
            n--;
        n = n%m;
        cout<<a[n]<<endl;
    }
    return 0;
}
