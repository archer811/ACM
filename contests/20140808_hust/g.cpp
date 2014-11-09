#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define ll long long

//4 3 1 2 4 3
//4 2 1 3
// 1 4
char s[1000005];
int g[][4]={0,0,0,0,
            1,1,1,1,
            1,2,4,3,
            1,3,4,2,
            1,4,1,4};
int main()
{
    int i,j;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%s",s)!=EOF)
    {
        int a=1,b=0,c=0,d=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            b=(b*10+s[i]-'0')%4;
            c=(c*10+s[i]-'0')%4;
            d=(d*10+s[i]-'0')%2;
        }
        //cout<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
        b = g[2][b];
        c = g[3][c];
        d = g[4][d];
        //cout<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
        printf("%d\n",(a+b+c+d)%5);
    }
    return 0;
}
