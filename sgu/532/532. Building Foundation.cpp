#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 3200;
struct array
{
    int x1,y1,x2,y2;
}s[maxn],t1,t[maxn];
int f(int i,int k)
{
//    cout<<i<<"**"<<k<<" "<<s[i].x1<<" "<<s[i].y1<<" "<<s[i].x2<<" "<<s[i].y2<<
//    " "<<t[k].x1<<" "<<t[k].y1<<" "<<t[k].x2<<" "<<t[k].y2<<endl;
//    cout<<(t[k].x1<=s[i].x1&&t[k].x2>=s[i].x1)<<" "<<
//    (s[i].y1<=t[k].y1&&s[i].y2>=t[k].y1)<<endl;
    if(t[k].x1<=s[i].x1&&t[k].x2>=s[i].x1&&s[i].y1<=t[k].y1&&s[i].y2>=t[k].y1)
        return 1;
    return 0;
}
int main()
{
    int i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        int h=0,l=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&t1.x1,&t1.y1,&t1.x2,&t1.y2);
            if(t1.x1==t1.x2)
            {
                if(t1.y1>t1.y2)swap(t1.y1,t1.y2);
                s[h++]=t1;
            }
            else
            {
                if(t1.x1>t1.x2)swap(t1.x1,t1.x2);
                t[l++]=t1;
            }
        }
        //cout<<h<<" "<<l<<endl;
//        for(i=0;i<h;i++)
//            cout<<s[i].x1<<" "<<s[i].y1<<" "<<s[i].x2<<" "<<s[i].y2<<endl;
//
//
//        for(i=0;i<l;i++)
//            cout<<t[i].x1<<" "<<t[i].y1<<" "<<t[i].x2<<" "<<t[i].y2<<endl;

        int ans =0;
        for(i=0;i<h;i++)
        {
            for(j=i+1;j<h;j++)
            {
                int sum=0;
                for(k=0;k<l;k++)
                {
                    if(f(i,k)&&f(j,k))
                        sum++;
                }
                //cout<<i<<" "<<j<<" "<<sum<<endl;
                ans += (sum-1)*sum/2;
            }
        }
        printf("%d\n",ans);
    }
}
