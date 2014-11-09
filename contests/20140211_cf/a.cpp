#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n,k,w;
char s[100005];
int a[100005][11];
int main()
{
    int i,j;
    while(cin>>n>>k>>w)
    {
        cin>>s;
        int len = strlen(s);
        memset(a,0,sizeof(a));
        for(i=1;i<=len;i++)
        {
            j = s[i-1]-'0';
            int tmp = i%k;
            a[i][tmp]=j;//cout<<a[i][0]<<" ";
        }
        for(i=1;i<=len;i++)
        {
            for(j=0;j<k;j++)
                a[i][j]+=a[i-1][j];
        }
       // cout<<endl;
        int x,y;
        while(w--)
        {
           cin>>x>>y;
           int sum=0;
           int g=  x+k-1;
           g %= k;
           for(i=0;i<k;i++)
           {
               if(i==g)continue;
               sum += a[y][i]-a[x-1][i];
               //cout<<i<<" "<<a[y][i]-a[x-1][i]<<endl;
           }

           int tmp = a[y][g]-a[x-1][g];
           //cout<<tmp<<endl;
           tmp = (y-x+1)/k-tmp;
           sum += tmp;
           //cout<<tmp<<endl;
           cout<<sum<<endl;
        }
    }
}
