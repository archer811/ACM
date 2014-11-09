#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#include<bitset>
#include<ctime>

using namespace std;

#pragma comment(linker, "/STACK:1024000000,1024000000")
#define PB push_back
#define MP make_pair

const double pi=acos(-1.0),eps=1e-8;
const int maxn=1100,maxm=1100000,inf=0x3f3f3f3f;
#define ll long long
struct node
{
    int x,y;
    friend bool operator < (node a, node b)
    {
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
}save[2506*2506];
//const ll linf=1122334455667788990;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int ok[2506][2506],sum[2506*2];
int main()
{
    int a,b,c,d;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d))
    {
        int all=0;
        int girl=c,boy=b;
        int GCD=gcd(b,c);
        int fg=c/GCD,fb=b/GCD;
        while(girl<a+1||boy<d+1)
        {
            girl+=fg,boy+=fb;
        }
        printf("%d %d\n",girl,boy);
        memset(ok,0,sizeof(ok));
        memset(sum,0,sizeof(sum));
        int pos1=0,pos2=girl;
        int ans=0;
        while(ans<girl*b)
        {
            while(1){
            pos1++;
            if(pos1>=girl+1) pos1=1;
            while(sum[pos1]>=b)
            {
                pos1++;
                if(pos1>=girl+1) pos1=1;
            }
            pos2++;
            if(pos2>=boy+girl+1) pos2=1+girl;
            while(sum[pos2]>=c)
            {
                pos2++;
                if(pos2>=girl+boy+1) pos2=1+girl;
            }
            if(!ok[pos1][pos2])break;
            }
            save[++all].x=min(pos1,pos2);
            save[all].y=max(pos1,pos2);
            sum[pos1]++;sum[pos2]++;
            ok[pos1][pos2]=ok[pos2][pos1]=1;
            ans++;
        }
//        for(int i=1+girl;i<=girl+boy;i++)
//        {
//            for(int j=1;j<=c;j++)
//            {
//                pos++;
//                if(pos>=girl+1)
//                {
//                    pos=1;
//                }
//                //printf("%d %d\n",i,pos);
//                save[++all].x=min(i,pos);
//                save[all].y=max(i,pos);
//            }
//        }
        memset(ok,0,sizeof(ok));
        memset(sum,0,sizeof(sum));
        int pos=0;
        for(int i=1;i<=girl;i++)
        {
            ok[i][i]=1;
            while(sum[i]<a)
            {
                pos++;
                if(pos>girl) pos=1;
                if(ok[pos][i]) continue;
                if(sum[pos]>=a) continue;
                //printf("%d %d\n",i,pos);
                save[++all].x=min(i,pos);
                save[all].y=max(i,pos);
                sum[i]++;sum[pos]++;
                ok[i][pos]=ok[pos][i]=1;
            }
        }

        memset(ok,0,sizeof(ok));
        memset(sum,0,sizeof(sum));
        pos=girl;
        for(int i=girl+1;i<=girl+boy;i++)
        {
            ok[i][i]=1;
            while(sum[i]<d)
            {
                pos++;
                if(pos>=girl+1+boy) pos=1+girl;
                if(ok[pos][i]) continue;
                if(sum[pos]>=d) continue;
                //printf("%d %d\n",i,pos);
                save[++all].x=min(i,pos);
                save[all].y=max(i,pos);
                sum[i]++;sum[pos]++;
                ok[i][pos]=ok[pos][i]=1;
            }
        }
        sort(save+1,save+1+all);
        for(int i=1;i<=all;i++)
            printf("%d %d\n",save[i].x,save[i].y);





//        memset(ok,0,sizeof(ok));
//        memset(sum,0,sizeof(sum));
//        pos=0;
//        for(int i=1;i<=girl;i++)
//        {
//            ok[i][i]=1;
//            for(int j=1;j<=a-sum[i];j++)
//            {
//                pos++;
//                if(pos>=girl+1)pos=1;
//                while(ok[i][pos])
//                {
//                    pos++;
//                    if(pos>=girl+1)pos=1;
//                }
//                ok[i][pos]=ok[pos][i]=1;
//                sum[pos]++;
//                printf("%d %d\n",i,pos);
//            }
//
////            for(int j=1;j<=girl;j++)
////            {
////                if(sum[i]==a) break;
////                if(sum[j]==a) continue;
////                if(i==j) continue;
////                if(ok[i][j]||ok[j][i]) continue;
////                printf("%d %d\n",i,j);
////                sum[i]++;sum[j]++;
////                ok[i][j]=ok[j][i]=1;
////            }
//        }
////        memset(ok,0,sizeof(ok));
////        memset(sum,0,sizeof(sum));
//        pos=girl;
//        for(int i=1+girl;i<=boy+girl;i++)
//        {
//            ok[i][i]=1;
//            for(int j=1;j<=d-sum[i];j++)
//            {
//                pos++;
//                if(pos>=girl+1+boy)pos=1+girl;
//                while(ok[i][pos])
//                {
//                    pos++;
//                    if(sum[pos]>=)
//                    if(pos>=girl+1+boy)pos=1+girl;
//                }
//                ok[i][pos]=ok[pos][i]=1;
//                sum[pos]++;
//                printf("%d %d\n",i,pos);
//            }
//        }
    }

    return 0;
}
