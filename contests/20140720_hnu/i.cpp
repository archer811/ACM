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
const int inf=108;
int a[103];
int findFirstGreaterThanOrEqual(int array[], int N, int X) {
int start = 0, end = N;
while (start < end) {
int middle = (start + end) / 2;
if (array[middle] > X) {
end = middle;
} else {
start = middle + 1;
}
}
return start;
}
int main()
{
    int i,j,n,x,y;
    int t;
    //freopen("t.txt","r",stdin);
    //freopen("i.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        for(int i=0;i<n-1;i++)
            a[i]=i+1;
        a[n]=inf;
        int flag=0;
        for(int i=n;i<=100;i++)
        {
            a[n-1]=i;
            int k=findFirstGreaterThanOrEqual(a,n,x);
            //cout<<i<<" "<<k<<"  "<<a[k]<<" "<<x<<"\n";
            if(y==1&&a[k]>=x&&a[k-1]<x) {flag=1;break;}
            if(y==2)
            {
                if(a[k]>=x&&a[k-1]<x) continue;
                else break;
            }
           // else if(y==2&&a[k-1]>=x) {flag=1;break;}
        }
        //if(flag==0)cout<<"**"<<endl;
        for(int i=0;i<n-1;i++) printf("%d ",a[i]); printf("%d\n",a[n-1]);
    }
    return 0;
}
