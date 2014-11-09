#include <iostream>
#include<cstring>
using namespace std;

//圆盘的个数最多为64
const int MAX = 64;

int g[10][10];
//用来表示每根柱子的信息
struct st
{
    int s[MAX]; //柱子上的圆盘存储情况
    int top; //栈顶，用来最上面的圆盘
    char name; //柱子的名字，可以是A，B，C中的一个
    int Top()//取栈顶元素
    {
        return s[top];
    }
    int Pop()//出栈
    {
        return s[top--];
    }
    void Push(int x)//入栈
    {
        s[++top] = x;
    }
} ;

long Pow(int x, int y); //计算x^y
void Creat(st ta[], int n); //给结构数组设置初值
void Hannuota(st ta[], long max); //移动汉诺塔的主要函数

int main(void)
{
    int n;
    while(1)
    {
        memset(g,0,sizeof(g));
        cin >> n; //输入圆盘的个数
        st ta[3]; //三根柱子的信息用结构数组存储
        Creat(ta, n); //给结构数组设置初值

        long max = Pow(2, n) - 1;//动的次数应等于2^n - 1<
        Hannuota(ta, max);//移动汉诺塔的主要函数
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i==j)continue;
                cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
            }

        }
    }


    return 0;
}

void Creat(st ta[], int n)
{
    ta[0].name = 'A';
    ta[0].top = n-1;
    //把所有的圆盘按从大到小的顺序放在柱子A上
    for (int i=0; i<n; i++)
        ta[0].s[i] = n - i;
    //柱子B，C上开始没有没有圆盘
    ta[1].top = ta[2].top = 0;
    for (int i=0; i<n; i++)
        ta[1].s[i] = ta[2].s[i] = 0;
    //若n为偶数，按顺时针方向依次摆放 A B C
    if (n%2 == 0)
    {
        ta[1].name = 'B';
        ta[2].name = 'C';
    }
    else  //若n为奇数，按顺时针方向依次摆放 A C B
    {
        ta[1].name = 'C';
        ta[2].name = 'B';
    }
}

long Pow(int x, int y)
{
    long sum = 1;
    for (int i=0; i<y; i++)
        sum *= x;

    return sum;
}

void Hannuota(st ta[], long max)
{
    int k = 0; //累计移动的次数
    int i = 0;
    int ch;
    while (k < max)
    {
        //按顺时针方向把圆盘1从现在的柱子移动到下一根柱子
        ch = ta[i%3].Pop();
        ta[(i+1)%3].Push(ch);
        g[ta[i%3].name-'A'][ta[(i+1)%3].name-'A']++;
        cout << ++k << ": " <<
             "Move disk " << ch << " from " << ta[i%3].name <<
             " to " << ta[(i+1)%3].name << endl;
        i++;
        //把另外两根柱子上可以移动的圆盘移动到新的柱子上
        if (k < max)
        {
            //把非空柱子上的圆盘移动到空柱子上，当两根柱子都为空时，移动较小的圆盘
            if (ta[(i+1)%3].Top() == 0 ||
                    ta[(i-1)%3].Top() > 0 &&
                    ta[(i+1)%3].Top() > ta[(i-1)%3].Top())
            {
                ch =  ta[(i-1)%3].Pop();
                ta[(i+1)%3].Push(ch);
                g[ta[(i-1)%3].name-'A'][ta[(i+1)%3].name-'A']++;
                cout << ++k << ": " << "Move disk "
                     << ch << " from " << ta[(i-1)%3].name
                     << " to " << ta[(i+1)%3].name << endl;
            }
            else
            {
                ch =  ta[(i+1)%3].Pop();
                ta[(i-1)%3].Push(ch);
                g[ta[(i+1)%3].name-'A'][ta[(i-1)%3].name-'A']++;
                cout << ++k << ": " << "Move disk "
                     << ch << " from " << ta[(i+1)%3].name
                     << " to " << ta[(i-1)%3].name << endl;
            }
        }
    }
}
