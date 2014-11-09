#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
#define ll __int64
int N,M,Fa,Fc,X,L,R,A,B,C,W,F;
const int maxn = 2097152;
int ch[maxn][2];
int sz;
int a[22],b[22];
int sum[maxn],root[100005];
int TT;
void insert(int m,int v)
{
    int i,j;
    for(i=0; i<20; i++)
        a[i]=0;
    j=19;
    while(m)
    {
        a[j--]=m%2;
        m/=2;
    }
    root[v]=sz;
    int x = sz,y = root[v-1];
    memset(ch[sz],0,sizeof(ch[sz]));
    sum[sz]=sum[y]+1;
    sz++;
    //cout<<y<<"@@@@@@@@@@@@"<<a[0]<<" "<<ch[y][a[0]]<<endl;
    for(i=0; i<20; i++)
    {
        if(ch[x][a[i]]==0)
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            ch[x][a[i]]=sz;
            //cout<<y<<"(("<<sum[y]<<endl;
            sum[ch[x][a[i]]]=sum[ch[y][a[i]]]+1;
            sz++;
        }
        ch[x][a[i]^1]=ch[y][a[i]^1];
        x = ch[x][a[i]];
        y = ch[y][a[i]];
    }
//    for(i=0;i<sz;i++)
//        cout<<i<<" "<<sum[i]<<endl;
}
int query(int pos,int x,int y)
{
    // cout<<x<<" "<<y<<endl;
    int i,j,ss=0;
    int tmp = a[pos];
    int tmp2 = b[pos];
    //cout<<tmp2<<endl;
    if(pos==20)
    {
        return 0;
    }
    if(tmp==1)
    {
        if(y==-1)ss += sum[ch[x][tmp2]];
        //
        else
            ss += sum[ch[x][tmp2]]-sum[ch[y][tmp2]];
       // if(TT)
         // cout<<x<<"@"<<y<<"   "<<ss<<" "<<tmp2<<" "<<ch[x][tmp2]<<"  "<<sum[ch[x][tmp2]]<<
         // "  "<<ch[y][tmp2]<<" "<<sum[ch[y][tmp2]]<<endl;
        if(y==-1)
            ss += query(pos+1,ch[x][tmp2^1],-1);
        else
            ss += query(pos+1,ch[x][tmp2^1],ch[y][tmp2^1]);
    }
    else
    {
        //if(TT&&y!=-1)
        //   cout<<x<<" "<<tmp2<<" "<<ch[x][tmp2]<<"****"<<ch[y][tmp2]<<endl;
        //else if(TT)cout<<x<<" "<<tmp2<<" "<<ch[x][tmp2]<<"(())"<<y<<endl;
        if(y==-1)
            ss += query(pos+1,ch[x][tmp2],-1);
        else
            ss += query(pos+1,ch[x][tmp2],ch[y][tmp2]);
    }
    //cout<<x<<" "<<y<<" "<<ss<<"===="<<endl;
    return ss;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&M);
        W=0;
        sz=1;
        insert(M,0);
        int count=0;




        for(int g=1; g<=N; g++)
        {
            scanf("%d%d%d%d%d%d%d%d",&Fa,&Fc,&X,&L,&R,&A,&B,&C);
            F =  (Fa * W + Fc) % g;
            L++;R++;
            //cout<<F<<"GG"<<Fa<<" "<<W<<" "<<Fc<<" "<<g<<endl;

  //if(g==3)TT=1;
            for(j=0; j<20; j++)
                b[j]=0;
            int xx = X;
            j=19;

            while(xx)
            {
                b[j--]=xx%2;
                xx/=2;
            }

            for(j=0; j<20; j++)
                a[j]=0;
            j = 19;
            int tt = R;
            while(tt)
            {
                a[j--]=tt%2;
                tt/=2;
            }



            if(F==0)
            {
               // cout<<root[g-1]<<"()"<<-1<<endl;
                count = query(0,root[g-1],-1);
            }
            else
            {
               // cout<<root[g-1]<<"()"<<root[F-1]<<endl;
                count = query(0,root[g-1],root[F-1]);
            }


            //cout<<count<<endl;


            if(L-1>=0)
            {
                for(j=0; j<20; j++)
                    a[j]=0;
                j = 19;
                tt = L-1;
                while(tt)
                {
                    a[j--]=tt%2;
                    tt/=2;
                }
                if(F==0)
                    count -= query(0,root[g-1],-1);
                else
                    count -= query(0,root[g-1],root[F-1]);
            }
            printf("%d\n",count);
            //if(TT)
//            for(j=0;j<sz;j++)
//                cout<<j<<"@"<<sum[j]<<endl;
            W = count;
           // cout<<W<<"*"<<"   "<<(A*count+B)%C<<endl;
            insert(((ll)A * count + B) % C,g);
        }
    }
}
