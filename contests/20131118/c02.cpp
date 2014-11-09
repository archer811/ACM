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
    int i,j,k;
    while(cin>>t1>>t2>>x1>>x2>>t0)
    {
        double ans=2000006;
        int a= (int)x1,b=(int)x2;
        if(t1==t2)
        {
            cout<<a<<" "<<b<<endl;
            continue;
        }
        if(t1==t0||t2==t0)
        {
            if(t1==t0)cout<<a<<" 0"<<endl;
            else cout<<"0 "<<b<<endl;
            continue;
        }
        int l=1,r=1,M=-1;
        for(i=0; i<=(int)x1; i++)
        {
            j = i*(t0-t1)/(t2-t0);
            j+=10;
            if(x2<j)j=x2;

            while((t1*i+t2*j)-(i+j)*t0>=0)
            {
                double g1 = (double)(t1*i+t2*j)/(double)(i+j)-t0;
                //if(i==2||i==4)printf("%d %d %.8f %.6f\n",i,j,g1,ans);
                if(g1<ans)
                {
                    ans=g1;
                    l=i;
                    r=j;
                    M=-1;
                }
                else if(g1==ans)
                {//cout<<l<<" "<<r<<" "<<M<<" "<<endl;
                    if(j>M)
                    {
                        M=j;
                        l=i;
                        r=j;
                    }
                }


                j--;
            }
        }
        if(l==0)cout<<l<<" "<<x2<<endl;
        else
        cout<<l<<" "<<r<<endl;
    }
}
