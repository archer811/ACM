
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;


const int N=2010;



int a[N],b[N],temp[N];
int T,m,n;

struct Node
{
    int num,a,b;
    friend bool operator < (const Node &a,const Node &b)
    {
        return a.num>b.num;
    }
};

priority_queue<Node> q;

int main()
{
//   freopen("in.txt","r",stdin)
    int i,j;
    Node t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=1; i<m; i++)
        {
            while(!q.empty())q.pop();
            for(j=0; j<n; j++)
                scanf("%d",&b[j]);
            sort(b,b+n);
            for(j=0; j<n; j++)
                q.push(Node {a[j]+b[0],j,0});
            for(j=0; j<n; j++)
            {
                t=q.top();
                q.pop();
                temp[j]=t.num;
                q.push(Node {a[t.a]+b[t.b+1],t.a,t.b+1});
            }
            for(j=0; j<n; j++)a[j]=temp[j];
        }

        printf("%d",a[0]);
        for(j=1; j<n; j++)
            printf(" %d",a[j]);
        putchar('\n');
    }
    return 0;
}
