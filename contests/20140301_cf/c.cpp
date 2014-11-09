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
#define ll __int64
int main()
{
    int i,j;
    ll a,b;
    while(cin>>a>>b)
    {
        ll sum = a*a-b*b;
        ll y=1;
        for(ll x=2; x<=b; x++)
        {
            ll g1 = b/x;
            ll g2 = b%x;
            ll tmp1 = (x-g2)*g1*g1+g2*(g1+1)*(g1+1);
            //cout<<tmp1<<endl;
            ll tmp2=0;
            if(a<=x-1)
            {
                tmp2 = a;
                g1 = b/(a+1);
                g2 = b%(a+1);
                tmp1 = (x-g2)*g1*g1+g2*(g1+1)*(g1+1);
            }
            else
            {
                ll s1 = a/(x-1);
                ll s2 = a%(x-1);
                tmp2 = (x-1-s2)*s1*s1+s2*(s1+1)*(s1+1);
            }
            if(sum<tmp2-tmp1)
            {
                sum=tmp2-tmp1;
                y=x;
            }
        }
        cout<<sum<<endl;
        ll x= y;
        //cout<<x<<endl;
        ll g1 = b/x;
        ll g2 = b%x;
        ll tmp1 = (x-g2)*g1*g1+g2*(g1+1)*(g1+1);
        //cout<<tmp1<<endl;
        ll tmp2=0;
        if(a<=x-1)
        {
            g1 = b/(a+1);
            g2 = b%(a+1);
            ll k = a;
            for(i=0; i<x-g1; i++)
            {
                for(j=0; j<g1; j++)
                    cout<<"x";
                if(k)
                {
                    k--;
                    cout<<"o";
                }
            }
            for(i=0; i<g1; i++)
            {
                for(j=0; j<g1+1; j++)
                    cout<<"x";
                if(k)
                {
                    k--;
                    cout<<"o";
                }
            }
        }
        else
        {
            //cout<<x<<" "<<a<<" "<<b<<endl;
            if(x==1)
            {
                for(i=0; i<a; i++)
                    cout<<"x";
                for(i=0; i<b; i++)
                    cout<<"o";
                cout<<endl;
            }
            else
            {
                ll s1 = a/(x-1);
                ll s2 = a%(x-1);
                i=0;
                j=0;
                for(int k=0; k<y-1; k++)
                {
                    int t;
                    if(i<y-g2)
                        t = g1;
                    else t = g1+1;
                    for(int m=0; m<t; m++)
                        cout<<"x";
                    if(j<y-s2)
                        t=s1;
                    else t = s1+1;
                    for(int m=0; m<t; m++)
                        cout<<"o";
                    i++;
                    j++;
                }
                int t;
                if(i<y-g2)
                    t = g1;
                else t = g1+1;
                for(int m=0; m<t; m++)
                    cout<<"x";
            }


        }
        cout<<endl;
    }
}
