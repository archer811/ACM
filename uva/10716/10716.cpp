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
const int maxn = 8006;
char s[maxn];
int a[26],b[26];
char ans[maxn];
vector<int>v[26];
int now[maxn];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int len= strlen(s);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<26;i++)
            v[i].clear();
        memset(now,0,sizeof(now));
        int mark=-1;
        for(i=0;i<len;i++)
        {
            int x = s[i]-'a';
            a[x]++;
            v[x].push_back(i);
        }
        int flag=0;
        for(i=0;i<26;i++)
        {
            if(a[i]&1)
            {
                mark=i;
                flag++;
            }
        }
        if(flag>1)
        {
            puts("Impossible");
            continue;
        }

        int k=0;
        for(i=0;i<len;i++)
        {
            int x = s[i]-'a';
            b[x]++;
            if(b[x]<=a[x]/2)
                ans[k++]=s[i];
        }
        if(mark!=-1)
            ans[k++]=char(mark+'a');
        if(len&1)j=k-2;
        else j=k-1;
        for(i=j;i>=0;i--)
            ans[k++]=ans[i];
        ans[k]='\0';
        int sum=0;
        for(i=0;i<k;i++)
        {
            int x = ans[i]-'a';
            if(s[i]==ans[i])continue;
            for(j=i+1;j<len;j++)
            {
                if(s[j]==ans[i])
                {
                    for(int g=j;g>i;g--)
                    {
                        swap(s[g],s[g-1]);
                    }
                    sum += j-i;
                    break;
                }
            }
            //cout<<s<<endl;
        }
        printf("%d\n",sum);
    }
    return 0;
}
