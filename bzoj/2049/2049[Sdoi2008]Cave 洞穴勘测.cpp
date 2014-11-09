/* ***********************************************
Author        :kuangbin
Created Time  :2013-9-3 22:29:16
File Name     :F:\2013ACM练习\专题学习\动态树-LCT\BZOJ2049洞穴勘测.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//支持三种操作：
//1.合并子树
//2.分裂子树
//3.询问x是否可达y
//
//Access(x) : 其实是把路径x到根打通，并且整条链用splay维护，这颗splay的
//所有节点就是这条路径上的节点
//link(u,v) : 把两颗子树合并为一颗树。先把u置为根，然后把u的父亲置为v.
//cut(u,v)  : 把u和v分离成两颗子树。先把u置为根，然后把y splay到根，把
//y 把左儿子与y分离
const int MAXN = 10010;
int ch[MAXN][2],pre[MAXN];
int rev[MAXN];
bool rt[MAXN];//rt[]表示该点是否为splay的根
void Update_Rev(int r)
{
    if(!r)return;
    swap(ch[r][0],ch[r][1]);
    rev[r] ^= 1;
}
void push_down(int r)
{
    if(rev[r])
    {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r] = 0;
    }
}
void push_up(int r)
{

}
void Rotate(int x)
{
    int y = pre[x], kind = ch[y][1]==x;
    ch[y][kind] = ch[x][!kind];
    pre[ch[y][kind]] = y;
    pre[x] = pre[y];
    pre[y] = x;
    ch[x][!kind] = y;
    if(rt[y])
        rt[y] = false, rt[x] = true;
    else
        ch[pre[x]][ch[pre[x]][1]==y] = x;
    push_up(y);
}
void P(int r)
{
    if(!rt[r])P(pre[r]);
    push_down(r);
}
void Splay(int r)
{
    P(r);
    while( !rt[r] )
    {
        int f = pre[r], ff = pre[f];
        if(rt[f])
            Rotate(r);
        else if( (ch[ff][1]==f)==(ch[f][1]==f) )
            Rotate(f), Rotate(r);
        else
            Rotate(r), Rotate(r);
    }
    push_up(r);
}
//Access(x) :打通路径x到根节点
int Access(int x)
{
    int y = 0;
    do
    {
        Splay(x);
        rt[ch[x][1]] = true, rt[ch[x][1]=y] = false;
        push_up(x);
        x = pre[y=x];
    }
    while(x);
    return y;
}
//判断是否同根(真实的树，非splay)
bool judge(int u,int v)
{
    while(pre[u]) u = pre[u];
    while(pre[v]) v = pre[v];
    return u == v;
}
//使r成为所在树的根
void mroot(int r)
{
    Access(r);
    Splay(r);
    Update_Rev(r);
}
void link(int u,int v)
{
    if(judge(u,v))
    {
        puts("-1");
        return;
    }
    mroot(u);
    pre[u] = v;
}
void cut(int u,int v)
{
    if(u == v || !judge(u,v))
    {
        puts("-1");
        return;
    }
    mroot(u);
    Splay(v);
    pre[ch[v][0]] = pre[v];
    pre[v] = 0;
    rt[ch[v][0]] = true;
    ch[v][0] = 0;
    push_up(v);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        for(int i = 0; i <= n; i++)
        {
            pre[i] = 0;
            ch[i][0] = ch[i][1] = 0;
            rev[i] = 0;
            rt[i] = true;
        }
        char op[20];
        int u,v;
        while(m--)
        {
            cin>>u>>v;
            link(u,v);
            for(int i=0; i<=3; i++)
                cout<<ch[i][0]<<" "<<ch[i][1]<<" "<<pre[i]<<endl;
            cout<<endl;
        }
    }
    return 0;
}
