#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define ll long long
int n,m,r;
const int maxn  = 555;
int s[maxn][maxn];
int d[maxn*2];
int cir[maxn][maxn];
int L[maxn][maxn],R[maxn][maxn],ln[maxn][maxn],rn[maxn][maxn];
int len[maxn*2];
void init()
{
    memset(cir,0,sizeof(cir));
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    memset(ln,0,sizeof(ln));
    memset(rn,0,sizeof(rn));
    memset(len,0,sizeof(len));
}
int _ll[maxn][maxn];
int main()
{
    int i,j,k;
    while(cin>>n>>m>>r)
    {
        init();
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                //continue;
                cin>>s[i][j];
                s[i][j]+=s[i][j-1];
            }
        }
        j=r;
        for(i=0; i<=r; i++)
        {
            while(j*j+i*i>r*r)j--;
            d[i]=j;

            j = 0;
            while(j*j + i*i <= r*r) ++j;
            d[i] = j-1;

            //cout<<i<<" () "<<j<<endl;
        }
        for(i=r+1; i<=n-r; i++)
        {
            for(j=r+1; j<=m-r; j++)
            {
                cir[i][j] += s[i][j+d[0]]-s[i][j-d[0]-1];
                for(k=1; k<=r; k++)
                {
                    cir[i][j] += s[i+k][j+d[k]]-s[i+k][j-d[k]-1];
                    cir[i][j] += s[i-k][j+d[k]]-s[i-k][j-d[k]-1];
                }
                //cout<<i<<" "<<j<<" "<<cir[i][j]<<endl;
            }
        }
        for(i=r+1; i<=n-r; i++)
        {
            for(j=r+1; j<=m-r; j++)
            {
                if(L[i][j-1]<cir[i][j])
                    L[i][j]=cir[i][j],ln[i][j]=1;
                else if(L[i][j-1]==cir[i][j])
                    L[i][j]=cir[i][j],ln[i][j]=ln[i][j-1]+1;
                else L[i][j]=L[i][j-1],ln[i][j]=ln[i][j-1];
                //cout<<i<<" "<<j<<"/////"<<ln[i][j]<<endl;
            }
        }
        for(i=r+1; i<=n-r; i++)
        {
            for(j=m-r; j>=r+1; j--)
            {
                if(R[i][j+1]<cir[i][j])
                    R[i][j]=cir[i][j],rn[i][j]=1;
                else if(R[i][j+1]==cir[i][j])
                    R[i][j]=cir[i][j],rn[i][j]=rn[i][j+1]+1;
                else R[i][j]=R[i][j+1],rn[i][j]=rn[i][j+1];
                //cout<<i<<" "<<j<<" "<<rn[i][j]<<endl;
            }
        }

        for(i=0; i<=r*2; i++)
        {
            len[i]=0;
            for(j=0; j<=r; j++)
            {
                if(i-j>r)continue;
                //cout<<i<<"!"<<j<<" "<<i-j<<endl;
                len[i]=max(len[i],d[j]+d[abs(i-j)]+1);
            }

        }


        ll ansx=-1;
        ll ansy=0;
        for(i=r+1; i<=n-r; i++)
        {
            for(j=r+1; j<=m-r; j++)
            {
                for(k=r+1; k<=n-r; k++)
                {
                    int tmp = len[abs(k-i)];
                    ll areasum=cir[i][j];
//                    if(i==5&&j==7&&k==7)
//                        cout<<i<<" "<<j<<" "<<k<<" "<<j-tmp<<" "<<
//                            j+tmp<<"&&"<<
//                            L[k][j-tmp]<<" "<<
//                            R[k][j+tmp]<<endl;
                    if(j-tmp>=r+1)
                    {
//                        if(areasum+L[k][j-tmp]==74)
//                            cout<<i<<" "<<j<<" "<<k<<" "<<j-tmp
//                                <<" "<<cir[i][j]<<" "<<L[k][j-tmp]<<endl;
                        if(areasum+L[k][j-tmp]>ansx)
                        {
                            ansx = areasum+L[k][j-tmp];
                            ansy=ln[k][j-tmp];

                        }
                        else if(areasum+L[k][j-tmp]==ansx)
                        {
                            ansx = areasum+L[k][j-tmp];
                            ansy+=ln[k][j-tmp];
                        }
                    }
                    int temp=j+tmp;
                    if(tmp==0)temp=j+tmp+1;
                    //if(i==2&&j==2)cout<<temp<<"!~!!!!~~~~~~~~~~~~~"<<endl;
                    if(temp<=m-r)
                    {
                        if(areasum+R[k][temp]>ansx)
                        {
//                            if(areasum+R[k][temp]==74)
//                            cout<<i<<" ** "<<j<<" "<<k<<endl;
                            ansx = areasum+R[k][temp];
                            ansy = rn[k][temp];
                        }
                        else if(areasum+R[k][temp]==ansx)
                        {
                            ansx = areasum+R[k][temp];
                            ansy += rn[k][temp];
                        }
                    }
//                    cout<<ansx<<" "<<ansy<<endl;
                }
            }
        }
        if(ansx==-1)ansx=0;
        cout<<ansx<<" "<<ansy/2<<endl;
    }
}
