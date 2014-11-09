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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        if(c==a)
        {
            int tmp = d-b;
            if(tmp<0)tmp=-tmp;
            cout<<a+tmp<<" "<<b<<endl;
            cout<<a+tmp<<" "<<d<<endl;
        }
        else if(b==d)
        {
            int tmp = a-c;
            if(tmp<0)tmp=-tmp;
            cout<<a<<" "<<b+tmp<<endl;
            cout<<c<<" "<<d+tmp<<endl;
        }
        else
        {
            int t1=a-c;
            int t2=b-d;
            if(t1<0)t1=-t1;
            if(t2<0)t2=-t2;
            if(t1!=t2)puts("-1");
            else
            {
                //if(c>=a&&d>=b)
                {
                    cout<<a<<" "<<d<<endl;
                    cout<<c<<" "<<b<<endl;
                }

            }
        }
    }
    return 0;
}
