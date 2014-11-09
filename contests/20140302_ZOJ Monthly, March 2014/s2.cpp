#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int pt[3];
int a[1010];
int b[1010];
int c[1010];
bool f[101000];
int n,m,k,x,y,z,p,q;
int x1,x2,x3,y1,y2,y3;
int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        memset(f,false,sizeof f);
        memset(pt,0,sizeof pt);
        int tgt=20200;
        for (int i=1; i<=n; i++)
        scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        tgt=a[1];
        int tgtnum=1;
        int side=0;
        int ad=side;
        int sum;
        for (int i=1; i<=m; i++)
        {
            f[0]=false;
            scanf("%d",&p);
            int minn=0;
            int minb=0;
            for (int i=1; i<=p; i++) scanf("%d",&b[i]),minn=max(minn,b[i]);
            if (p==1 && b[1]==tgt)
            {
                scanf("%d",&q);
                sum=0;
                minb=0;
                for (int i=1; i<=q; i++)
                {
                    scanf("%d",&c[i]),minb=max(minb,c[i]),sum+=c[i];
                    f[c[i]]=true;
                }
                if (f[0])
                {
                    pt[side^1]+=minn;
                    pt[side^1]+=sum;
                    side^=1;
                }
                else
                {
                    if (f[tgt]) pt[side]+=sum;
                    else pt[side^1]+=sum,side^=1;
                }
            }
            else
            {
                scanf("%d",&q);
                minb=0;
                sum=0;
                for (int i=1; i<=q; i++)
                scanf("%d",&c[i]),minb=max(minb,c[i]),sum+=c[i],f[c[i]]=true;

                if (p==0) pt[side^1]+=tgt;
                else if (!f[0]) pt[side^1]+=minn;

                if (f[0] && p>0) pt[side^1]+=minn;

                pt[side^1]+=sum;
                side^=1;
            }

            while(f[a[tgtnum]] && tgtnum<=n) tgtnum++;
            if (tgtnum>n) break;
            tgt=a[tgtnum];
        }
        cout<<pt[0]<<" : "<<pt[1]<<endl;
    }
    return 0;
}
