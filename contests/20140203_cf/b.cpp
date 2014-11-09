#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;
int n;
int a[101],b[101];
int ans[101];
int main()
{
    int i,j;
    while(cin>>n)
    {
        memset(b,0,sizeof(b));
        for(i=0; i<n; i++)
            cin>>a[i],b[a[i]]++;
        memset(ans,0,sizeof(ans));
        int now = 0,Max=0;
//        for(i=0;i<=100;i++)
//        {
//            if(b[i])
//            {
//                int tmp = i+1;
//                if(b[i]%tmp==0)now=b[i]/tmp;
//                else now=b[i]/tmp+1;
//                cout<<now<<" "<<tmp<<"!!!"<<b[i]<<endl;
//                for(j=0;j<now;j++)
//                {
//                    tmp = i+1-b[i];
//                    if(b[i]&&b[i]>=tmp)
//                    {
//                        b[i]-=tmp;
//                        ans[now++]=tmp;
//                    }
//                    else if(b[i])
//                    {
//                        ans[now++]=b[i];
//                        b[i] =0;
//                    }
//                    if(b[i]==0)break;
//                }
//              //
//                break;
//            }
//        }
//        cout<<now<<"&"<<endl;
//        for(j=0; j<now; j++)
//            cout<<j<<"!"<<ans[j]<<endl;
        for(i=0; i<=100; i++)
        {
            if(b[i]==0)continue;
//            cout<<i<<" ( ) "<<b[i]<<" "<<now<<endl;
            for(j=0; j<now; j++)
            {
                int tmp = i+1-ans[j];

                //cout<<itmp<<endl;
                if(b[i]&&b[i]>=tmp)
                {
                    b[i]-=tmp;
                    ans[j]+=tmp;
//                    if(i<=34)
//                        cout<<j<<"()"<<ans[j]<<endl;
                }
                else if(b[i])
                {
                    ans[j]+=b[i];
                    b[i]=0;
                    //cout<<j<<")("<<ans[j]<<endl;
                }
                if(b[i]==0)break;
            }

            if(b[i])
            {
                while(1)
                {
                    int tmp = i+1-0;

                    //cout<<itmp<<endl;
                    if(b[i]&&b[i]>=tmp)
                    {
                        b[i]-=tmp;
                        ans[now++]+=tmp;
                    }
                    else if(b[i])
                    {

                        ans[now++]=b[i];
                        b[i]=0;
                        //cout<<")("<<ans[j]<<endl;
                    }
                    if(b[i]==0)break;
                    if(now>=100)break;
                }
            }
        }
        cout<<now<<endl;
    }
}
