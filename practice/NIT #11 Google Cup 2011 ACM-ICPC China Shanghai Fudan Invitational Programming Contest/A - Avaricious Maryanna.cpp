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

int n;
int a[555];
vector<string>ans[505];
void dfs(int pos,int *s)
{
    int i,j;
    if(pos==n)
    {
//        printf(" ");
//        for(i=n-1;i>=0;i--)
//            printf("%d",a[i]);
        string tmp="";
        for(i=n-1;i>=0;i--)
        {
            tmp+=(char)(a[i]+'0');
        }
        //cout<<n<<" "<<tmp<<endl;
        ans[n].push_back(tmp);
        return;
    }
    int c[505];
    for(i=0;i<=9;i++)
    {
        if(pos==n-1&&i==0)continue;
        if(pos==0&&(i!=0&&i!=5&&i!=6))continue;
        int g = a[0]*i*2+s[pos];
        if(pos==0)g-=a[0]*i;
        if(pos==0||(pos>0&&g%10==i))
        {
            int M = min(n,500);
            for(j=0;j<=M;j++)
                c[j]=s[j];
            a[pos]=i;
            int k=0;
            for(j=pos;j<=n;j++)
            {
                int tmp = a[k]*i+c[j];
                if(pos>0&&k<=pos-1)tmp+=a[k]*i;
                c[j]=tmp%10;
                c[j+1]+=tmp/10;
                k++;
            }
            dfs(pos+1,c);
            a[pos]=0;
        }
    }
}
int b[555];
int main()
{
    int i,j,t;
    for(i=1;i<=500;i++)
        ans[i].clear();
    memset(b,0,sizeof(b));
    for(i=1;i<=500;i++)
    {

        n=i;
        dfs(0,b);
        sort(ans[i].begin(),ans[i].end());
    }
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        scanf("%d",&n);
        printf("Case #%d:",++cas);
        if(n==1)printf(" 0 1");
        if(n!=1&&ans[n].size()==0)
        {
            printf("Impossible");
        }
        for(i=0;i<ans[n].size();i++)
        {
            cout<<" "<<ans[n][i];
        }
        puts("");
    }
    return 0;
}
