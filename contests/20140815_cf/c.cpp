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
int a[10005],b[10005];
vector<int>v[100005];
int num[100005];
int main()
{
    int i,j;
    int n,k,d;
    while(cin>>n>>k>>d)
    {
        for(i=1; i<=1000; i++)
            v[i].clear();
        memset(num,0,sizeof(num));
        if(k>=n)
        {
            for(i=1; i<=d; i++)
            {
                for(j=1; j<=n; j++)
                    cout<<j<<" ";
                cout<<endl;
            }
        }
        else
        {
            if(d==1)
                puts("-1");
            else
            {
                if(n>=k*k+1)
                    puts("-1");
                else
                {
                    int t = n/k;
                    if(n%k)t++;
                    j=0;
                    int f=1;
                    for(i=1; i<=n; i++)
                    {
                        j++;
                        if(j<=t)
                        {
                            a[i]=f;
                            v[f].push_back(i);
                        }
                        else
                        {
                            j = 1;
                            f++;
                            a[i]=f;
                            v[f].push_back(i);
                        }
                    }
                    for(int s=1; s<=k; s++)
                    {
                        for(i=1; i<=f; i++)
                        {
                            if(num[i]<v[i].size())
                            {
                                b[v[i][num[i]]]=s;
                                num[i]++;
                            }
                        }
                    }
                    for(i=1;i<k;i++)
                    {
                        for(j=1;j<=n;j++)
                            cout<<a[j]<<" ";
                        cout<<endl;
                    }
                    for(i=1;i<=n;i++)
                    {
                        cout<<b[i]<<" ";
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
