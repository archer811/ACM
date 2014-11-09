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
int i,j,n;
struct array
{
    int x,y,z;
}s[100000];
int cmp(array a,array b)
{
    if(a.x==b.x&&a.y==b.y)return a.z<b.z;
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    scanf("%d",&n);
    printf("%d\n",n*(n-1)/2);
    int num=0;
    for(i=1; i<=n/2; i++)
        for(j=0; j<n; j++)
        {
            s[num].x=j+1;
            s[num].y=(j+i)%n+1;
            s[num++].z=(j+i+i)%n+1;
            printf("%d %d %d\n",j+1,(j+i)%n+1,(j+i+i)%n+1);
        }
    sort(s,s+num,cmp);
    for(i=0;i<num;i++)
    {
        //cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].z<<endl;
    }

}
