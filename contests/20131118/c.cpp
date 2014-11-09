#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
double t1,t2,t0,x1,x2;
int main()
{
    double i,j,k;
    while(cin>>t1>>t2>>x1>>x2>>t0)
    {
        double ans=2000006;
        double l=1,r=1,M=-1;
        for(i=1;i<=(int)x1;i++)
        {
            j = i*(t0-t1)/(t2-t0);
            j+=100;
            if(x2<j)j=x2;
            //if(i==76)cout<<j<<" "<<(t1*i+t2*j)/(i+j)<<endl;
            while((i+j)>0&&(t1*i+t2*j)/(i+j)>=t0)
            {
                //if(i==76)cout<<j<<"*"<<endl;

                {
                    double g = (t1*i+t2*j)/(i+j)-t0;
                    //cout<<i<<" "<<j<<endl;
//                    if((i==76&&j==54)||(i==38&&j==27))
//                        cout<<i<<" "<<j<<" "<<
//                        g<<" "<<ans<<endl;
//                    if(i==76||i==110)cout<<i<<" "<<j<<" "<<g<<"*"<<
//
//                        "        "<<(t1*i+t2*j)<<" "<<i+j<<" "<<t0<<
//                        endl;
                    if(g<ans)
                    {
                        ans=g;
                        l=i;r=j;
                    }
                    else if(g==ans)
                    {
                        if(i+j>M)
                        {
                            M=i+j;l=i;r=j;
                        }
                    }
                }
                j--;
            }
        }
        cout<<l<<" "<<r<<endl;
    }
}
