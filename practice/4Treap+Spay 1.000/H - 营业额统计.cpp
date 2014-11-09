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
#define ll long long
const int inf = 20000000;
struct Node
{
    Node *ch[2];
    int r,v;
    void init()
    {
        srand(time(0));
    }
    Node(int _v)
    {
        v=_v;
        ch[0]=ch[1]=NULL;
        r = rand();
    }
};
int ans,sum;
void rotate(Node* &k,int d)
{
    Node* y = k->ch[d^1];
    k->ch[d^1]=y->ch[d];
    y->ch[d]=k;
    k=y;
}
void add(Node* &k,int num)
{
    if(k==NULL)
    {
        k = new Node(num);
        return;
    }
    if(num>k->v)
    {
        int tmp = num-(k->v);
        if(tmp<ans)ans=tmp;
        add(k->ch[1],num);
        if(k->ch[1]->r>k->r)
        {
            rotate(k,0);
        }
    }
    else if(num<k->v)
    {
//        cout<<"gG"<<k->v<<endl;
        int tmp = (k->v)-num;
        if(tmp<ans)ans=tmp;
        add(k->ch[0],num);
        if(k->ch[0]->r>k->r)
        {
            rotate(k,1);
        }
    }
    else
    {
        ans = 0;
    }
}
void output(Node *k)
{
    int t1,t2;
    if(k->ch[0]!=NULL)t1=k->ch[0]->v;
    else t1=-1;

    if(k->ch[1]!=NULL)t2=k->ch[1]->v;
    else t2=-1;

//    cout<<"L="<<t1<<" "<<k->v<<" "<<"R="<<t2<<endl;
    if(k->ch[0]!=NULL)
        output(k->ch[0]);

    if(k->ch[1]!=NULL)
        output(k->ch[1]);
}
void de(Node *k)
{
    if(k==NULL)return;
    if(k->ch[0]!=NULL)de(k->ch[0]);
    if(k->ch[1]!=NULL)de(k->ch[1]);
    delete k;
    k = NULL;
}
Node *root;
int main()
{
    int i,j,n,d;
    //srand(time(0));
    scanf("%d",&n);
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            if(scanf("%d",&d) == EOF)
            d = 0;
            ans = inf;
//            cout<<d<<"DDD"<<endl;
            add(root,d);
            if(i==1)
            {
                sum += d;
            }
            else sum += ans;
//            cout<<sum<<endl;
        }
        printf("%d\n",sum);
    }
}
