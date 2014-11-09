#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 100005;
struct array
{
    int index,num;
    bool friend operator < (array x,array y)
    {
        return x.num>y.num;
    }
};
array ans[5];
array now;
int a[maxn],vis[maxn];
typedef pair<int,int>PII;
priority_queue<PII>q;
int numback,numque,numsta,numfro;
int main()
{
    int i,j,k,n,m;
    while(scanf("%d",&n)!=EOF)
    {
        int all=0;
        memset(vis,0,sizeof(vis));
        numque=numsta=numfro=0;
        for(int g=1;g<=n;g++)
        {
            scanf("%d",&m);
            a[g]=m;
            if(m==0)
            {
                if(q.size()){vis[q.top().second]=1;q.pop();}
                if(q.size()){vis[q.top().second]=1;q.pop();}
                if(q.size()){vis[q.top().second]=1;q.pop();}
                q=priority_queue<PII>();
            }
            else
            {
                now.index = g;
                now.num = m;
                s.insert(now);
            }
        }
        for(int g=1;g<=n;g++)
        {
            if(a[g]==0)
            {
                int num=0;
                if(numque)num++;
                if(numsta)num++;
                if(numfro)num++;
                if(num==0)
                {
                    puts("0");
                    continue;
                }
                else
                {
                    printf("%d",num);
                    if(numque)
                    {
                        numque--;
                        printf(" popQueue");
                    }
                    if(numsta)
                    {
                        numsta--;
                        printf(" popStack");
                    }
                    if(numfro)
                    {
                        numfro--;
                        printf(" popFront");
                    }
                }
                puts("");
            }
            else
            {
                if(vis[g])
                {
                    int ant = 1,M=numque;
                    if(numsta<=M){M=numsta;ant=2;}
                    if(numfro<=M){M=numfro;ant=3;}
                    if(ant==1)numque++,puts("pushQueue");
                    else if(ant==2)numsta++,puts("pushStack");
                    else if(ant==3)numfro++,puts("pushFront");
                }
                else puts("pushBack");
            }
        }
    }
}
