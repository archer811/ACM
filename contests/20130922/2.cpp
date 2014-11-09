#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int inf = 0x3fffffff;
int a[100005],b[100005],n,s[100005],g1[100005],g2[100005];
struct array
{
    int x,y;
} ans[100005];
int M;
int ok[100005];
int main()
{
    int i,j,k,q;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==-1)a[i]=-inf;
            s[i]=-inf;
            g1[i]=g2[i]=-inf;
            ans[i].x=i;
            ans[i].y=-inf;
        }
        for(i=1; i<=n; i++)
            scanf("%d",&b[i]);
        if(n>=3)s[3]=b[2]-b[1],a[3]=s[3],ans[3].y=a[3];
        for(i=6; i<=n; i+=3)
        {
            s[i] = b[i-1]-(b[i-2]-s[i-3]);
            a[i] = s[i];
            ans[i].y=a[i];
        }
        if(n-2>=1)s[n-2]=b[n-1]-b[n],a[n-2]=s[n-2],ans[n-2].y=a[n-2];
        for(i=n-5; i>=1; i-=3)
            s[i]=b[i-1]-(b[i+2]-s[i+3]),a[i]=s[i],ans[i].y=a[i];
        int m = n/3*3;
        j=1;
        for(i=1; i<=m; i+=3)
        {
            g1[j++]=i;
            g2[j-1]=b[i+1]-s[i+2];
            g1[j++]=i+1;
            g2[j-1]=b[i+2]-s[i+2];
        }
        if(n-m==1)
        {
            g1[j++]=n;
            g2[j-1]=b[n]-s[n-1];
        }
        else if(n-m==2)
        {
            g1[j++]=n-1;
            g2[j-1]=b[n-1]-s[n-2];
            g1[j++]=n;
            g2[j-1]=-1;
        }
//        for(i=1;i<=n;i++)
//            cout<<a[i]<<endl;
        M = j;
        for(i=1;i<=n;i++)
            cout<<i<<"%%%"<<ans[i].y<<" "<<endl;
        int flag=0;
        for(i=1; i<j; i++)
        {
            //cout<<g1[i]<<" "<<ans[g1[i]].y<<endl;
            if(ans[g1[i]].y!=-inf)
            {
                flag=1;
                k=i;
                break;
            }
        }
        cout<<flag<<"*"<<endl;
        if(flag)
        {
            for(i=k+1; i<M; i++)
            {
                ans[g1[i]].y=g2[i-1]-ans[g1[i-1]].y;
            }
            for(i=k-1; i>=1; i--)
                ans[g1[i]].y=g2[i]-ans[g1[i+1]].y;
        }
        for(i=1;i<=n;i++)
            cout<<i<<"$"<<ans[i].y<<endl;
        int tmp = 0;
        ok[1]=0;
        int Min = inf,Max = 0;
        for(i=1;i<M;i++)
            cout<<"#"<<i<<" "<<ans[i].y<<endl;
        for(i=2;i<M;i++)
        {
            tmp = -tmp+g2[i-1];
            ok[i]=tmp;
            if(i%2==0)
            {
                if(Min>tmp)Min=tmp;
            }
            else
            {
                if(Max<tmp)Max=tmp;
            }
            //cout<<i<<"%"<<ok[i]<<endl;

        }
        scanf("%d",&q);
        //cout<<f(1,2)<<endl;
        //cout<<Max<<"$$%"<<Min<<endl;
        while(q--)
        {
            scanf("%d",&k);
            k++;
            //cout<<<<" "<<-inf<<endl;
            if(ans[k].y!=-inf)printf("%d\n",ans[k].y);
            else
            {
                k = k-k/3;
                if(k%2)
                {
                    printf("%d\n",ok[k]+Min);
                }
                else
                {
                    //cout<<k<<" "<<ok[k]<<"^^^^^^^^^^^^^^^^^^^^^^^"<<Min<<endl;
                    printf("%d\n",ok[k]-Max);
                }
            }
        }
    }
}
