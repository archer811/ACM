#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 30
using namespace std;

int l[maxn];
int mp[maxn][maxn];
int n,m,k;

bool dfs(int x,int y,int letter){
    if(letter==27)letter=1;
    if(y==m){
        y=0;
        x++;
        if(x==n){
            puts("YES");
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    printf("%c",mp[i][j]-1+'a');
                }
                puts("");
            }
            return true;
        }
    }
    if(mp[x][y])return dfs(x,y+1,letter);
    for(int i=0;i<k;i++){
        bool can=false;
        if(y+l[i]-1<m) {
            for(int j=y; j<y+l[i]; j++) {
                if(mp[x][j]) {
                    can=true;
                    break;
                }
            }
        }else can=true;
        if(can!=true){
            for(int j=y;j<y+l[i];j++){
                mp[x][j]=letter;
            }
            if(dfs(x,y+1,letter+1))return true;
            for(int j=y;j<y+l[i];j++){
                mp[x][j]=0;
            }
        }
        can=false;
        if(x+l[i]-1<n) {
            for(int j=x; j<x+l[i]; j++) {
                if(mp[j][y]) {
                    can=true;
                    break;
                }
            }
        }else can=true;
        if(can!=true){
            for(int j=x;j<x+l[i];j++){
                mp[j][y]=letter;
            }
            if(dfs(x,y+1,letter+1))return true;
            for(int j=x;j<x+l[i];j++){
                mp[j][y]=0;
            }
        }
    }
    return false;
}

int main() {
    int i;
    int cnt;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        cnt=0;
        for(i=0;i<k;i++){
            scanf("%d",&l[i]);
            if(l[i]%2==0)cnt++;
        }
        sort(l,l+k);
        memset(mp,0,sizeof(mp));

        if(cnt==k&&(n*m%2==1)||!dfs(0,0,1)){
            puts("NO");
        }
    }
    return 0;
}
