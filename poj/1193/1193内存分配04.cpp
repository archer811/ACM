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
    int i,j,k,n;
    freopen("out.txt","w",stdout);
    cin>>n;
    int g =20000;
    cout<<n<<endl;

    while(cin>>i>>j>>k)
    {
        //cout<<j<<endl;
        //if(g>k)g=k;
        cout<<i<<" "<<j-40<<" "<<k<<endl;
    }
    //cout<<g<<endl;
}
