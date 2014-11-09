#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a[5][5];
vector<int>v;

int dx(int temp)
{
    return (temp-1)/4 + 1;
}

int dy(int temp)
{
    return (temp-1)%4 + 1;
}

bool find()
{
    int re = 0;
    for(int i=0;i<v.size();i++)
    {
        for(int u=i+1;u<v.size();u++)
        {
            if(v[i]>v[u])
            {
                re++;
            }
        }
    }
    int temp;
    for(int i=1;i<=4;i++)
    {
        for(int u=1;u<=4;u++)
        {
            if(!a[i][u]) continue;
            temp = a[i][u];
            re += abs(dx(temp)-i);
        }
    }
    re%=2;
    if(re) return false;
    else return true;
}

int main()
{
    v.clear();
    for(int i=1;i<=4;i++)
    {
        for(int u=1;u<=4;u++)
        {
            cin>>a[i][u];
            if(a[i][u])
            v.push_back(a[i][u]);
        }
    }
    if(find())
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
