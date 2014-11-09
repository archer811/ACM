#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef long long LL;
const LL MOD = LL(1e9)+7;
void mod(LL &x){
    if(x >= MOD)(x=x%MOD+MOD);
    }

const int maxn = 100010;
char A[maxn],B[maxn];
int len;
LL num[maxn][2];
bool isok[maxn];

bool maybe(char c,char b){
    return c == b || c == '?';
    }
void output(){
    LL a,b;
    int p;
    for(int i=1;i<=len;i++){
        if(i == len){
            a=num[i-1][0]*(maybe(A[i],'0')&&maybe(B[i],'1'));
            b=num[i-1][1]*(maybe(A[i],'1')&&maybe(B[i],'0'));
                }
        else {
            a=num[i-1][0]*(maybe(A[i],'0')&&maybe(B[i],'1'))*
            (maybe(A[i+1],'1')&&maybe(B[i+1],'1')&&isok[i+2]);
            b=num[i-1][1]*(maybe(A[i],'1')&&maybe(B[i],'0'))
                *(maybe(A[i+1],'1')&&maybe(B[i+1],'1')&&isok[i+2]);
            }
        if(a+b){
            if(a){A[i]='0';B[i]='1';}
            else {A[i]='1';B[i]='0';}
            p=i;
            break;
            }
        }
    for(int i=1;i<p;i++){
        if(A[i]=='?')A[i]=B[i];
        if(B[i]=='?')B[i]=A[i];
        }
    A[p+1]=B[p+1]='1';
    for(int i=p+2;i<=len;i++)
        A[i]=B[i]='0';
    }

int main()
{

    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        printf("Case #%d:\n",kase);

        scanf("%s%s",&A[1],&B[1]);
        len=strlen(&A[1]);
        A[0]=B[0]='?';

        memset(num,0,sizeof(num));
        num[0][0]=1LL;
        num[0][1]=0LL;
        for(int i=1;i<=len;i++){
            if(maybe(A[i],'0')&&maybe(B[i],'0')){
                num[i][0]+=num[i-1][0];
                num[i][1]+=num[i-1][1];
                }
            if(maybe(A[i],'1')&&maybe(B[i],'1')){
                num[i][0]+=num[i-1][1];
                num[i][1]+=num[i-1][0];
                }
            mod(num[i][0]);
            mod(num[i][1]);
            }

        memset(isok,0,sizeof(isok));
        isok[len+1]=isok[len+2]=1;
        for(int i=len;i>=1;i--)
            isok[i]=isok[i+1]&&maybe(A[i],'0')&&maybe(B[i],'0');

        LL ans = 0,temp;
        for(int i=1;i<=len;i++){
            if(i == len)
                temp = (num[i-1][0]*(maybe(A[i],'0')&&maybe(B[i],'1'))+
                    num[i-1][1]*(maybe(A[i],'1')&&maybe(B[i],'0')));
            else temp = (num[i-1][0]*(maybe(A[i],'0')&&maybe(B[i],'1'))+
                    num[i-1][1]*(maybe(A[i],'1')&&maybe(B[i],'0')))
                    *(maybe(A[i+1],'1')&&maybe(B[i+1],'1')&&isok[i+2]);
            //cout<<"--------------------     "<<ans<<endl;
            ans += temp;
            mod(ans);
            }
        //cout<<ans<<endl;

        if(ans){
            if(ans > 1)
                printf("Ambiguous %I64d\n",ans%MOD);
            else {
                output();
                for(int i=1;i<=len;i++)
                    putchar(A[i]);printf("\n");
                for(int i=1;i<=len;i++)
                    putchar(B[i]);printf("\n");
                }
            }else printf("Impossible\n");
        }

    return 0;
}
