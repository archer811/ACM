#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<string,int>M;
struct array
{
    char a[15];
}s[4];
int cmp(array x,array y)
{
    return strcmp(x.a,y.a)<0;
}
int vis[800005];
int b[]={1,2,4,8,16};
int tot;
int g[4];
void f(int x,int num)
{
    char ans[60];
    int k=0,i,j;
    int t=0;
    while(x)
    {
        if(x%2)
        {
            g[t++]=1;
        }
        else g[t++]=0;
        x/=2;
    }
    while(t<num)g[t++]=0;
    for(i=0;i<num;i++)
    {
        if(g[i])
        {
            int tmp = strlen(s[i].a);
            for(j=0;j<tmp;j++)
                ans[k++]=s[i].a[j];
            ans[k++]='+';
        }
    }
    ans[k]='\0';
    if(M[ans]==0)
        {
            M[ans]=tot++;
        }
        vis[M[ans]]++;
}
int main()
{
    int i,j,k,n,num,q;
    while(scanf("%d",&n)!=EOF)
    {
        M.clear();
        tot =1;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            for(j=0;j<num;j++)
                scanf("%s",s[j].a);
            sort(s,s+num,cmp);
            for(j=0;j<b[num];j++)
            {
                f(j,num);
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&num);
            char ans[60];
            for(i=0;i<num;i++)
            {
                scanf("%s",s[i].a);
            }
            sort(s,s+num,cmp);
            k = 0;
            for(i=0;i<num;i++)
            {
                int tmp = strlen(s[i].a);
                for(j=0;j<tmp;j++)
                    ans[k++]=s[i].a[j];
                ans[k++]='+';
            }
            ans[k]='\0';
            int tmp = M[ans];
            printf("%d\n",vis[tmp]);

        }
    }
}
