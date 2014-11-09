#include <cstdio>

using namespace std;

const int maxn=100000;

int a[maxn],m,n,x,t;
long long s;

void sov() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%d",a+i);
    }
    s=0;
    for (int i=0;i<n;i++) {
        int d=a[i];
        for (int j=i;j<n;j++) {
            d|=a[j];
            if (d>=m)
                break;
            else
                s++;
        }
    }
    printf("%lld\n",s);
    return;
}

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for (int i=0;i<t;i++) {
        printf("Case #%d: ",i+1);
        sov();
    }
    return 0;
}
