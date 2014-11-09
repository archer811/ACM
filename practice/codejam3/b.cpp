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
string s[105];
int n;
int fac[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
int a[30][10005];
int num[30];
int uncantor(int x, int k)
{
    int res[12];
    int i, j, l, t;
    bool h[12];
    for( i =0 ;i<12;i++)
        h[i]=false,res[i]=0;
    for (i = 1; i <= k; i++)
    {
        t = x / fac[k - i];
        x -= t * fac[k - i];
        for (j = 1, l = 0; l <= t; j++)
            if (!h[j])l++;
        j--;
        h[j] = true;
        res[i - 1] = j;
    }

    string tmp="";
    for(i=0;i<n;i++)
    {
        tmp += s[res[i]];
    }
    for(i=0;i<26;i++)
        num[i]=0;
    int len = tmp.length();
    for(i=0;i<len;i++)
    {
        j = tmp[i]-'a';
        a[j][num[j]++]=i;
    }
    //cout<<tmp<<endl;
    for(i=0;i<26;i++)
    {
        for(j=1;j<num[i];j++)
        {
            if(a[i][j]!=a[i][j-1]+1)return 0;
        }
    }
    return 1;
    //return res;
}
int judge(int x)
{
    int i,j;
    if(uncantor(x,n))return 1;
    return 0;
}
int main()
{
    int i,j;
//    freopen("B-small-attempt3.in","r",stdin);
//    freopen("out.txt","w",stdout);
    int cas=0,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            cin>>s[i];
            string tmp="";
            int len = s[i].length();
            tmp += s[i][0];
            for(j=1;j<len-1;j++)
            {
                if(s[i][j]==s[i][j-1]&&s[i][j]==s[i][j+1])
                    continue;
                tmp+=s[i][j];
            }
            tmp += s[i][len-1];
            //cout<<s[i]<<"*"<<tmp<<endl;
            s[i]=tmp;
        }
        int M = fac[n];
        //cout<<M<<endl;
        int sum=0;
        for(i=0; i<M; i++)
        {
            if(judge(i))sum++;
        }
        printf("Case #%d: %d\n",++cas,sum);
    }
    return 0;
}
