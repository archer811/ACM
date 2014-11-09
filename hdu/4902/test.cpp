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
    cout<<1<<endl;
    cout<<400<<endl;
    for(i=0;i<400;i++)
        cout<<0<<" ";
    cout<<endl;
    cout<<20<<endl;
    for(i=0;i<20;i++)
    {
        int x=rand()%400;
        int y=rand()%400;
        if(x>y)swap(x,y);
        cout<<rand()%2+1<<" "<<x<<" "<<y<<" "<<rand()<<endl;
    }
    return 0;
}
