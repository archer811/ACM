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
struct array
{
    int x,y;
} ans1[1000],ans2[1000];
int main()
{
    int i,j;
    int a,b;
    while(cin>>a>>b)
    {
        int x=-1,y=-1,x2,y2;
        if(a>b)swap(a,b);
        int flag=0;
        //if(g2*g2==gg)
        {
            int t1=0,t2=0;
            for(i=1; i<a; i++)
            {
                int tmp = a*a-i*i;
                int g = sqrt(tmp);
                if(g*g==tmp)
                {
                    ans1[t1].x=i;
                    ans1[t1++].y=g;
                }
            }

            for(i=1; i<b; i++)
            {
                int tmp = b*b-i*i;
                int g = sqrt(tmp);
                if(g*g==tmp)
                {
                    ans2[t2].x=i;
                    ans2[t2++].y=g;
                }
            }

            int mark=0;
            for(i=0; i<t1&&mark==0; i++)
            {
                for(j=0; j<t2&&mark==0; j++)
                {
                    //if(ans1[i].x*ans2[j].x==ans1[i].y*ans2[])
                    if(ans1[i].x!=ans2[j].x)
                    {
                        x=ans1[i].x;
                        y=ans2[j].x;
                        x2 = ans1[i].y;
                        y2 = ans2[j].y;
                        if(x*y==x2*y2)
                        {
                            mark=1;
                            break;
                        }
                        else
                        {
                            x=-1;
                            y=-1;
                        }
                    }

                    if(ans1[i].x!=ans2[j].y)
                    {
                        x=ans1[i].x;
                        y=ans2[j].y;
                        x2 = ans1[i].y;
                        y2 = ans2[j].x;
                        if(x*y==x2*y2)
                        {
                            mark=1;
                            break;
                        }
                        else
                        {
                            x=-1;
                            y=-1;
                        }
                    }

                    if(ans1[i].y!=ans2[j].x)
                    {
                        x=ans1[i].y;
                        y=ans2[j].x;
                        x2 = ans1[i].x;
                        y2 = ans2[j].y;
                        if(x*y==x2*y2)
                        {
                            mark=1;
                            break;
                        }
                        else
                        {
                            x=-1;
                            y=-1;
                        }
                    }

                    if(ans1[i].y!=ans2[j].y)
                    {
                        x=ans1[i].y;
                        y=ans2[j].y;
                        x2 = ans1[i].x;
                        y2 = ans2[j].x;
                        if(x*y==x2*y2)
                        {
                            mark=1;
                            break;
                        }
                        else
                        {
                            x=-1;
                            y=-1;
                        }
                    }
                }
            }
            if(x!=-1&&y!=-1)
            {
                puts("YES");
                int x2 = sqrt(a*a-x*x);
                int y2 = sqrt(b*b-y*y);
                cout<<0<<" "<<x<<endl;
                cout<<x2<<" "<<0<<endl;
                //cout<<x2+y<<" "<<0<<endl;
                cout<<x2+y2<<" "<<y<<endl;
                flag=1;
            }


        }


        if(flag==0)
        {
            int gg = b*b-a*a;
            int g2 = sqrt(gg);

            if(g2*g2==gg)
            {
                b = g2;
                int t1=0,t2=0;
                for(i=1; i<a; i++)
                {
                    int tmp = a*a-i*i;
                    int g = sqrt(tmp);
                    if(g*g==tmp)
                    {
                        ans1[t1].x=i;
                        ans1[t1++].y=g;
                    }

                }

                for(i=1; i<b; i++)
                {
                    int tmp = b*b-i*i;
                    int g = sqrt(tmp);
                    if(g*g==tmp)
                    {
                        ans2[t2].x=i;
                        ans2[t2++].y=g;
                    }
                }

                int mark=0;
                for(i=0; i<t1&&mark==0; i++)
                {
                    for(j=0; j<t2&&mark==0; j++)
                    {
                        //if(ans1[i].x*ans2[j].x==ans1[i].y*ans2[])
                        if(ans1[i].x!=ans2[j].x)
                        {
                            x=ans1[i].x;
                            y=ans2[j].x;
                            x2 = ans1[i].y;
                            y2 = ans2[j].y;
                            if(x*y==x2*y2)
                            {
                                mark=1;
                                break;
                            }
                            else
                            {
                                x=-1;
                                y=-1;
                            }
                        }

                        if(ans1[i].x!=ans2[j].y)
                        {
                            x=ans1[i].x;
                            y=ans2[j].y;
                            x2 = ans1[i].y;
                            y2 = ans2[j].x;
                            if(x*y==x2*y2)
                            {
                                mark=1;
                                break;
                            }
                            else
                            {
                                x=-1;
                                y=-1;
                            }
                        }

                        if(ans1[i].y!=ans2[j].x)
                        {
                            x=ans1[i].y;
                            y=ans2[j].x;
                            x2 = ans1[i].x;
                            y2 = ans2[j].y;
                            if(x*y==x2*y2)
                            {
                                mark=1;
                                break;
                            }
                            else
                            {
                                x=-1;
                                y=-1;
                            }
                        }

                        if(ans1[i].y!=ans2[j].y)
                        {
                            x=ans1[i].y;
                            y=ans2[j].y;
                            x2 = ans1[i].x;
                            y2 = ans2[j].x;
                            if(x*y==x2*y2)
                            {
                                mark=1;
                                break;
                            }
                            else
                            {
                                x=-1;
                                y=-1;
                            }
                        }
                    }
                }
                if(x!=-1&&y!=-1)
                {
                    puts("YES");
                    int x2 = sqrt(a*a-x*x);
                    int y2 = sqrt(b*b-y*y);
                    cout<<0<<" "<<x<<endl;
                    cout<<x2<<" "<<0<<endl;
                    //cout<<x2+y<<" "<<0<<endl;
                    cout<<x2+y2<<" "<<y<<endl;
                    flag=1;
                }


            }
        }
        if(flag==0)
            puts("NO");

        //cout<<0
    }
}
