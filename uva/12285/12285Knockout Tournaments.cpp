#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int w,l;
const double c = 0.57721566490153286060;
double cal(int num)
{
    if(num<0)return 0.0;
    int i,j;
    double sum=0;
    if(num<=10000)
    {
        for(i=1;i<=num;i++)
            sum += 1.0/i;
    }
    else
    {
        sum = log(num)+c;
    }
    return sum;
}
int main()
{
    int i,j,k;
    int cas=0;
    while(scanf("%d%d",&w,&l)!=EOF)
    {
        if(w==0&&l==0)break;
        printf("Case %d: ",++cas);
        if(w%8&&l==0)
        {
            puts("Situation Impossible.");
            continue;
        }
        double ans = w*1.0+l*1.0;
        int left;
        if(w<=7*l)
            left = l;
        else left = w/8+l;
        //cout<<w<<" "<<w/8+l<<endl;
        int right = w/8+l;

        left = min(left,right);

        double tmp = cal(right)-cal(left-1);
        //cout<<left<<" "<<right<<" "<<tmp<<" "<<ans<<endl;

        int t = right-left+1;
        //cout<<w/8+l<<" "<<l<<" "<<ans<<" "<<tmp<<" "<<t<<endl;
        printf("On Average Bob Reaches Round %.2f\n",ans*1.0*tmp/t*1.0);
        //printf("On Average Bob Reaches Round %.2f\n",cas++,ans*res);
    }
}
