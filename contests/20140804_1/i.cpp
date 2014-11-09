#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 101
int ha[MAXN][MAXN][MAXN];
int row,col;
bool dfs(int p,int q,int r){
    if(ha[p][q][r]==1)return 1;
    else if(ha[p][q][r]==0)return 0;
    else{
        int p1,q1,r1;
        for(p1=p;p1>=2;p1--){
            q1=min(p1-1,q);
            r1=min(q1,r);
            if(dfs(p1-1,q1,r1)==0){
                row=1;col=p1;
                return ha[p][q][r]=1;
            }
        }
        for(q1=q;q1>=1;q1--){
            r1=min(r,q1-1);
            if(dfs(p,q1-1,r1)==0){
                row=2;col=q1;
                return ha[p][q][r]=1;
            }
        }
        for(r1=r;r1>=1;r1--){
            if(dfs(p,q,r1-1)==0){
                row=3;col=r1;
                return ha[p][q][r]=1;
            }
        }
        return ha[p][q][r]=0;
    }
}
int main()
{
    int t;
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    scanf("%d",&t);
    memset(ha,-1,sizeof(ha));
    ha[1][0][0]=0;
    //ha[1][1][0]=ha[2][0][0]=1;
    while(t--){
        int p,q,r,cas;
        scanf("%d%d%d%d",&cas,&p,&q,&r);
        ha[p][q][r]=-1;
        if(dfs(p,q,r)==0){
            printf("%d L\n",cas);
        }
        else {
            printf("%d W %d %d\n",cas,col,row);
        }
    }
    return 0;
}
