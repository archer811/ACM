#include<iostream>
using namespace std;
const int N = 1000006;
int a[N];
int main()
{
    int i,j;
    a[1]=a[0]=1;
    for(i=2;i<N;i++)
    {
        for(j=i+i;j<N;j+=i)
            a[j]=1;
    }
    int n;
    while(cin>>n)
    {
        for(i=2;i<=n;i++)
        {
            if(a[i]&&a[n-i])
            {
                cout<<i<<" "<<n-i<<endl;
                break;
            }
        }
    }
    return 0;
}
