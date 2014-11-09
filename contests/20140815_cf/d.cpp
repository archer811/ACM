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
vector<int>v[100005],v2[10004];
int num[100005];
int main()
{
    int i,j;
    int n,k,d;
    while(cin>>n>>k>>d)
    {
        for(i=1; i<=1000; i++)
            v[i].clear(),v2[i].clear();
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
            int x=n;
            for(i=1;i<=d;i++)
            {
                int g = x/k;
                if(x%k)g++;
                x = g;
            }
            if(x>1)
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
                for(i=1;i<=n;i++)
                    cout<<a[i]<<" ";
                cout<<endl;
                int flag=0;
                for(int g=1;g<=d-1;g++)
                {
                    for(i=1;i<=f;i++)
                    {
                        int j2=0;
                        int f2=1;
                        t = v[i].size()/k;
                        if(v[i].size()%k)t++;
                        if(g==d-1&&t>1)flag=1;
                        for(j=0;j<v[i].size();j++)
                        {
                            j2++;
                            if(j2<=t)
                            {
                                b[v[i][j]]=f2;
                                v2[f2].push_back(v[i][j]);
                            }
                            else
                            {
                                f2++;
                                j2=1;
                                b[v[i][j]]=f2;
                                v2[f2].push_back(v[i][j]);
                            }
                        }
                    }
                    for(i=1;i<=n;i++)
                        cout<<b[i]<<" ";
                    cout<<endl;
                    f=k;
                    for(i=1;i<=n;i++)
                    {
                        for(j=0;j<v[i].size();j++)
                            cout<<v2[i][j]<<"*";
                        cout<<endl;
                    }
                    for(i=1;i<=f;i++)
                        v[i]=v2[i],v2[i].clear();
                }
            }
        }
    }
    return 0;
}
