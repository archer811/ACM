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
const int maxn = 511115;

struct ACtrie
{
    int chd[maxn][2],word[maxn],fail[maxn],sz;
    void init()
    {
        memset(chd,0,sizeof(chd));
        sz=1;
        memset(fail,0,sizeof(fail));
        word[0]=0;
        memset(word,0,sizeof(word));
    }
    int idx(char c){ return c-'0'; }
    void Ins(char *s,int val)
    {
//        int p = 0;
//        for(; *s; s++)
//        {
//            if(!chd[p][(*s)-'0'])
//            {
//                memset(chd[sz],0,sizeof(chd[sz]));
//                word[sz]=0;
//                chd[p][(*s)-'0']=sz++;
//            }
//            p = chd[p][(*s)-'0'];
//        }
//        word[p]=1;

        int u = 0;

        for(int i = 0; s[i] ; i++)
        {
            int c = idx(s[i]);
            if(!chd[u][c])
                chd[u][c] = sz++;

            u = chd[u][c];
        }
        word[u] = 1;
    }
    void AC()
    {
//        int *s = Que,*e = Que;
//        for(int i=0; i<2; i++)
//        {
//            if(chd[0][i])
//            {
//                fail[chd[0][i]]=0;
//                *e++=chd[0][i];
//            }
//        }
//        while(s!=e)
//        {
//            int p = *s++;
//            for(int i=0; i<2; i++)
//            {
//                if(chd[p][i])
//                {
//                    int k = chd[p][i];
//                    int temp = fail[p];
//                    while(temp && !chd[temp][i])
//                        temp = fail[temp];
//                    fail[k]=chd[temp][i];
//                    *e++=k;
//                }
//            }
//        }

        queue<int> q;
        for(int i = 0; i<2; i++)
            if(chd[0][i]) q.push(chd[0][i]);

        while(!q.empty())
        {
            int r = q.front();
            q.pop();
            for(int c = 0; c<2; c++)
            {
                int u = chd[r][c];
                if(!u)continue;
                q.push(u);
                int v = fail[r];
                while(v && chd[v][c] == 0) v = fail[v]; //沿失配边走上去 如果失配后有节点 且 其子节点c存在则结束循环
                fail[u] = chd[v][c];
            }
        }
    }
    int solve(char *s)
    {
//        int p=0;
//        int sum=0;
//        for(; *s; s++)
//        {
//            int c = (*s)-'0';
//            while(p && chd[p][c]==0)p=fail[p];
//            p = chd[p][c];
//            int temp = p;
//            while(temp)
//            {
//                sum += word[temp];
//                temp = fail[temp];
//            }
//        }
//        return sum;

        int j = 0, ans = 0;
        for(int i = 0; s[i] ; i++)
        {
            int c = (s[i]-'0');
            while(j && chd[j][c]==0) j = fail[j];
            j = chd[j][c];

            int temp = j;
            while(temp)  //沿失配边走 || 若沿失配边走时一定要节点为单词结尾则改成while(temp && val[temp])
            {
                ans += word[temp];
                temp = fail[temp];
            }
        }
        return ans;
    }
    int search(char *s)
    {
        int p=0;
        for(; *s; s++)
        {
            if(chd[p][(*s)-'0'])
                p = chd[p][(*s)-'0'];
            else return 0;
        }
        return word[p];
    }
} ac,tmp;
//char s[7654321],s2[7654321];
void dfs(int u,int v)
{
//    for(int i=0; i<2; i++)
//    {
//        if(tmp.chd[v][i])
//        {
//            if(ac.chd[u][i]==0)
//            {
//                memset(ac.chd[ac.sz],0,sizeof(ac.chd[ac.sz]));
//                ac.chd[u][i]=ac.sz++;
//            }
//            ac.word[ac.chd[u][i]]|=tmp.word[tmp.chd[v][i]];
//            dfs(ac.chd[u][i],tmp.chd[v][i]);
//        }
//    }

    for(int i = 0; i < 2; i++)
    {
        if( tmp.chd[v][i] )
        {
            int e2 = tmp.chd[v][i];
            if(! ac.chd[u][i])
            {
                memset(ac.chd[ac.sz], 0, sizeof(ac.chd[ac.sz]));
                ac.chd[u][i] = ac.sz++;
            }
            int e1 = ac.chd[u][i];
            ac.word[e1] |= tmp.word[e2];
            dfs(e1, e2);
        }
    }
}
void join()
{
    dfs(0,0);
    ac.AC();
    tmp.init();
}
char s[6000000],temp[6000000];
int main()
{
    int i,j,t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ac.init();
        tmp.init();
        printf("Case #%d:\n",++cas);
        /*
        int pre=0;
        int tot=1;

        while(n--)
        {
            scanf("%s",s);
            if(s[0]=='+')
            {
                int k=0;
                int len = strlen(s);
                for(i=1; i<len; i++)
                    s2[k++]=s[i];
                s2[k]='\0';
                if(tmp.sz>2000)
                {
                    join();
                }
                int x = ac.search(s2);
                int y = tmp.search(s2);
                if(x==0&&y==0)
                {
                    tmp.Ins(s2,tot++);
                    tmp.AC();
                }
            }
            else
            {
                int k=0;
                int len = strlen(s);
                for(i=pre+1; i<len; i++)
                    s2[k++]=s[i];
                for(i=1; i<=pre; i++)
                    s2[k++]=s[i];
                s2[k]='\0';
                //cout<<s2<<"!!"<<endl;

                pre = ac.solve(s2)+tmp.solve(s2);
                printf("%d\n",pre);
            }
        }*/

        int L = 0;
        while(n--)
        {
            scanf("%s",temp);
            int len = strlen ( temp + 1 ) ;
            s[0] = temp[0] ;
            for (int i = 0 ; i < len ; i ++ )
                s[i+1] = temp[1+(i+L%len+len)%len] ;
            s[len+1] = '\0';
            if(s[0] == '+')
            {
                if( tmp.search(s+1) || ac.search(s+1) )continue;//若单词已存在
                tmp.Ins(s+1,1);
                tmp.AC();
                if(tmp.sz > 2000) join();
            }
            else
            {
                L = tmp.solve(s+1) + ac.solve(s+1);
                printf("%d\n", L);
            }
        }
    }
    return 0;
}
