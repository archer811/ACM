#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m;
int s[100005],a,b,c;
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(s,0,sizeof(s));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(s[a]==0&&s[b]==0&&s[c]==0)
            {
                s[a]=1;s[b]=2;s[c]=3;
            }
            else if(s[a]==0&&s[b]==0&&s[c]!=0)
            {
                if(s[c]==1)
                {
                    s[a]=2;s[b]=3;
                }
                if(s[c]==2)
                {
                    s[a]=1;s[b]=3;
                }
                if(s[c]==3)
                {
                    s[a]=1;s[b]=2;
                }
            }
            else if(s[a]==0&&s[b]!=0&&s[c]==0)
            {
                if(s[b]==1)
                {
                    s[a]=2;s[c]=3;
                }
                if(s[b]==2)
                {
                    s[a]=1;s[c]=3;
                }
                if(s[b]==3)
                {
                    s[a]=1;s[c]=2;
                }
            }
            else if(s[a]!=0&&s[b]==0&&s[c]==0)
            {
                if(s[a]==1)
                {
                    s[b]=2;s[c]=3;
                }
                if(s[a]==2)
                {
                    s[b]=1;s[c]=3;
                }
                if(s[a]==3)
                {
                    s[b]=1;s[c]=2;
                }
            }
            else if(s[a]!=0&&s[b]!=0&&s[c]==0)
            {
                int x=-1,y=-1,z=-1;
                if(s[a]==1)x=1;
                if(s[a]==2)y=1;
                if(s[a]==3)z=1;
                if(s[b]==1)x=1;
                if(s[b]==2)y=1;
                if(s[b]==3)z=1;
                if(x==-1)s[c]=1;
                if(y==-1)s[c]=2;
                if(z==-1)s[c]=3;
            }
            else if(s[a]!=0&&s[b]==0&&s[c]!=0)
            {
                int x=-1,y=-1,z=-1;
                if(s[a]==1)x=1;
                if(s[a]==2)y=1;
                if(s[a]==3)z=1;
                if(s[c]==1)x=1;
                if(s[c]==2)y=1;
                if(s[c]==3)z=1;
                if(x==-1)s[b]=1;
                if(y==-1)s[b]=2;
                if(z==-1)s[b]=3;
            }
            else if(s[a]==0&&s[b]!=0&&s[c]!=0)
            {
                int x=-1,y=-1,z=-1;
                if(s[b]==1)x=1;
                if(s[b]==2)y=1;
                if(s[b]==3)z=1;
                if(s[c]==1)x=1;
                if(s[c]==2)y=1;
                if(s[c]==3)z=1;
                if(x==-1)s[a]=1;
                if(y==-1)s[a]=2;
                if(z==-1)s[a]=3;
            }
            else if(s[a]!=0&&s[b]!=0&&s[c]!=0)
            {

            }
        }
        for(i=1;i<=n;i++)
        {
            if(i==1)cout<<s[i];
            else cout<<" "<<s[i];
        }
        cout<<endl;
    }
}
