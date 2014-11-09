#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int a[1005];
int main()
{
    int i,j,k;
    int n,l,r,sk,sall;
    while(cin>>n>>k>>l>>r>>sall>>sk)
    {
        for(i=1;i<=n;i++)
            a[i]=l;
//        for(i=1;i<=n;i++)
//            cout<<a[i]<<" ";
//        cout<<endl;
        int tmp = sall-sk-(n-k)*l;
        //cout<<n-k<<endl;
        if(n-k>0)
        {
            tmp = tmp/(n-k);
            for(j=k+1;j<=n;j++)
                a[j]+=tmp;
//

            tmp = sall-sk-(n-k)*l-(tmp*(n-k));
            //
            //cout<<tmp<<"@"<<endl;
            for(i=k+1;i<=n;i++)
            {
                if(tmp==0)break;
                //
                a[i]+=1;tmp--;
            }
        }
        tmp = sk-(k)*l;
        if(k>0)
        {
            tmp = tmp/(k);
            for(int t=0,j=k;t<k;t++,j--)
                a[j]+=tmp;

            tmp = sk-(k)*l-(tmp*(k));
            for(i=1;i<=k;i++)
            {
                if(tmp==0)break;
                a[i]+=1;tmp--;
            }
        }
        for(i=1;i<=n;i++)
            cout<<a[i]<<" ";
    }
}
