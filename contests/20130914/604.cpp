#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int md = 1000000007;
const int N = 100005;
char a[N],b[N];
int n,c0[N],cq[N],w0[N],wq[N],fq[N];

int er[N];

inline bool myb0(const char &c){
    return c=='0' || c=='?';
}
inline bool myb1(const char &c){
    return c=='1' || c=='?';
}
inline bool myp(const char &a,const char &b){
    return (myb0(a) && myb1(b)) || (myb1(a) && myb0(b));
}

void g0(){
    int i;
    c0[n+1] = 1;
    w0[n+1] = 0;
    c0[n+2] = 1;
    w0[n+2] = 0;
    for(i = n;i;i--){
        if(myb0(a[i]) && myb0(b[i])){
            c0[i] = 1;
            if(a[i] == '?' && b[i] == '?')
                w0[i] = w0[i+1] + 1;
            else w0[i] = w0[i+1];
        }
        else break;
    }
    for(;i;i--) c0[i] = 0;
}
void gs(){
    int i;
    cq[0] = 1;
    wq[0] = 0;
    fq[0] = 0;
    for(i = 1;i<=n;i++){

        if(a[i] != '?') fq[i] = fq[i-1]^(a[i] - '0');
        else if(b[i] != '?') fq[i] = fq[i-1]^(b[i] - '0');
        else fq[i] = fq[i-1];

        if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
            break;
        else{
            cq[i] = 1;
            if(a[i] == '?' && b[i] == '?')
                wq[i] = wq[i-1] + 1;
            else wq[i] = wq[i-1];
        }
    }
    for(;i<=n;i++) cq[i] = 0;
}
bool onlyone(int x){
    if((wq[x-2] + (a[x-1]=='?' && b[x-1]=='?')) > 1) return false;
    int ctp;
    if(a[x-1] != '?') ctp = a[x-1] - '0';
    else if(b[x-1] != '?') ctp = 1 - (b[x-1] - '0');
    else ctp = 0;
    int qnum = fq[x-2]^ctp;
    for(int i=1;i<x-1;i++){
        if(a[i] != '?') putchar(a[i]);
        else if(b[i] != '?')putchar(b[i]);
        else putchar(qnum + '0');
    }
    if(a[x-1] == '?'){
        if(b[x-1] == '0') putchar('1');
        else if(b[x-1] == '1')putchar('0');
        else putchar(qnum + '0');
    }
    else putchar(a[x-1]);
    if(x <= n) putchar('1');
    for(int i=x+1;i<=n;i++){
        putchar('0');
    }
    puts("");
    for(int i=1;i<x-1;i++){
        if(b[i] != '?') putchar(b[i]);
        else if(a[i] != '?') putchar(a[i]);
        else putchar(qnum + '0');
    }
    if(b[x-1] == '?'){
        if(a[x-1] == '0') putchar('1');
        else if(a[x-1] == '1')putchar('0');
        else putchar((1-qnum)+'0');
    }
    else putchar(b[x-1]);
    if(x <= n)putchar('1');
    for(int i=x+1;i<=n;i++){
        putchar('0');
    }
    return true;
}
int main(){
    //freopen("in.txt", "r", stdin);
    er[0] = 1;
    for(int i=1;i<N;i++){
        er[i] = er[i-1]<<1;
        if(er[i] >= md) er[i] -= md;
    }
    int T,C=0;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d:\n",++C);
        scanf("%s%s",a+1,b+1);
        n = strlen(a+1);
        ll ans = 0,cnt = 0, j;
//        if(n == 1){
//            if(myb0(a[1]) && myb1(b[1])){
//                puts("0\n1");
//            }
//            else puts("Impossible");
//            continue;
//        }
        g0();
        gs();
        for(int i=2;i<=n+1;i++)if(((myb1(a[i]) && myb1(b[i])) || i==n+1) && myp(a[i-1],b[i-1]) && cq[i-2] && c0[i+1]){
            int tmp = wq[i-2];
            if(a[i-1] == '?' && b[i-1] == '?') tmp++;
            int ctp;
            if(a[i-1] != '?') ctp = a[i-1] - '0';
            else if(b[i-1]!='?') ctp = 1 - (b[i-1] - '0');
            else ctp = 0;
            if(tmp == 0){
                if(fq[i-2] != ctp)
                    continue;
                else tmp = 1;
            }
            j = i;
            cnt++;
            ans += er[tmp-1];
            if(ans >= md) ans -= md;
        }
        if(cnt == 0){
            puts("Impossible");
        }
        else if(cnt == 1 && onlyone(j)){
            puts("");
        }
        else printf("Ambiguous %I64d\n",ans);
    }
    return 0;
}
