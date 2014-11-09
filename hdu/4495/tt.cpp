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
string a = "[(])";
int main()
{
    int i,j;
    srand(time(0));
    for(i=0;i<100;i++)
    {
        int d = rand()%4;
        cout<<a[d];
    }
}
