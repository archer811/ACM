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
struct Node
{
    int value;
    vector<Node>son;
};
int Min,Max,flag_min,flag_max;
void dfs(Node now_root)
{
    if(flag_min==0)
    {
        Min=now_root.value;
        flag_min = 1;
    }
    else
    {
        Min = min(Min,now_root.value);
    }

    if(flag_max==0)
    {
        Max=now_root.value;
        flag_max = 1;
    }
    else
    {
        Max = max(Min,now_root.value);
    }
    int siz = now_root.son.size();
    for(int i=0;i<siz;i++)
    {
        dfs(now_root.son[i]);
    }
}
int main()
{
    Node root;
    flag_min=0;
    flag_max=0;
    dfs(root);
}
