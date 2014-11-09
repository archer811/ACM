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
int n,l;
struct array
{
    int x,y;
    int flag;
    int anstime;
} s[22];
int g[22],num;
int mark[22];
int main()
{
    int i,j,d;
    char t[2];
    while(scanf("%d%d",&n,&l)!=EOF)
    {
        if(n==0&&l==0)break;
        num=0;
        for(i=1; i<=n; i++)
        {
            scanf("%s%d",t,&d);
            if(t[0]=='L')
                s[i].x=-1;
            else
                s[i].x=1;
            s[i].y=d;
            s[i].flag=0;
            g[num++]=i;
            s[i].anstime=0;
        }
//        for(i=0;i<num;i++)
//            cout<<g[i]<<"()"<<endl;
        while(1)
        {
            int a=-1,b=-1;
            double tmp=l+1;
            for(int _i=0; _i<num; _i++)
            {
                for(int _j=_i+1; _j<num; _j++)
                {
                    i = g[_i];
                    j = g[_j];
                    if(s[i].y<s[j].y&&s[i].x==1&&s[j].x==-1)
                    {
                        int gg = (s[j].y-s[i].y)/2;
                        if((s[j].y-s[i].y)%2==0)
                        {
                            if(s[j].y-s[i].y<tmp)
                            {
                                tmp=s[j].y-s[i].y;
                                a=i;
                                b=j;
                            }
                        }
                    }

                    if(s[i].y>s[j].y&&s[i].x==-1&&s[j].x==1)
                    {
                        int gg = (s[i].y-s[j].y)/2;
                        if((s[i].y-s[j].y)%2==0)
                        {
                            if(s[i].y-s[j].y<tmp)
                            {
                                tmp=s[i].y-s[j].y;
                                a=j;
                                b=i;
                            }
                        }
                    }
                }
            }


//            cout<<a<<"*"<<b<<endl;
            if(a!=-1)
            {

                for(i=1; i<=n; i++)
                    mark[i]=0;

                for(int _i=0; _i<num; _i++)
                {
                    for(int _j=_i+1; _j<num; _j++)
                    {
                        i = g[_i];
                        j = g[_j];
                        if(s[i].y<s[j].y&&s[i].x==1&&s[j].x==-1)
                        {
                            int gg = (s[j].y-s[i].y)/2;
                            if((s[j].y-s[i].y)%2==0)
                            {
                                if(s[j].y-s[i].y==tmp)
                                {
                                    mark[i]=1;
                                    mark[j]=1;
                                }
                            }
                        }

                        if(s[i].y>s[j].y&&s[i].x==-1&&s[j].x==1)
                        {
                            int gg = (s[i].y-s[j].y)/2;
                            if((s[i].y-s[j].y)%2==0)
                            {
                                if(s[i].y-s[j].y==tmp)
                                {
                                    mark[i]=1;
                                    mark[j]=1;
                                }
                            }
                        }
                    }
                }

                int tim = (s[b].y-s[a].y)/2;

                for(i=0; i<num; i++)
                {
                    int t1=0;
                    if(s[g[i]].x==-1)
                    {
                        t1 = s[g[i]].y;
                    }
                    else
                        t1 = (l-s[g[i]].y);
                    if(t1<tim)
                    {
                        s[g[i]].anstime+=t1;
                        s[g[i]].flag=1;
                        continue;
                    }
                    else
                    {
                        s[g[i]].anstime+=tim;
                        s[g[i]].y+=s[g[i]].x*tim;
                        if(s[g[i]].y<=0||s[g[i]].y>=l+1)
                        {
                            s[g[i]].flag=1;
                            continue;
                        }
                    }
                    if(mark[g[i]])
                        s[g[i]].x=-s[g[i]].x;
                }
            }
            else
            {
                for(i=0; i<num; i++)
                {
                    int t1=0;
                    if(s[g[i]].x==-1)
                    {
                        t1 = s[g[i]].y*1.0;
                    }
                    else
                        t1 = (l-s[g[i]].y);
                    s[g[i]].anstime += t1;
                    s[g[i]].flag=1;
                }
            }
//            for(i=1;i<=n;i++)
//            {
//                cout<<i<<"++"<<s[i].x<<" "<<s[i].y<<"  "<<s[i].flag<<
//                " = "<<s[i].anstime<<endl;
//            }

            int _num=num;
            num=0;
            for(i=0; i<_num; i++)
            {
                if(s[g[i]].flag)continue;
                else
                    g[num++]=g[i];
            }
            if(num==0)break;
        }
        int ans=0;
        int anstime =-1;
        for(i=1; i<=n; i++)
        {
            if(anstime<s[i].anstime)
            {
                anstime=s[i].anstime;
                ans=i;
            }
            else if(anstime==s[i].anstime)
            {
                if(s[i].x==-1)
                    ans=i;
            }
            //cout<<s[i].anstime<<endl;
        }
        printf("%d %d\n",anstime,ans);
    }
}
