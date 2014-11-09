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
int n,m,k;
int a[10005];
int vis[10005];
int hit[10005],poc[10005];
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int p,q;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(i=0;i<=10000;i++)
            vis[i]=0;
        int haha[2]={0};
        int f=0;
        while(m--)
        {
           int tmp=0,now=-1;
           for(i=1;i<=n;i++)
           {
               if(vis[a[i]]==0)
               {
                   now=a[i];break;
               }
           }
           if(now==-1)break;
//           cout<<now<<endl;
           int pen=0;
           int cpok=0;
           int havehit_tar=0;
           int largest=0;
           int havepoc_tar=0;
           int sum=0;
           scanf("%d",&p);
           for(i=0;i<p;i++)
           {
               scanf("%d",&hit[i]);
               if(hit[i]==now)
                  havehit_tar=1;
               if(hit[i]>largest)
                  largest=hit[i];
           }

           scanf("%d",&q);

           for(i=0;i<q;i++)
           {
               scanf("%d",&poc[i]);
               if(poc[i]==0)
                cpok=1;
               if(poc[i]==now)
                havepoc_tar=1;
               sum += poc[i];
               if(poc[i]!=0)
               vis[poc[i]]=1;
           }

           int flag=0;
           if(p==0)
           {
               flag=1;
               pen=now;
           }
           if(cpok==0)
           {
// cout<<havehit_tar<<"@@"<<endl;
               if(p>=1&&(havehit_tar==0||p>1))
               {
                   flag=1;pen=largest;
               }
           }
           if(cpok)
           {
               if(p)
               {
                   flag=1;pen=largest;
               }
           }

           if(flag||havepoc_tar==0)
           {
               flag=1;
               pen+=sum;
           }

           if(flag)
           {
               haha[f^1]+=pen;
               f^=1;
           }
           else
           {
               haha[f]+=sum;
           }
        }
        printf("%d : %d\n",haha[0],haha[1]);
    }
}
