#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;

int q[3000000],dis[300002],l,b0[300001],b1[600006],b2[600006],b3[600006],d[100000],vv[100000];
 bool v[300000];




void build (int xx,int yy,int zz)
{
    l++;
    b1[l]=b0[xx];
    b0[xx]=l;
    b2[l]=yy;
    b3[l]=zz;
}

int main()
{
    int t,n,m,c,x,y,z,h,w;
    scanf("%d",&t);
    for (int k=1;k<=t;k++){
        scanf("%d%d%d",&n,&m,&c);
        memset(dis,122,sizeof(dis));
        memset(vv,0,sizeof(vv));
        memset(v,0,sizeof(v));
        memset(b0,0,sizeof(b0));
        memset(b1,0,sizeof(b1));

        l=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&x);
            vv[x]++;d[x]=i;
            build(i,n+x,0);//
            build(n+n+x,i,0);//
        }
        for (int i=1;i<n;i++){
            if ((vv[i]!=0)and(vv[i+1]!=0)) {
                if ((vv[i]==1)and(vv[i+1]==1)) {
                    build(d[i],d[i+1],c);
                    build(d[i+1],d[i],c);
                } else if (vv[i]==1) {
                    build(d[i],n+n+i+1,c);
                    build(n+i+1,d[i],c);
                } else if (vv[i+1]==1) {
                    build(n+i,d[i+1],c);
                    build(d[i+1],n+n+i,c);
                } else {
                    build(n+i,n+n+i+1,c);
                    build(n+i+1,n+n+i,c);
                }
            }
        }
        for (int i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&z);
            build(x,y,z);
            build(y,x,z);
        }
        q[1]=1;v[1]=true;dis[1]=0;
        h=0;w=1;
        while (h!=w){
            h++;x=q[h];v[x]=false;
            int i=b0[x];
            while(i!=0){
                if (dis[x]+b3[i]<dis[b2[i]]){
                    dis[b2[i]]=dis[x]+b3[i];
                    if (v[b2[i]]==false) {
                        v[b2[i]]=true;
                        w++;
                        q[w]=b2[i];
                    }
                }
                i=b1[i];
            }
        }
        if (dis[n]==dis[0]) printf("Case #%d: -1\n",k); else printf("Case #%d: %d\n",k,dis[n]);

    }
    return 0;
}
