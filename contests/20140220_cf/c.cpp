#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
struct array
{
    int a,b;
} s[1000005];
int n,m;
char g[10];
int cmp(array x,array y)
{
    return x.a+x.b>y.a+y.b;
}
int f;
int judge(int mid)
{
    int i,j;
    int k=0;
    for(i=0; i<m; i++)
    {
        int gg=0,hh=0;
        while(k<f)
        {
            hh++;
            if(s[k].a)gg++;
            k++;
            if(gg==mid)break;
            if(hh==n)break;
        }
    }
    if(s[k].a)return 0;
    return 1;
}
int ans[1004][1004][2];
int vis[1004][1004][2];
void output(int mid)
{
    int i,j;
    //cout<<mid<<endl;

    int k=0;
    for(i=0; i<m; i++)
    {
        int gg=0,hh=0;
        while(k<f)
        {
            if(s[k].a)
            {
                // cout<<k<<endl;
                gg++;
                ans[hh][i][0]=s[k].a;
                ans[hh][i][1]=s[k].b;
                vis[hh][i][0]=vis[hh][i][1]=1;
            }
            hh++;
            k++;
            if(gg==mid)break;
            if(hh==n)break;
        }
    }

    while(k<f)
    {
        for(i=m-1; i>=0&&f>k; i--)
        {
            for(j=n-1; j>=0&&f>k; j--)
            {

                if(vis[j][i][0]==0)
                {
                    //cout<<j<<" "<<i<<endl;
                    ans[j][i][0]=s[k].b;
                    ans[j][i][1]=s[k].a;
                    vis[j][i][1]=1;
                    k++;
                }
            }
        }
    }

}
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        f=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                scanf("%s",g);
                s[f].a=g[0]-'0';
                s[f].b=g[1]-'0';
                if(s[f].a<s[f].b)
                    swap(s[f].a,s[f].b);
                f++;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                ans[i][j][0]=ans[i][j][1]=0;
                vis[i][j][0]=vis[i][j][1]=0;
            }
        }
        sort(s,s+f,cmp);
        int num1=0,num2=0;
        for(i=0; i<f; i++)
        {
            if(s[i].a==1&&s[i].b==1)num1++;
            if(s[i].a==1&&s[i].b==0)num2++;
        }
//cout<<num1<<" "<<num2<<endl;

        //num1 = 2;num2 = 8;

        int tmp = num1/m;
        int tmp2 = num1%m;
        int tmp3 = m-tmp2;
       // cout<<num1<<" "<<tmp<<"**"<<tmp2<<endl;
        for(i=0; i<tmp; i++)
        {
            for(j=0; j<m; j++)
            {
                ans[i][j][0]=1;
                ans[i][j][1]=1;
            }
        }
        for(i=0; i<tmp2; i++)
            ans[tmp][i][0]=ans[tmp][i][1]=1;

        int g1 = (num2-tmp3)/m;
        int g2 = (num2-tmp3)%m;
       // cout<<g1<<" "<<g2<<" "<<num2<<" "<<tmp3<<endl;
        if(num2<=tmp3)
        {
            for(i=tmp2; i<m&&i<tmp2+num2; i++)
            {
                ans[tmp][i][0]=1;
                ans[tmp][i][1]=0;
            }
        }
        else
        {
            for(i=tmp2; i<m; i++)
            {
                ans[tmp][i][0]=1;
                ans[tmp][i][1]=0;
            }
            for(i=tmp+1; i<tmp+1+g1; i++)
            {
                for(j=0; j<m; j++)
                    ans[i][j][0]=1,ans[i][j][1]=0;
            }
            for(j=tmp2; j<tmp2+g2&&j<m; j++)
                ans[i][j][0]=1,ans[i][j][1]=0;
           // cout<<g2<<" "<<tmp3<<endl;
            g2 -= tmp3;//i++;

            for(j=0;j<g2;j++)
            {
                ans[i][j][0]=1;ans[i][j][1]=0;
            }
        }

        for(j=0;j<m;j++)
        {
            int ff=0;
            for(i=0;i<n;i++)
            {
                if(ff==0&&ans[i][j][0]==1&&ans[i][j][1]==0)
                {
                    ff=1;
                }
                else if(ff&&ans[i][j][0]==1&&ans[i][j][1]==0)
                {
                    ff=0;
                    ans[i][j][0]=0;
                    ans[i][j][1]=1;
                }
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                printf("%d%d ",ans[i][j][0],ans[i][j][1]);
            puts("");
        }
    }
}
