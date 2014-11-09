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
const int maxn = 100005;
int f[maxn];
char s[maxn];
int num[maxn];
struct o
{
    int index,v;
}g[maxn];
vector<int>v;
int cmp(o x,o y)
{
    return x.v>y.v;
}
int main()
{
    int i,j;
    while(scanf("%s",s)!=EOF)
    {
        v.clear();
        memset(num,0,sizeof(num));
        f[0]=0;
        f[1]=0;
        int m=strlen(s);
        for(i=1;i<m;i++)
        {
            j = f[i];
            while(j&&s[i]!=s[j])
                j=f[j];
            f[i+1]=(s[i]==s[j]?j+1:0);
        }

        j=f[m];
        while(j)
        {
            v.push_back(j);
            j=f[j];
        }
        for(i=1;i<=m;i++)
            num[f[i]]++;
        for(i=1;i<=m;i++)
        {
            g[i].index=i;
            g[i].v=f[i];
        }
//        for(i=0;i<=m;i++)
//        {
//            cout<<i<<"      "<<f[i]<<endl;
//        }
        sort(g+1,g+1+m,cmp);
        int pre=-1;
        for(i=1;i<=m;i++)
        {
            int tmp=g[i].index;
            //cout<<g[i].v<<endl;
            j=f[tmp];
            if(j==pre)continue;
            pre=j;
            if(j==0)continue;
            int k=f[j];
            //cout<<k<<" @ "<<j<<" "<<num[k]<<" "<<num[j]<<"()"<<num[j]+num[k]<<endl;
            num[k]+=num[j];
        }
//        for(i=0;i<=m;i++)
//        {
//            cout<<i<<"@#!@#!@#"<<num[i]<<endl;
//        }
        v.push_back(m);
        sort(v.begin(),v.end());
        cout<<v.size()<<endl;

        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" "<<num[v[i]]+1<<endl;
        }
    }
    return 0;
}
