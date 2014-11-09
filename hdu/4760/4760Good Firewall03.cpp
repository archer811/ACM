#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LS(t) (t<<1)
#define RS(t) ((t<<1)|1)
#define MD(l,r) (((l)+(r))>>1)
int cnt[1111];
long long a[1111][20], b[1111][20];
char s[1000];

long long toInt(string s)
{
    long long ret = 0;
    for (int i = 0; i < s.size(); i ++) {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}

long long getIP(string s)
{
    long long ret = 0;
    for (int i = 0; i < 3; i ++) {
        int k = s.find(".");
        ret = (ret << 8) | toInt(s.substr(0, k));
        s = s.substr(k + 1);
    }
    return (ret << 8) | toInt(s);
}

void Insert()
{
    int k;
    scanf("%d", &k);
    scanf("%d", &cnt[k]);
    for (int i = 0; i < cnt[k]; i ++) {
        scanf("%s", s);
        string st = s;
        int v = st.find("/");
        int x = 32 - toInt(st.substr(v + 1));
        st = st.substr(0, v);
        a[k][i] = getIP(st);
        a[k][i] = (a[k][i] >> x) << x;
        b[k][i] = a[k][i] + (1 << x);
        cout<<a[k][i]<<" "<<b[k][i]<<endl;
    }
}

bool check(int k, long long x)
{
    for (int i = 0; i < cnt[k]; i ++)
    if (a[k][i] <= x && x < b[k][i]) {
        return true;
    }
    return false;
}

char Query()
{
    scanf("%s", s);
    long long x = getIP(s);
    scanf("%s", s);
    long long y = getIP(s);
    for (int i = 0; i < 1024; i ++)
    if (cnt[i]) {
        if (check(i, x) && check(i, y)) {
            return 'F';
        }
    }
    return 'D';
}

void Delete()
{
    int k;
    scanf("%d", &k);
    cnt[k] = 0;
}

int main()
{
    while (scanf("%s", s) != EOF) {
        if (s[0] == 'E') {
            Insert();
        } else if (s[0] == 'F') {
            printf("%c\n", Query());
        } else {
            Delete();
        }
    }
    return 0 ;
}
