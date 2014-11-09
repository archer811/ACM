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
char s[22];
int k;
struct array
{
    int mark,mod,len,th;
    friend bool operator <(array x,array y)
    {
        if(x.len!=y.len)return x.len>y.len;
        return x.a.compare(y.a)>0;
    }
    string a;
} now,next;
priority_queue<array>q;
string bfs()
{
    int i,j,len = strlen(s);
    now.mark=1;
    now.mod=0;
    now.a = "";
    now.len=0;
    now.th=0;
    q.push(now);
    while(!q.empty())
    {
        now = q.top();
        //if(now.len==8)
         //   cout<<now.a<<"()"<<endl;
        q.pop();
        if(now.mod==0&&now.th==len)
        {
            return now.a;
        }
        if(now.mark==1)
        {
            if(now.th<len)
            {
                next.mark=-1;
                next.mod=(now.mod*2+s[now.th]-'0')%k;
                next.a=now.a+s[now.th];
                next.len=now.len+1;
                next.th=now.th+1;
                //cout<<next.a<<"&"<<endl;
                q.push(next);

                next.mark=1;
                next.mod=(now.mod*2+s[now.th]-'0')%k;
                next.a=now.a+s[now.th];
                next.len=now.len+1;
                next.th=now.th+1;
                //cout<<next.a<<"*"<<endl;
                q.push(next);
            }
        }
        else
        {
            next.mark=-1;
            next.mod=(now.mod*2+0)%k;
            next.a=now.a+"0";
            next.len=now.len+1;
            next.th=now.th;
            q.push(next);


            next.mark=-1;
            next.mod=(now.mod*2+1)%k;
            next.a=now.a+"1";
            next.len=now.len+1;
            next.th=now.th;
            q.push(next);

            if(now.th<len)
            {
                next.mark=1;
                next.mod=(now.mod*2+0)%k;
                next.a=now.a+"0";
                next.len=now.len+1;
                next.th=now.th;
                q.push(next);
            }

        }
    }
}
int main()
{
    int i,j;
    while(scanf("%s%d",s,&k)!=EOF)
    {
        while(!q.empty())q.pop();
        string ans = bfs();
        cout<<ans<<endl;
    }
}
