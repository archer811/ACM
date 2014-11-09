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
int a[4],isleap;
//其中1月、3月、5月、7月、8月、10月、12月为31天；
//4月、6月、9月、11月为30天；2月为28天(闰年为29天)
int f(int d,int m,int y,int a,int b,int c)
{
    if((2000+c)%4==0)isleap=1;
    else isleap=0;
    if(!(c>=1&&c<=99))return 0;
    if(!(b>=1&&b<=12))return 0;

    if(b==1||b==3||b==5||b==7||b==8||b==10||b==12)
    {
        if(a>31||a<=0)return 0;
    }
    if(b==4||b==6||b==9||b==11)
    {
        if(a>=31||a<=0)return 0;
    }
    if(isleap&&b==2&&(a<=0||a>29))return 0;
    if(isleap==0&&b==2&&(a<=0||a>28))return 0;

    c+=18;
    if(c>99)return 0;

    if(c<y||(c==y&&b<m)||(c==y&&b==m&&a<=d))
    {
        //cout<<"@"<<d<<" "<<m<<" "<<y<<" "<<a<<" "<<b<<" "<<c<<endl;
        return 1;
    }

    return 0;
}
int main()
{
    int i,j,d,m,y;
    while(scanf("%d.%d.%d",&d,&m,&y)!=EOF)
    {
        scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        int flag=0;
        if(f(d,m,y,a[0],a[1],a[2]))flag=1;
        while(next_permutation(a,a+3))
        {
            if(f(d,m,y,a[0],a[1],a[2]))flag=1;
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}
