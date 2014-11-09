#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define ll __int64
struct array
{
    int n;
    bool vis;
    int a[15];
    int a2[15][2][25];
    int b[15];
    ll c[15][2];
} ans[1025];
char op[2],s[10000];
void f(int num,int g)
{

    int i,j,len;
    len = strlen(s);
    int sum =0 ;
    int b[33];
    for(i=32; i>=0; i--)
        b[i]=0;
    int tmp =0,just=7;
    for(i=0; i<len; i++)
    {
        if(s[i]=='.')
        {
            j = just;
            just+=8;
            while(tmp)
            {
                b[j]=tmp%2;
                j-=1;
                tmp /= 2;
            }
            tmp =0;
        }
        else if(s[i]=='/')
        {
            j = just;
            just+=7;
            while(tmp)
            {
                b[j--]=tmp%2;
                tmp /= 2;
            }
            break;
        }
        else
        {
            tmp = tmp*10+s[i]-'0';
        }
    }
    sum =0;
//    for(j=0;j<32;j++)
//        cout<<b[j];
//    cout<<endl;
    for(j=0; j<8; j++)
        sum = sum*2+b[j];
    ans[num].a[g] = sum;
//    cout<<sum<<endl;
    tmp =0;
    i++;
    for(; i<len; i++)
        tmp = tmp*10+s[i]-'0';
    ans[num].b[g]=tmp;
    int k=0;
    for(; j<32; j++)
    {
        if(j<tmp)ans[num].a2[g][0][k]=ans[num].a2[g][1][k]=b[j],k++;
        else ans[num].a2[g][0][k]=b[j],ans[num].a2[g][1][k++]=1;
    }
    __int64 temp = ans[num].a[g];
    for(i=0;i<24;i++)
        temp = temp*(__int64)2+ans[num].a2[g][0][i];
    ans[num].c[g][0]=temp;
    temp = ans[num].a[g];
    for(i=0;i<24;i++)
        temp = temp*(__int64)2+ans[num].a2[g][1][i];
    ans[num].c[g][1]=temp;
}
int start[25],end[25];
ll ss,ee;
void gg()
{
    int i,j,len;
    len = strlen(s);
    int sum =0 ;
    int b[33];
    for(i=32; i>=0; i--)
        b[i]=0;
    int tmp =0,just=7;
    for(i=0; i<len; i++)
    {
        if(s[i]=='.')
        {
            j = just;
            just+=8;
//            cout<<tmp<<endl;
            while(tmp)
            {
                b[j]=tmp%2;
                j-=1;
                tmp /= 2;
            }
            tmp =0;
        }
        else
        {
            tmp = tmp*10+s[i]-'0';
        }
    }
    j = just;
    just+=7;
    while(tmp)
    {
        b[j--]=tmp%2;
        tmp /= 2;
    }
    sum =0;
    for(j=0; j<8; j++)
        sum = sum*2+b[j];
    if(ss==-1)ss=sum;
    else ee = sum;

   // cout<<sum<<endl;
    int k=0;
    if(ee==-1)
    {
        for(; j<32; j++)
        {
            start[k++]=b[j];
        }
        for(j=8;j<32;j++)
        ss = ss*(ll)2+b[j];
    }
    else
    {
        for(; j<32; j++)
        {
           end[k++]=b[j];
        }
        for(j=8;j<32;j++)
        ee = ee*(ll)2+b[j];
    }


}
int Num,Num2;
int judge(int num)
{
    int i,j;
    for(i=0; i<ans[num].n; i++)
    {
        if((ans[num].a[i]^ss))continue;
        int flag=0,flag2=0;
        for(j=0; j<24; j++)
        {
            //cout<<j<<" "<<ans[num].a2[i][0][j]<< " "<<start[j]<< " "<<end[j]<<endl;
            if(j<ans[num].b[i]-8&&ans[num].a2[i][0][j]!=start[j])break;
            else continue;
            if(ans[num].a2[i][0][j]==0&&start[j]==1){flag=1;break;}
            if(ans[num].a2[i][0][j]==1&&start[j]==0&&flag==0)break;
        }
        if(j==24){Num++;break;}
    }
    //if(Num>=1&&Num2>=1)return 1;
    for(i=0; i<ans[num].n; i++)
    {
        if((ans[num].a[i]^ee))continue;
        int flag=0,flag2=0;
        for(j=0; j<24; j++)
        {
            if(j<ans[num].b[i]-8&&ans[num].a2[i][0][j]!=end[j])break;
            else continue;
            if(ans[num].a2[i][0][j]==0&&end[j]==1){flag=1;break;}
            if(ans[num].a2[i][0][j]==1&&end[j]==0&&flag==0)break;
        }
        if(j==24){Num2++;break;}
    }
    return 0;
}
int judge2(int num)
{
    int i,j;
    for(i=0;i<ans[num].n;i++)
    {
        //cout<<ans[num].c[i][0]<<" "<<ans[num].c[i][1]<<" "<<ss<<endl;
        if(ss>=ans[num].c[i][0]&&ss<=ans[num].c[i][1])return 1;
    }
    return 0;
}
int judge3(int num)
{
    int i,j;
    for(i=0;i<ans[num].n;i++)
    {
        //cout<<ans[num].c[i][0]<<" "<<ans[num].c[i][1]<<" "<<ee<<endl;
        if(ee>=ans[num].c[i][0]&&ee<=ans[num].c[i][1])return 1;
    }
    return 0;
}
int main()
{
    int i,j,k,n;
    while(scanf("%s",op)!=EOF)
    {
        if(op[0]=='E')
        {
            scanf("%d%d",&k,&n);
            ans[k].n = n;
            ans[k].vis = true;
            for(i=0; i<n; i++)
            {
                scanf("%s",s);
                f(k,i);
            }
            for(i=0; i<n; i++)
            {
                for(j=0; j<24; j++)
                    cout<<ans[k].a2[i][0][j];
                cout<<endl;
                for(j=0; j<24; j++)
                    cout<<ans[k].a2[i][1][j];
                cout<<endl;
                cout<<endl;
            }
        }
        else if(op[0]=='F')
        {
            ss = ee = -1;
            scanf("%s",s);
            gg();
            scanf("%s",s);
            gg();
//            for(i=0; i<24; i++)
//                cout<<start[i];
//            cout<<endl;
//            for(i=0; i<24; i++)
//                cout<<end[i];
//            cout<<endl;
            int flag =0;
            Num=0;Num2=0;
            for(i=0; i<1024; i++)
            {
                if(ans[i].vis)
                {
//                    judge(i);
//                    if(Num>=1&&Num2>=1)
//                    {
//                        break;
//                    }
                      //if(judge2(i))Num++;
                      //if(judge3(i))Num2++;
                      //if(Num>=1&&Num2>=1)break;
                      int tmp = (judge2(i)&&judge3(i));

                      if(tmp)break;
                }
            }
            if(i>=1024)puts("D");
            else puts("F");
        }
        else
        {
            scanf("%d",&k);
            ans[k].n  = 0;
            ans[k].vis = false;
        }
    }
}
