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
int a[50000];
int main()
{
    int i,j;
    int x,k;
    while(cin>>x>>k)
    {
        memset(a,-1,sizeof(a));
        int mark,l,r;
        for(i=0;i<k;i++)
        {
            cin>>mark;
            if(mark==1)
            {
                cin>>l>>r;
                if(l>r)swap(l,r);
                a[l]=2;a[r]=1;
            }
            else
            {
                cin>>l;
                a[l]=2;
            }
        }
        int s1=0,s2=0;
        for(i=1;i<x;i++)
        {
            if(a[i]==-1)s2++;
        }
        for(i=1;i<x;i++)
        {
            if(a[i]==-1)
            {
                if(i+1<x&&a[i+1]==-1)
                {
                    s1++;i=i+1;
                }
                else
                {
                    s1++;
                }
            }
        }
        cout<<s1<<" "<<s2<<endl;
    }
}
