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
    freopen("out.txt","w",stdout);
    cout<<"10 300"<<endl;
    for(i=0;i<300;i++)
    {
        if(i&1)cout<<-100000<<endl;
        else cout<<100000<<endl;
    }
    return 0;
}
