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
    int i,j,n;
    while(cin>>n)
    {
        int su=0;
        int now=0;
        for(i=1;i<=n;i++)
        {
            cin>>j;
            now+=j;
            if(now<0)su++,now=0;
        }
        cout<<su<<endl;
    }
    return 0;
}
