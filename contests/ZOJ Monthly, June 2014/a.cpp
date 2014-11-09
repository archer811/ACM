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
int GetHighest(double a,double b)
{
    double intpart;
    double fractpart = modf(b*log10(a),&intpart);
    double temp=pow((double)10,fractpart);
    modf(temp,&intpart);
    return (int)intpart;
}
int main()
{
    int t;
    double a,b;
    while(cin>>t)
    {
        int flag=0;
        int i,j;
        for(i=0,j=0; i<t; i++)
        {
            cin>>a>>b;
            int tmp=GetHighest(a,b);
            j++;
            double g = j*1.0/t;
            if(g>=0.25&&g<0.6)
                flag=1;
            if(flag)
            {
                if(tmp==1)cout<<9<<endl;
                else cout<<tmp-1<<endl;
            }
            else
                cout<<tmp<<endl;
        }
    }


}
