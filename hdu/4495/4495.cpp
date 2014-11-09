#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
char s[505][505];
int n,m;
int ans1[505][505],ans2[505][505],ans3[505][505],ans4[505][505];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
            scanf("%s",s[i]);
        memset(ans1,0,sizeof(ans1));
        memset(ans2,0,sizeof(ans2));
        memset(ans3,0,sizeof(ans3));
        memset(ans4,0,sizeof(ans4));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int tmp=0;
                if(i>=1&&j>=1)tmp=ans1[i-1][j-1]+2;
                int sum=0;
                for(int k=0;i-k>=0&&j-k>=0;k++)
                {
                    if(s[i][j-k]==s[i-k][j])sum++;
                    else break;
                }
                ans1[i][j]=max(ans1[i][j],min(sum,tmp));
                ans1[i][j]=max(ans1[i][j],1);
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=m-1;j>=0;j--)
            {
                int tmp=0;
                if(i>=1&&j<m-1)tmp=ans2[i-1][j+1]+2;
                int sum=0;
                for(int k=0;i-k>=0&&j+k<m;k++)
                {
                    if(s[i][j+k]==s[i-k][j])sum++;
                    else break;
                }
                ans2[i][j]=max(ans2[i][j],min(sum,tmp));
                ans2[i][j]=max(ans2[i][j],1);
            }
        }

        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<m;j++)
            {
                int tmp=0;
                if(i<n-1&&j>=1)tmp=ans3[i+1][j-1]+2;
                int sum=0;
                for(int k=0;i+k<n&&j-k>=0;k++)
                {
                    if(s[i][j-k]==s[i+k][j])sum++;
                    else break;
                }
                ans3[i][j]=max(ans3[i][j],min(sum,tmp));
                ans3[i][j]=max(ans3[i][j],1);
            }
        }

        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                int tmp=0;
                if(i<n-1&&j<m-1)tmp=ans4[i+1][j+1]+2;
                int sum=0;
                for(int k=0;i+k<n&&j+k<m;k++)
                {
                    if(s[i][j+k]==s[i+k][j])sum++;
                    else break;
                }
                ans4[i][j]=max(ans4[i][j],min(sum,tmp));
                ans4[i][j]=max(ans4[i][j],1);
            }
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(ans1[i][j]>ans)ans=ans1[i][j];
                if(ans2[i][j]>ans)ans=ans2[i][j];
                if(ans3[i][j]>ans)ans=ans3[i][j];
                if(ans4[i][j]>ans)ans=ans4[i][j];
            }
        }

        printf("%d\n",ans*(1+ans)/2);
    }
    return 0;
}
