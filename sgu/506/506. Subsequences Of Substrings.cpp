#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005][30];
char s[100005],t[105];
int vis[30];
int getans[100005];
#define ll __int64
struct array
{
    __int64 x,y;
}hh[100005];
int ha;
ll Min(ll x,ll y)
{
    if(x<y)return x;
    return y;
}
int main()
{
    int i,j,k,d,g;
    while(scanf("%s",s)!=EOF)
    {
        scanf("%s",t);
        memset(a,-1,sizeof(a));
        for(i=0;i<30;i++)
            vis[i]=0;
        int len = strlen(s);
        int lent = strlen(t);
        for(i=0;i<len;i++)
        {
            k = s[i]-'a';
            a[vis[k]][k]=i;
            vis[k]=i;
        }
        for(i=0;i<len;i++)
        {
            for(j=0;j<30;j++)
            {
                if(a[i][j]==-1&&i!=0)
                {
                    a[i][j]=a[i-1][j];
                    if(i>=a[i][j])a[i][j]=-1;
                }
                if(i>=a[i][j])a[i][j]=-1;
            }
        }
//        for(i=0;i<len;i++)
//        {
//            for(j=0;j<26;j++)
//                cout<<a[i][j]<<" ";
//            cout<<endl;
//        }
        k = 0;
        if(s[0]==t[0])getans[k++]=0;
        g = 0;d = t[0]-'a';
        while(a[g][d]!=-1)
        {
//            cout<<a[g][d]<<"===="<<endl;
            getans[k++]=a[g][d];g=a[g][d];
            //if(g==a[g][d])break;
        }
//        for(i=0;i<k;i++)
//        {
//            cout<<getans[i]<<"()"<<endl;
//        }
        ha =0;
        for(i=0;i<k;i++)
        {
            d = getans[i];
            //0cout<<d<<"^^"<<endl;
            for(j=1;j<lent;j++)
            {
                d = a[d][t[j]-'a'];
                if(d==-1)break;
            }
            if(j==lent)
            hh[ha].x=(ll)getans[i],hh[ha++].y=(ll)(len-d-1);
//            cout<<getans[i]<<" "<<len-d-1<<endl;
        }
        ll sum=0;
        for(i=0;i<ha;i++)
        {
           // cout<<hh[i].x<<" "<<hh[i].y<<endl;
            if(i==0)sum+=(hh[i].x+1)*(hh[i].y+1);
            else
            {
                sum += (hh[i].x+1)*(hh[i].y+1);
                  //cout<<sum<<"$$$"<<endl;
                ll x=  Min(hh[i].x,hh[i-1].x);
                ll y=  Min(hh[i].y,hh[i-1].y);
                //cout<<x<<"%%%"<<y<<endl;
                sum -= (x+1)*(y+1);
            }
            //cout<<sum<<"**"<<endl;
        }
        printf("%I64d\n",sum);
    }
}
