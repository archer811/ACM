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
#define ll long long
ll a[10],b[10];
int z[10],mark[10];
int main()
{
    int i,j,t;
    a[0]=0;
    for(i=1; i<=6; i++)
    {
        ll tmp = 1;
        for(j=1; j<=i; j++)
            tmp = tmp*i%7;
        a[i]=tmp;
    }
    for(i=0;i<=6;i++)
    {
        for(j=0;j<=6;j++)
            mark[j]=0;
        int tmp=0;
        ll now = a[i];
        while(mark[now]==0)
        {
            mark[now]=1;
            //cout<<now<<" ";
            now = now*i%7;
            tmp++;
        }
        //cout<<endl;
        z[i]=tmp;
        //cout<<i<<" * "<<tmp<<endl;
    }
    ll n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(b,0,sizeof(b));
        int tmp = n/7;
        for(i=0; i<=6; i++)
            b[i]=tmp;
        n = n-tmp*7;
        for(i=0; i<=6&&i<=n; i++)
            b[i]++;
//        for(i=0;i<=6;i++)
//            cout<<i<<""<<b[i]<<" "<<a[i]<<endl;
//        cout<<n<<endl;
        int sum=0;
        for(i=0; i<=6; i++)
        {
            if(b[i]>=z[i])
            {
                ll tp = a[i];
                ll x = b[i]/z[i];
                for(j=0;j<z[i];j++)
                {
                    sum = sum+tp*(x)%7;
                    sum%=7;
                    tp = tp*i%7;
                }
            }
            b[i]-=(b[i]/z[i])*z[i];
//            cout<<i<<"()"<<b[i]<<endl;
            int tmp = a[i];
            for(j=1;j<=b[i];j++)
            {
                sum = sum+tmp%7;
                sum%=7;
//                cout<<tmp<<" ";
                tmp = tmp*i%7;
            }
//            cout<<endl;
//            cout<<sum<<endl;
        }
//        cout<<sum<<endl;
        int x = (6+sum)%7;
        if(x==0)puts("Sunday");
        else if(x==1)puts("Monday");
        else if(x==2)puts("Tuesday");
        else if(x==3)puts("Wednesday");
        else if(x==4)puts("Thursday");
        else if(x==5)puts("Friday ");
        else if(x==6)puts("Saturday");

    }
}
