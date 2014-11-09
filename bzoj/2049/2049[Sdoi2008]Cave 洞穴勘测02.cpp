#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int ch[maxn][2],pre[maxn];
int rev[maxn];
bool rt[maxn];
void update_rev(int r)
{
    if(!r)return;
    swap(ch[r][0],ch[r][1]);
    rev[r]^=1;
}
void push_down(int r)
{
    if(rev[r])
    {
        update_rev(ch[r][0]);
        update_rev(ch[r][1]);
        rev[r]=0;
    }
}
void push_up(int r)
{

}
void rotate(int x)
{
    int y = pre[x],kind = ch[y][1]==x;
    ch[y][kind]=ch[x][!kind];
    pre[ch[y][kind]]=y;
    pre[x]=pre[y];
    pre[y]=x;
    ch[x][!kind]=y;
    if(rt[y])
        rt[y]=false,rt[x]=true;
    else
        ch[pre[x]][ch[pre[x]][1]==y]=x;
    push_up(y);
}
void P(int r)
{
    if(!rt[r])P(pre[r]);
    push_down(r);
}
void splay(int r)
{
    P(r);
    while(!rt[r])
    {
        int f = pre[r],ff  = pre[f];
        if(rt[f])
            Rotate(r);
        else if((ch[ff][1]==f)==(ch[f][1]==f))
            Rotate(f),Rotate(r);
        else Rotate(r),Rotate(r);
    }

}
