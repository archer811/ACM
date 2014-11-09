#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
char s[11111];
int v[200];
int n,m;
int fa[200];
int ant;
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void f(int num)
{
    int j;
    int len = strlen(s);
    int flag=0,sum=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            if(flag)
            {
                v[num]++;
                v[sum]++;
                ant++;
                int a= find(num),b = find(sum);
                if(a!=b)fa[a]=b;
                sum=0;flag=0;
            }
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            sum = sum*10+s[i]-'0';
            flag=1;
        }
    }
    if(flag)
    {
        v[num]++;
        v[sum]++;
        ant++;
        int a= find(num),b = find(sum);
        if(a!=b)fa[a]=b;
        sum=0;flag=0;
    }
}
int judge()
{
    int t = find(0);
    for(int i=1;i<n;i++)
    {
        if(find(i)!=t){return 0;}
    }
    return 1;
}


int main()
{
    int i,j,k;
    char cmd[111];
    while(scanf("%s",cmd)!=EOF)
    {
        if(strcmp(cmd,"ENDOFINPUT")==0)break;
        scanf("%d%d",&m,&n);ant=0;
        memset(v,0,sizeof(v));
        for(i=0;i<n;i++)
            fa[i]=i;
        getchar();
        for(i=0;i<n;i++)
        {
            gets(s);
            f(i);
        }
        gets(s);
//        if(judge()==0)
//        {
//            puts("NO");
//            continue;
//        }
        int ok=0;
        for(i=0;i<n;i++)
            if(v[i]%2)ok++;
        if(m==0)
        {
            if(ok){puts("NO");continue;}
        }
        else
        {
            if(!(ok==2&&v[m]%2&&v[0]%2)){puts("NO");continue;}
        }
        printf("YES %d\n",ant);
       // cout<<ant<<endl;
    }
}
