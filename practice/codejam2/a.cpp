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
int f[1005][30];
char s[1005];
int main()
{
    int i,j,t;
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int n;
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            int len = strlen(s);
            for(j=0;j<len;j++)
            {
                f[i][s[j]-'a']++;
            }
        }
        int o=0;
        int ans=0;
        for(i=0;i<26;i++)
        {
            if(o)break;
            int mark=0;
            for(j=0;j<n;j++)
            {
                if(f[j][i]){mark=1;break;}
            }
            if(mark)
            {
                int M=-1;
                for(j=0;j<n;j++)
                {
                    if(f[j][i]==0){o=1;break;}
                    if(f[j][i]>M)M=f[j][i];
                }
                if(o)break;
                int sum=-1;
                for(int k=1;k<=M;k++)
                {
                    int tmp=0;
                    for(j=0;j<n;j++)
                    {
                        if(f[j][i]==k)continue;
                        else if(f[j][i]>k)tmp+=f[j][i]-k;
                        else tmp+=k-f[j][i];
                    }
                    if(sum==-1||sum>tmp)sum=tmp;
                    //cout<<i<<" "<<k<<" "<<sum<<endl;
                }

                if(sum!=-1)
                ans+=sum;
            }
        }
        if(o)
            printf("Case #%d: Fegla Won\n",++cas);
        else
            printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
