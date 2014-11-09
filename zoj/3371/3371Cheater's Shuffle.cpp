#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;
int n,t,p;
map<string,int>M;
struct array
{
    char str[73];
    int fa,num,op;
}s[781250];
int l[6],m[6];
int tot;
char h[73];
queue<int>q;
bool flag;
void dfshead(int x)
{
    int i,j;
    while(!q.empty())q.pop();
    q.push(1);
    while(!q.empty())
    {
        int tmp = q.front();q.pop();
        for(i=0;i<p;i++)
        {
            int k =0;
            for(j=2*(n-l[i]-m[i]);j<2*(n-m[i]);j++)
                h[k++]=s[tmp].str[j];
            for(j=0;j<2*(n-l[i]-m[i]);j++)
                h[k++]=s[tmp].str[j];
            for(j=2*(n-m[i]);j<2*n;j++)
                h[k++]=s[tmp].str[j];
            if(M[h])continue;
            if(s[tmp].num+1>x)continue;
            M[h]=tot++;
            k = M[h];
            s[k].fa = tmp;s[k].op = i;
            strcpy(s[k].str,h);
            s[k].num=s[tmp].num+1;
            q.push(k);
        }
    }
}
void dfsend(int x)
{
    int i,j;
    while(!q.empty())q.pop();
    q.push(2);
    while(!q.empty())
    {
        if(flag)break;
        int tmp = q.front();q.pop();
        for(i=0;i<p;i++)
        {
            if(flag)break;
            int k =0;
            for(j=2*(n-l[i]-m[i]);j<2*(n-m[i]);j++)
                h[k++]=s[tmp].str[j];
            for(j=0;j<2*(n-l[i]-m[i]);j++)
                h[k++]=s[tmp].str[j];
            for(j=2*(n-m[i]);j<2*n;j++)
                h[k++]=s[tmp].str[j];
            if(flag)break;
            if(M[h])
            {
                if(s[tmp].num+1==x)
                {
                    output(M[h],s[tmp].fa);
                }
                else continue;
            }
            if(s[tmp].num+1>x)continue;
            M[h]=tot++;
           // cout<<i<<endl;
            //cout<<h<<endl;
            k = M[h];
            s[k].fa = tmp;
            strcpy(s[k].str,h);
            s[k].num=s[tmp].num+1;
            q.push(k);
        }
    }
}
int main()
{
    int i,j,k,d;
    while(scanf("%d%d%d",&n,&t,&p)!=EOF)
    {
        k=0;
        M.clear();
        tot =3;
        for(i=0;i<n;i++)
        {
            scanf("%d",&d);
            if(d/10==0)s[1].str[k++]='0',s[1].str[k++]='0'+d%10;
            else s[1].str[k++]='0'+d/10,s[1].str[k++]='0'+d%10;
        }
        s[1].fa = -1;s[1].num=0;s[1].op = -1;
        M[s[1].str]=1;
        k = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&d);
            if(d/10==0)s[2].str[k++]='0',s[2].str[k++]='0'+d%10;
            else s[2].str[k++]='0'+d/10,s[2].str[k++]='0'+d%10;
        }
        s[2].fa = -1;s[2].num=0;s[2].op=-1;
        M[s[2].str]=2;
        for(i=0;i<p;i++)
            scanf("%d%d",&m[i],&l[i]);
        ok = false;
        dfshead(t/2);
        dfsend(t-t/2);
        if(ok==false)puts("Impossible");
    }
}
