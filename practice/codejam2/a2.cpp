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
char s[105][105];
vector<int>v;
int num[105],st[105],ll[105];
int main()
{
    int i,j,T;
//    freopen("A-large.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int n;
    int cas=0;
    while(T--)
    {
        scanf("%d",&n);
        memset(st,0,sizeof(st));
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            ll[i] = strlen(s[i]);
        }
        int len = strlen(s[0]);
        v.clear();
        for(i=0;i<len;i++)
        {
            if(i==0||s[0][i]!=s[0][i-1])
            {
                v.push_back(s[0][i]-'a');
            }
        }
        int o=0;
        for(i=1;i<n;i++)
        {
            len = ll[i];
            j=0;
            if(o)break;
            for(int k=0;k<v.size();k++)
            {
                if(j>=len){o=1;break;}
                if(v[k]!=s[i][j]-'a'){o=1;break;}
                while(j<len&&s[i][j]-'a'==v[k])
                {
                    j++;
                }
            }
            if(j<len){o=1;break;}
        }
        int sum=0;
        if(o==0)
        {
            for(i=0;i<v.size();i++)
            {
                for(j=0;j<n;j++)
                {
                    num[j]=0;
                    while(st[j]<ll[j]&&s[j][st[j]]-'a'==v[i])
                    {
                        num[j]++;st[j]++;
                    }
                }
                int M=-1;
                for(j=0;j<n;j++)
                {
                    if(num[j]>M)M=num[j];
                }
                int tt=-1;
                for(int k=1;k<=M;k++)
                {
                    int tmp=0;
                    for(j=0;j<n;j++)
                    {
                        if(num[j]>k)tmp+=num[j]-k;
                        else tmp+=k-num[j];
                    }
                    if(tt==-1||tt>tmp)
                        tt=tmp;
                }
                if(tt!=-1)
                    sum+=tt;
            }
        }

        if(o)
            printf("Case #%d: Fegla Won\n",++cas);
        else
            printf("Case #%d: %d\n",++cas,sum);
    }
    return 0;
}
