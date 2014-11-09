#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
char s[100008];
using namespace std;
const int inf = 0x3fffffff;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int l=strlen(s);
        int sum=0,minx=0,miny=0,maxx=0,maxy=0;
        minx=miny=maxx=maxy=0;
        int k1=inf,k2=inf,k3=-inf,k4=-inf;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='?')
            {
                sum++;
                maxx++,maxy++;
                minx--,miny--;
            }
            if(s[i]=='R')
            {
                maxx++;minx++;
            }
            if(s[i]=='L')
            {
                maxx--;minx--;
            }
            if(s[i]=='U')
            {
                maxy++;miny++;
            }
            if(s[i]=='D')
            {
                maxy--;miny--;
            }
            //cout<<
            //if(minx>maxx)swap(minx,maxx);
//            k1=min(k1,maxx);
//            k1=min(k1,minx);
//            k2=min(k2,miny);
//            k2=min(k2,maxy);
//            k3=max(k3,maxx);
//            k3=max(k3,minx);
//            k4=max(k4,miny);
//            k4=max(k4,maxy);
        }

        printf("%d %d %d %d\n",minx,miny,maxx,maxy);
    }
    return 0;
}
