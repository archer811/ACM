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
    int i,j,k;
    int g=20;
    freopen("out1.txt","w",stdout);
    while(g--)
    {
        int n=rand()%20;
        int m = 20-n;
        k = rand()%6;
        cout<<n<<" "<<m<<" "<<k<<endl;
        while(k--)
        {
            cout<<rand()%10+1<<endl;
        }
    }
}
