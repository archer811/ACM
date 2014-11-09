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
//const ll linf=1122334455667788990;
int a[100];
char s[1000];
struct array
{
    double ans;
    int index;
}g[1000];
int cmp(array x,array y)
{
    if(x.ans==y.ans)return x.index<y.index;
    return x.ans>y.ans;
}
char name[1000][105];
int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
            scanf("%s",name[i]);
        int o=0;
        double sum=0;
        for(i=0;i<m;i++)
        {
            scanf("%s",s);
            int f=0;
            for(j=0;j<n;j++)
            {
                if(s[j]=='X')f++;
            }
            if(f!=1){o=1;sum++;continue;}
            for(j=0;j<n;j++)
            {
                if(s[j]=='X')a[j]++;
            }
        }
//        for(i=0;i<n;i++)
//        {
//            cout<<i<<" "<<a[i]<<endl;
//        }
        for(i=0;i<n;i++)
        {
            g[i].ans= a[i]*1.0/m;

            g[i].index=i;
            //cout<<i<<" "<<a[i]<<" "<<n<<" "<<g[i].ans<<endl;
        }
        //for(int i=0;i<n;i++) cout<<g[i].ans<<"\n";
        sort(g,g+n,cmp);
        for(i=0;i<n;i++)
        {
            //int key=g[i].ans*10000;


            printf("%s %.2f",name[g[i].index],(g[i].ans)*100.0);
            //cout<<g[i].ans*100<<endl;
            printf("%%\n");
            //printf("%.10f\n",g[i].ans*100);
            //sum-=g[i].ans;
        }
        //cout<<sum<<"\n";
        sum = sum/m*100;

        printf("Invalid %.2f%%\n",sum);
    }

    return 0;
}
