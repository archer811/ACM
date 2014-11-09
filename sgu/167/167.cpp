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
int a[16][16];
int  d[16][260][16][16][2][2];
int b[16][16];
int k,n,m;
char pnum[16][260][16][16][2][2],pl[16][260][16][16][2][2];
char pr[16][260][16][16][2][2],px[16][260][16][16][2][2],py[16][260][16][16][2][2];
void func(int a,int b2,int c,int dd,int e,int f,int a2,int b3,int c2,int d2,int e2,int f2,int mark)
{
    if(mark==0)
    {
        if(d[a][b2][c][dd][e][f]<b[a][dd]-b[a][c-1])
        {
            d[a][b2][c][dd][e][f]=b[a][dd]-b[a][c-1];
            pnum[a][b2][c][dd][e][f]=b3;
            pl[a][b2][c][dd][e][f]=c2;
            pr[a][b2][c][dd][e][f]=d2;
            px[a][b2][c][dd][e][f]=e2;
            py[a][b2][c][dd][e][f]=f2;
        }
    }
    else if(d[a][b2][c][dd][e][f]<d[a2][b3][c2][d2][e2][f2]+b[a][dd]-b[a][c-1])
    {
        pnum[a][b2][c][dd][e][f]=b3;
        pl[a][b2][c][dd][e][f]=c2;
        pr[a][b2][c][dd][e][f]=d2;
        px[a][b2][c][dd][e][f]=e2;
        py[a][b2][c][dd][e][f]=f2;
        d[a][b2][c][dd][e][f]=d[a2][b3][c2][d2][e2][f2]+b[a][dd]-b[a][c-1];
    }
}
void print(int id,int num,int l,int r,int x,int y)
{
    if(id<=0 || num==0)return;

    print(id-1,pnum[id][num][l][r][x][y],pl[id][num][l][r][x][y],
          pr[id][num][l][r][x][y],px[id][num][l][r][x][y],py[id][num][l][r][x][y]);
    for(int i=l; i<=r; i++)
    {
        printf("%d %d\n",id,i);
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(d,0,sizeof(d));
        for(i=1; i<=n; i++)
        {
            b[i][0]=0;
            for(j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=b[i][j-1]+a[i][j];
            }
        }
        for(int tp=1; tp<=n; tp++)
        {
            for(int t=0; t<=k; t++)
            {
                for(i=1; i<=m; i++)
                {
                    for(j=i; j<=m; j++)
                    {
                        if(t+j-i+1>k)continue;
                        if(t>(tp-1)*m)continue;
                        //if(j-i+1<=k)
                        {
                            func(tp,j-i+1,i,j,0,0,tp,0,i,j,0,0,0);
                            func(tp,j-i+1,i,j,0,1,tp,0,i,j,0,1,0);
                            func(tp,j-i+1,i,j,1,0,tp,0,i,j,1,0,0);
                            func(tp,j-i+1,i,j,1,1,tp,0,i,j,1,1,0);

                            int x,y;


                            x=0;
                            y=0;
                            for(int l=i; l<=j; l++)
                            {
                                for(int r=l; r<=j; r++)
                                {

                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,0,0,1);
                                }
                            }

                            x=1;
                            y=0;
                            for(int l=1;l<=i;l++)
                            {
                                for(int r=i;r<=j;r++)
                                {
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,0,0,1);
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,1,0,1);
                                }
                            }

                            x=0;
                            y=1;
                            for(int l=i;l<=j;l++)
                            {
                                for(int r=j;r<=m;r++)
                                {
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,0,0,1);
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,0,1,1);
                                }
                            }

                            x=1;
                            y=1;
                            for(int l=1; l<=i; l++)
                            {
                                for(int r=j; r<=m; r++)
                                {
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,0,0,1);
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,0,1,1);
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,1,0,1);
                                    func(tp,t+j-i+1,i,j,x,y,
                                         tp-1,t,l,r,1,1,1);
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans=0;
        int ansid=-1,ansnum,ansl,ansr,ansx,ansy;
        for(i=1; i<=n; i++)
        {
            for(int l=1; l<=m; l++)
            {
                for(int r=l; r<=m; r++)
                {
                    for(int x=0; x<2; x++)
                    {
                        for(int y=0; y<2; y++)
                        {
                            if(d[i][k][l][r][x][y]>ans)
                            {
                                ans=d[i][k][l][r][x][y];
                                ansid=i;
                                ansnum=k;
                                ansl=l;
                                ansr=r;
                                ansx=x;
                                ansy=y;
                            }

                        }
                    }
                }
            }
        }
        printf("Oil : %d\n",ans);
       // cout<<ansid<<endl;
        print(ansid,ansnum,ansl,ansr,ansx,ansy);

    }
    return 0;
}

