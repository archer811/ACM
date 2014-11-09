#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
using namespace std;
#ifdef __int64
typedef __int64 ll;
#else
typedef long long ll;
#endif
/*
const int maxn = 400005;
int head[maxn],tot;
struct Edge
{
    int to,next;
}edge[maxn];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}*/
map<string,int>M;
const int maxn = 1000006;
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
char s[1000006];
vector<string>v,v2;
int main()
{
    int i,j,t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        int len = strlen(s);
        v.clear();
        s[len++]=' ';
        string tmp = "";
        int tot=1;
        for(i=0; i<len; i++)
        {
            if(s[i]==' ')
            {
                if(tmp.length()>0)
                {
                    v.push_back(tmp);
                }
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }

        while(1)
        {
            gets(s);
            v2.clear();
            len = strlen(s);
            s[len++]=' ';
            string tmp = "";
            for(i=0; i<len; i++)
            {
                if(s[i]==' ')
                {
                    if(tmp.length()>0)
                    {
                        v2.push_back(tmp);
                    }
                    tmp = "";
                }
                else
                {
                    tmp += s[i];
                }
            }
            if(v2.size()==3)
            {
                if(M[v2[2]]==0)M[v2[2]]=tot++;
            }
            else
                break;
        }

        int flag=0;
        for(i=0;i<v.size();i++)
        {
            if(M[v[i]]==0)
            {
                if(flag==0)cout<<v[i];
                else cout<<" "<<v[i];
                flag=1;
            }
        }
        puts("");
    }
    return 0;
}
