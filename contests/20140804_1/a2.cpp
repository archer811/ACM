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
int a[66];
int d[2][262145];
int b[105];
int c[30];
const int inf = 0x3fffffff;
int ok[33][63];
int MM;
int fun(int a,int b)
{
    if(b==1)
    {
        MM=1;
        int mtp =a-1;
        if(mtp<0)mtp=-mtp;
        return mtp;
    }
    int b2=b;
    int ans=-1;
    while(b!=1&&b<a)
    {
        if(ans==-1||a-b<ans)
        {
            MM=b;ans=a-b;
        }

        b = b*b2;
    }
    if(b<a)b=b*b2;
    int flag=0;
    while(b>=a&&flag==0)
    {
        if(ans==-1||b-a<ans)
        {
            MM=b;ans=b-a;
        }

        b = b*b2;
        flag=1;
    }
    return ans;
}

int f[32][63];
struct array
{
    int pre,v;
}o[105][262145];
int ans[33];
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    int k=0;
    c[k++]=1;
    for(i=2;i<=59;i++)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<=59;j+=i)
                a[j]=1;
            c[k++]=i;
        }
    }

    //cout<<k<<endl;
    for(i=0;i<=30;i++)
    {
        for(j=0;j<=59;j++)
        {
            f[i][j]=fun(i,j);
            ok[i][j]=MM;
            //cout<<i<<" "<<c[j]<<" "<<f[i][c[j]]<<" "<<MM<<endl;
        }

    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        //cout<<c[0]<<endl;
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        if(n==1)
        {
            cout<<b[1]<<endl;
            continue;
        }
        memset(d,127,sizeof(d));

        d[0][0]=0;
        int M = (1<<k)-1;
        //cout<<M<<endl;
        int now=1,now2=0;
        //cout<<c[0]<<"()"<<endl;
        for(i=1;i<=n;i++)
        {
            //cout<<c[0]<<endl;

            for(j=0;j<k;j++)
            {
                for(int g=0;g<=M;g++)
                {
                    if(j!=0&&((1<<j)&g)==0)
                    {

                        if(d[now2][g]>=inf)continue;
                        int tp=g|(1<<j);
                        if(d[now2][g]+f[b[i]][c[j]]<d[now][tp])
                        {
                            d[now][tp]=d[now2][g]+f[b[i]][c[j]];
                            o[i][tp].pre=g;
                            o[i][tp].v=c[j];
                            //if(i==2)cout<<c[j]<<" "<<d[i][tp]<<endl;
                        }
                    }
                    if(j==0)
                    {
                        if(d[now2][g]>=inf)continue;
                        //if(i==2)
                        //cout<<g<<"  ()  "<<d[now2][g]<<endl;
                        int tp=g|(1<<j);
                        //cout<<tp<<"  "<<j<<" "<<c[0]<<endl;
                        //cout<<c[j]<<" "<<f[b[i]][c[j]]<<endl;
                        if(d[now2][g]+f[b[i]][c[j]]<d[now][tp])
                        {
                            d[now][tp]=d[now2][g]+f[b[i]][c[j]];
                            //cout<<tp<<" "<<d[now][tp]<<endl;
                            o[i][tp].pre=g;
                            o[i][tp].v=c[j];
                           // if(i==2)
                            //    cout<<c[j]<<"!"<<d[i][tp]<<endl;
                        }
                    }
                }
            }

            for(j=0;j<=M;j++)
            {
                if(i==3&&d[now][j]<10)
                    cout<<j<<"**"<<now<<" "<<d[now][j]<<" "<<o[i][j].v<<endl;
                d[now2][j]=d[now][j];
               // if(i==1&&j==1)cout<<d[now2][j]<<"!!!!!!!!1"<<endl;
                d[now][j]=inf;
            }
            //now^=1;
            //now2^=1;
        }
        //cout<<"*"<<endl;
        int ans0=-1,ans1=1;
        for(i=0;i<=M;i++)
        {
            if(ans0==-1||ans0>d[now2][i])
            {
                ans0=d[now2][i];
                //cout<<now<<"  "<<d[now][i]<<endl;
                ans1=i;
            }
        }
        if(ans0==-1||ans0>=inf){cout<<"****"<<endl; continue;};

        cout<<ans1<<endl;
        for(i=n;i>=1;i--)
        {
            int pre=o[i][ans1].pre;
            ans[i]=ok[b[i]][o[i][ans1].v];
           // cout<<ans[i]<<"--------"<<b[i]<<" "<<o[i][ans1].v<<" "<<ok[1][1]<<endl;
            ans1=pre;
        }
        for(i=1;i<=n;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
