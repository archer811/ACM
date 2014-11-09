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
map<string,int>M;
vector<int>v[305];
char s[25];
int ans[305];
struct oo
{
    char s[25];
    int ind;
} g[306];
int cmp(oo a,oo b)
{
    return strcmp(a.s,b.s)<0;
}
char tmp[] = "Isenbaev";
int mark[305];
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        M.clear();
        int tot=2;
        for(i=1; i<=n*3; i++)
            v[i].clear();
        int k=0;
        memset(mark,0,sizeof(mark));
        M["Isenbaev"]=1;
        strcpy(g[0].s,tmp);
        //strcpy(g[0].s,"Isenbaev");
        //g[0].s="Isenbaev";
        g[k++].ind=1;
        cout<<g[0].s<<endl;
        for(i=0; i<n; i++)
        {
            int a,b,c;
            scanf("%s",s);
            a = M[s];
            if(a==0)
            {
                a=M[s]=tot++;
                strcpy(g[k].s,s);
                g[k++].ind=a;
            }

            scanf("%s",s);
            b = M[s];
            if(b==0)
            {
                b=M[s]=tot++;
                strcpy(g[k].s,s);
                g[k++].ind=b;
            }

            scanf("%s",s);
            c = M[s];
            if(c==0)
            {
                c=M[s]=tot++;
                strcpy(g[k].s,s);
                g[k++].ind=c;
            }

            v[a].push_back(b);
            v[a].push_back(c);

            v[b].push_back(a);
            v[b].push_back(c);

            v[c].push_back(a);
            v[c].push_back(b);
            mark[a]=1;
            mark[b]=1;
            mark[c]=1;
//            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        queue<int>q;
        memset(ans,-1,sizeof(ans));
        ans[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            int len=v[u].size();
            for(i=0; i<len; i++)
            {
                int v2=v[u][i];
                if(ans[v2]==-1)
                {
                    //if(v2==4)cout<<ans[u]<<endl;
                    ans[v2]=ans[u]+1;
                    q.push(v2);

                }

            }
        }
        sort(g,g+k,cmp);
//        for(i=0;i<k;i++)
//        {
//            cout<<g[i].s<<"***"<<g[i].ind<<endl;
//        }
        for(i=0; i<k; i++)
        {
            if(mark[g[i].ind]==0)continue;
            if(ans[g[i].ind]==-1)
            {
                printf("%s undefined\n",g[i].s);
            }
            else
            {
                printf("%s %d\n",g[i].s,ans[g[i].ind]);
            }
        }
    }
    return 0;
}
