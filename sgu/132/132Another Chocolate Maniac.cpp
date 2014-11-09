#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,temp;
const int inf = 0x3fffffff;
char s[77][11];
int d[2][130][130];
bool judge[130];
int a[8];
int bug[77][130];
void dfs(int index,int fro,int now,int num,int ok)
{
    int i,j;
    if(index==2)cout<<fro<<" ++++ "<<ok<<" "<<now<<" "<<num<<" "<<ok<<endl;
    if(now==n)
    {
        //if(index==4)
           //cout<<fro<<" ++++++ "<<judge[fro]<<endl;
        if(judge[fro]==1)
        {
            //if(index==4)
           // cout<<"@@@@@@@@@@@@@@@@2"<<d[index%2][fro][ok]<<" "<<num+temp<<endl;
            d[index%2][fro][ok]=min(d[index%2][fro][ok],num+temp);
            if(d[index%2][fro][ok]<inf&&num+temp<inf)
            cout<<"G"<<index<<"  "<<fro<<" "<<ok<<" "<<d[index%2][fro][ok]<<endl;
        }
        return;
    }
    //if(index==4)cout<<"FFFFFFFFFFfffff"<<s[index-1][now]<<" "
    //<<s[index-1][now+1]<<endl;
    if(s[index-1][now]=='.'&&now+1<n&&s[index-1][now+1]=='.')
    {
        int tmp = (1<<now);
        tmp |= (1<<(now+1));
        if(index==2)cout<<"*"<<ok<<" "<<tmp<<" "<<(ok|tmp)<<endl;

        if(s[index][now]=='.'&&now+1<n&&s[index][now+1]=='.')
        {
            dfs(index,fro|tmp,now+2,num+2,ok|tmp);
        }
        else  dfs(index,fro|tmp,now+2,num+1,ok);
    }
    if((1<<now)&fro==0&&s[index][now]=='.')
    {
        if(index==1)cout<<((1<<now)&fro)<<endl;
        dfs(index,fro|(1<<now),now+1,num+1,ok|(1<<now));
    }
    if(now<n&&(!(((1<<now)&fro==0)&&s[index][now]=='.')))//
    {
        //if(index==0)
        //cout<<"GG"<<endl;
        dfs(index,fro,now+1,num,ok);
    }

}
void init()
{
    int i,j;
    int b[8];
    for(i=0; i<a[n]; i++)
    {
        for(j=0; j<n; j++)
        {
            if((1<<j)&i)b[j]=1;
            else b[j]=0;
        }
        int f=0;
        for(j=0; j<n; j++)
        {
            if(b[j])f=0;
            else f++;
            if(f>=2)break;
        }
        if(f<2)judge[i]=1;
        else judge[i]=0;
        // cout<<i<<" "<<judge[i]<<endl;
    }
    // cout<<endl;
}
int main()
{
    //freopen("out.txt","w",stdout);
    int i,j,k;
    a[0]=1;
    for(i=1; i<=7; i++)
        a[i] = a[i-1]*2;
    for(i=0;i<7;i++)
      s[0][i]='*';
    scanf("%d%d",&m,&n);
    {
        init();
        for(i=1; i<=m; i++)
            scanf("%s",s[i]);
        int ok =0;
        for(i=0;i<n;i++)
           s[m+1][i]='*';
        for(j=0; j<n; j++)
        {
            if(s[1][j]=='*')ok=ok|(1<<j);
        }
        for(j=0; j<a[n]; j++)
        {
            for(k=0; k<a[n]; k++)
                d[0][j][k]=d[1][j][k]=inf;
        }
        temp=0;
        dfs(1,a[n]-1,0,0,ok);
        for(i=0; i<=m+1; i++)
        {
            for(j=0; j<a[n]; j++)
                bug[i][j]=inf;
        }
        for(i=2; i<=m+1; i++)
        {
            //cout<<i<<"((((((((((("<<endl;
            for(j=0; j<a[n]; j++)
            {
                for(k=0; k<a[n]; k++)
                {
                    bug[i-1][j]=min(bug[i-1][j],d[(i-1+2)%2][k][j]),d[i%2][k][j]=inf;
                }
            }
            ok =0;
            for(j=0; j<n; j++)
            {
                if(s[i][j]=='*')ok=ok|(1<<j);
            }
            //cout<<ok<<endl;
            if(i==m+1)ok=a[n]-1;
            for(j=0; j<a[n]; j++)
            {
                temp = bug[i-1][j];
                if(i==2&&j==1)cout<<temp<<"xiaobawang"<<endl;
                //cout<<i<<" "<<j<<"_+++++++++++_"<<temp<<endl;
                dfs(i,j,0,0,ok);
            }
        }
        int ans=inf;
        for(i=0; i<a[n]; i++)
        {
            if(judge[i])ans = min(ans,d[(m+1)%2][i][a[n]-1]);
        }
        printf("%d\n",ans);
    }
}
