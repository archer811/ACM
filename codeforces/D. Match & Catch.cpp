#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
const int maxn = 15005;
int sa[maxn],t[maxn],t2[maxn],c[maxn],n;
char s[maxn],s2[maxn];
void getsa(int m)
{
    int i,j,*x=t,*y=t2;
    for(i=0;i<m;i++)
        c[i]=0;
    for(i=0;i<n;i++)
        c[x[i]=s[i]]++;
    for(i=1;i<m;i++)
        c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)
    {
        sa[--c[x[i]]]=i;
    }
    for(int k=1;k<=n;k*=2)
    {
        int p=0;
        for(i=n-k;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=k)y[p++]=sa[i]-k;
        for(i=0;i<m;i++)
            c[i]=0;
        for(i=0;i<n;i++)
            c[x[y[i]]]++;
        for(i=1;i<m;i++)
            c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)
            sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for(i=1;i<n;i++)
        {
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        }
        m=p;
    }
}
int rank[maxn],height[maxn];
void getheight()
{
    int i,j;
    for(i=0;i<n;i++)
        rank[sa[i]]=i;
    int k=0;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[j+k]==s[i+k])k++;
        height[rank[i]]=k;
    }
}
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    while(scanf("%s%s",s,s2)!=EOF)
    {
         n = strlen(s);
         int m=0;
         for(i=0;i<n;i++)
         {
             m = max(m,(int)s[i]);
         }
         int id=n;
         int mark=id;
         s[id++]='#';
         m = max(m,(int)s[id-1]);
         int len = strlen(s2);
         for(i=0;i<len;i++)
         {
             s[id++]=s2[i];
             m = max(m,(int)s[id-1]);
         }
         n = id;
         getsa(m+1);
         getheight();
         int ans=maxn+10;
//         for(i=0;i<n;i++)
//         {
//             cout<<sa[i]<<":  ";
//             for(j=sa[i];j<n;j++)
//                cout<<s[j];
//             cout<<endl;
////cout<<i<<" "<<sa[i]<<" "<<s[i]<<endl;
//         }
         for(i=0;i<n;i++)
         {
             if(i+1<n&&(  (sa[i+1]>mark&&sa[i]<mark)||(sa[i]>mark&&sa[i+1]<mark) ))
             {
                 int tmp = height[i+1];
                 int flag=0;
                 if(i>=1)
                 {
                     flag=max(flag,height[i]);
                     //cout<<flag<<"oo"<<tmp<<endl;
                 }
                 if(i+2<n)
                 {
                     flag=max(flag,height[i+2]);
                     //cout<<flag<<"--"<<tmp<<endl;
                 }
                 if(flag<tmp)
                 {
//                     cout<<sa[i]<<"*"<<sa[i+1]<<" "<<tmp<<" "<<flag<<
//                     "()"<<i<<" "<<n<<endl;
                     ans=min(ans,min(flag+1,tmp));
                 }
             }
         }
         if(ans>=maxn)ans=-1;
         cout<<ans<<endl;
    }
    return 0;
}

