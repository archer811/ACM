#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int a[10005];
struct array
{
    int x,y;
}now;
vector<array>v;
void move(int a2,int b)
{
    int i,j=b;
    for(i=a2;i<b;i++)
    {
        swap(a[i],a[j]);
        j++;
    }
}
int main()
{
    int i,j,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        v.clear();
        for(i=1;i<=n;i++)
        {
            if(a[i]==i)continue;
            int k=-1;
            for(j=i+1;j<=n;j++)
            {
                if(a[j]==i)
                {
                    k=j;break;
                }
            }
            //cout<<i<<"ooo"<<k<<endl;
            if(n-i+1>=2*(k-i))
            {
                now.x=i;
                now.y = k*2-i-1;
                v.push_back(now);
                move(i,k);
                //cout<<i<<"  "<<i<<"* "<<k<<endl;
            }
            else
            {
                now.x = 2*k-1-n;
                now.y = n;
                //cout<<i<<"()"<<2*k-1-n<<"  "<<k<<endl;
                v.push_back(now);
                move(2*k-1-n,k);
                i--;
            }
        }
        printf("%d\n",v.size());
        for(i=0;i<v.size();i++)
        {
            printf("%d %d\n",v[i].x,v[i].y);
        }
    }
}
/*
2
6
5 4 6 3 2 1
5
1 2 3 4 5


 */
