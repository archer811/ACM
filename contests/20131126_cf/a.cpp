#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,d,a[105];
multiset<int>s;
multiset<int>::iterator it;
int main()
{
    int i,j,k,m;
    while(cin>>n>>d)
    {
        s.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        cin>>m;
        int sum=0;
        j=0;
        k=0;
        for(it=s.begin(),k=0;k<n;it++,k++)
        {
            sum += (*it);
            //cout<<k<<" "<<sum<<endl;
            //k++;
            j++;
            if(j==m)break;
        }
        while(j<m)sum-=d,j++;
        cout<<sum<<endl;
    }
}
