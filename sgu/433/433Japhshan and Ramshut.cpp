#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int w[6];
int n,m,k;
bool flag;
int ans[6],ant[6];
int vis[5][21][21][2];
int v[21][21];
void dfs(int num,int sum)
{
    if(flag)return;
    if(num==k)
    {
        if(sum==n*m)
        {
            for(int i=0; i<k; i++)
                ant[i]=ans[i];
            flag=true;
        }
        return;
    }
    int tmp = (n*m-sum)/w[num],i;
    for(i=tmp;i>=0;i--)
    {
        ans[num]=i;
        dfs(num+1,sum+i*w[num]);
    }
}
int ff=0;
char ok[21][21];
int judge[27];
int go[][2]= {-1,0,1,0,0,1,0,-1};
void Dfs(int sn,int sm,int now,int num)
{
    if(flag)return;
    if(ant[now]==num)
    {
        if(now==k-1)
        {
            int gg=0;
            cout<<"F"<<endl;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                    ok[i][j]=' ';
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(ok[i][j]==' ')
                    {
                        //cout<<i<<"GG"<<j<<endl;
                        int fff=v[i][j];
                        if(j+1<m&&v[i][j+1]==fff)
                        {
                            for(int t=0; t<26; t++)
                                judge[t]=0;
                            for(int t=j; v[i][t]==fff; t++)
                            {
                                for(int fuck=0; fuck<4; fuck++)
                                {
                                    int f1=i+go[fuck][0];
                                    int f2=t+go[fuck][1];
//                                    cout<<i<<" "<<j<<
//                                    " "<<i<<" "<<t<<" "
//                                    <<f1<<" "<<f2<<" "<<ok[f1][f2]<<endl;

                                    if(f1<n&&f1>=0&&f2>=0&&f2<m&&ok[f1][f2]!=' ')
                                    {
                                        judge[ok[f1][f2]-'a']=1;
                                    }
                                }
                            }
                            for(int t=0; t<26; t++)
                            {
                                //cout<<i<<" "<<j<<" "<<judge[t]<<endl;
                                if(judge[t]==0)
                                {
                                    gg=t;
                                    break;
                                }
                            }
                            for(int t=j; v[i][t]==fff; t++)
                                ok[i][t]=gg+'a';
                        }
                        else if(i+1<n&&v[i+1][j]==fff)
                        {
                            for(int t=0; t<26; t++)
                                judge[t]=0;
                            for(int t=i; v[t][j]==fff; t++)
                            {
                                for(int fuck=0; fuck<4; fuck++)
                                {
                                    int f1=t+go[fuck][0];
                                    int f2=j+go[fuck][1];
                                    if(f1<n&&f1>=0&&f2>=0&&f2<m&&ok[f1][f2]!=' ')
                                    {
                                        judge[ok[f1][f2]-'a']=1;
                                    }
                                }
                            }
                            for(int t=0; t<26; t++)
                            {
                                //if(i==0&&j==0)cout<<t<<"FFF"<<judge[t]<<endl;
                                if(judge[t]==0)
                                {
                                    gg=t;
                                    break;
                                }
                            }
                            for(int t=i; v[t][j]==fff; t++)
                                ok[t][j]=gg+'a';
                        }
                        else
                        {
                            for(int t=0; t<26; t++)
                                judge[t]=0;
                            for(int fuck=0; fuck<4; fuck++)
                            {
                                int f1=i+go[fuck][0];
                                int f2=j+go[fuck][1];
                                if(f1<n&&f1>=0&&f2>=0&&f2<m&&ok[f1][f2]!=' ')
                                {
                                    judge[ok[f1][f2]-'a']=1;
                                }
                            }
                            for(int t=0; t<26; t++)
                            {
                                if(judge[t]==0)
                                {
                                    gg=t;
                                    break;
                                }
                            }
                            ok[i][j]=gg+'a';
                        }
                    }
                }
                //printf("\n");
            }
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                    printf("%c",ok[i][j]);
                printf("\n");
            }
            flag=true;
            return;
        }
        Dfs(0,0,now+1,0);
    }
    cout<<sn<<" "<<sm<<" "<<now<<" "<<num<<endl;
    int i,j;
    int ti = sn,tj = sm;
    while()
    for(i=sn; i<n; i++)
    {
        if(flag)return;
        for(j=sm; j<m; j++)
        {
            int t;
            //cout<<i<<" "<<j<<endl;
           // if(v[i][j]!=-1)continue;
            //if(vis[now][i][j][0]==0)
            {
                for(t=0; t<w[now]&&j+t<m; t++)
                {
                    if(v[i][j+t]!=-1)break;
                }
                //if(i==0&&j==0)cout<<t<<"+++++++++++++++++++++++++++++"<<now<<" "<<w[now]<<endl;
                if(t==w[now])
                {
                    for(t=0; t<w[now]; t++)
                        v[i][j+t]=ff;
                    ff++;
                    vis[now][i][j][0]=1;
                    int ti=i,tj=j+w[now];
                    if(tj==m)ti=i+1,tj=0;
                    if(ti==n)return;
                    i=i;j=j;
                    //cout<<ti<<"+"<<tj<<endl;
//                    for(int ii=0; ii<n; ii++)
//                    {
//                        for(int ji=0; ji<m; ji++)
//                            cout<<v[ii][ji]<<" ";
//                        cout<<endl;
//                    }
//cout<<"Hen"<<endl;
                    Dfs(ti,tj,now,num+1);
                    for(t=0; t<w[now]; t++)
                        v[i][j+t]=-1;
                }
            }
            //if(vis[now][i][j][1]==0)
            {
                for(t=0; t<w[now]&&i+t<n; t++)
                {
                    if(v[i+t][j]!=-1)break;
                }
                if(t==w[now])
                {
                    for(t=0; t<w[now]; t++)
                        v[i+t][j]=ff;
                    ff++;
                    vis[now][i][j][1]=1;
                    int ti=i,tj=j+1;
                    if(tj>=m)ti=i+1,tj=0;
                    if(ti==n)return;
                    //cout<<"shu"<<endl;
                    //cout<<ti<<"+"<<tj<<endl;
                    Dfs(ti,tj,now,num+1);
                    for(t=0; t<w[now]; t++)
                        v[i+t][j]=-1;
                }
            }
        }
    }
}
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(i=0; i<k; i++)
    {
        scanf("%d",&w[i]);
    }
    j=0;
    for(i=0; i<k; i++)
    {
        if(w[i]>n&&w[i]>m)
            continue;
        w[j++]=w[i];
    }
    k=j;
    sort(w,w+k);
    flag = false;
    dfs(0,0);
    if(flag==false)printf("NO\n");
    else
    {
        printf("YES\n");
        memset(vis,0,sizeof(vis));
        memset(v,-1,sizeof(v));
        ff=0;
//        for(i=0;i<k;i++)
//            cout<<ant[i]<<endl;
        flag = false;
        Dfs(0,0,0,0);
    }
}
/*
5 5 2
3 4

6 14 5
9
10
3
8
10
*/
