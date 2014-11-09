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
    int a,b;
    while(cin>>a>>b)
    {
        int flag=0;
        for(i=1; i<a&&flag==0; i++)
        {
            for(j=1; j<b&&flag==0; j++)
            {
                if(i==j)continue;
                int tmp = a*a-i*i;
                int g1 = sqrt(tmp);
                if(g1*g1!=tmp)continue;
                tmp = b*b-j*j;
                int g2 = sqrt(tmp);
                if(g2*g2!=tmp)continue;
                if(i*j!=g1*g2)continue;
                flag=1;
                puts("YES");
                cout<<0<<" "<<i<<endl;
                cout<<g1<<" "<<0<<endl;
                cout<<g1+g2<<" "<<j<<endl;
                break;
            }
        }
        if(flag==0)
        {
            if(a>b)swap(a,b);
            int tt = b*b-a*a;
            int t2 = sqrt(tt);
            if(t2*t2==tt)
            {
                b = t2;
                for(i=1; i<a&&flag==0; i++)
                {
                    for(j=1; j<b&&flag==0; j++)
                    {
                        if(i==j)continue;
                        int tmp = a*a-i*i;
                        int g1 = sqrt(tmp);
                        if(g1*g1!=tmp)continue;
                        tmp = b*b-j*j;
                        int g2 = sqrt(tmp);
                        if(g2*g2!=tmp)continue;
                        if(i*j!=g1*g2)continue;
                        flag=1;
                        puts("YES");
                        cout<<0<<" "<<i<<endl;
                        cout<<g1<<" "<<0<<endl;
                        cout<<g1+g2<<" "<<j<<endl;
                        break;
                    }
                }
            }

        }
        if(flag==0)
            puts("NO");
    }
}
