#include
#include
#include
using namespace std;
struct ITEM
{
    int begin;
    int end;
};
struct running//运行中的内存
{
    int id;//用于测试
    int begin;
    int end;
    int releaseT;
    bool operator<(const running& r) const//重载小于符号，以大于的功能去用小于
    {
        return (releaseT > r.releaseT);
    }
};
struct waiting
{
    int id;
    int memory;
    int spendT;
};
int N, T, M, P;
list freeList;//保存空闲内存的链表
queue waitQueue;//等待队列
priority_queue runQueue;//建立小顶堆
list::iterator iter;
int time = 0, waitSum = 0;
bool AllocateMem(int now, int Mem, int spentT, int id);
void AllocateForWaitQ(int nowT);
void ReleaseMem(running& r);
void releaseAllocate();
int main()
{

    cin >> N;
    ITEM item;
    item.begin = 0;
    item.end = N - 1;
    freeList.push_back(item);
    int id = 0;
    while (cin >> T >> M >> P)
    {
        id++;
        if (!T && !M && !P) break;
        //if (P == 0) P = 1;
        //先释放内存，再分配等待队列中的进程，最后处理当前的申请
        while (!runQueue.empty() && runQueue.top().releaseT <= T)
        {
            releaseAllocate();
        }
        if (!AllocateMem(T, M, P, id))//给当前申请的进程分配内存
        {
            waitSum++;
            waiting tmp;
            tmp.memory = M;
            tmp.spendT = P;
            tmp.id = id;
            //cout << T << "  进入等待队列：" << id << endl;
            waitQueue.push(tmp);
        }
        time = T;
    }
    while (!(runQueue.empty() && waitQueue.empty()))//不同时为空
    {
        if (!runQueue.empty())//释放正在运行的进程
        {
            releaseAllocate();
        }
    }
    cout << time << endl << waitSum << endl;
    return 0;
}

//释放运行中的进程和为等待队列分配
void releaseAllocate()
{
    int timeTmp = time = runQueue.top().releaseT;
    while (time == timeTmp && !runQueue.empty())//表示还是同一时刻
    {
        //cout << time  << "  " << runQueue.top().begin << "---" << runQueue.top().end
        // << "  释放" << runQueue.top().id << endl;
        ReleaseMem(runQueue.top());
        runQueue.pop();
        if (!runQueue.empty())
        {
            timeTmp = runQueue.top().releaseT;//要把某个时刻堆上该释放的释放完才给等待队列分配
        }
    }
    AllocateForWaitQ(time);
}
//给等待队列分配内存
void AllocateForWaitQ(int nowT)
{
    while (!waitQueue.empty())
    {
        waiting wait = waitQueue.front();
        if (AllocateMem(nowT, wait.memory, wait.spendT, wait.id))
        {
            waitQueue.pop();
        }
        else
        {
            break;
        }
    }
}

//分配内存
bool AllocateMem(int now, int Mem, int spentT, int id)
{
    iter = freeList.begin();
    int sizeFreeM;
    while (iter != freeList.end())
    {
        sizeFreeM = iter->end - iter->begin + 1;
        if (sizeFreeM >= Mem)
        {
            running tmp;
            tmp.begin = iter->begin;
            tmp.end = iter->begin + Mem - 1;
            tmp.releaseT = spentT + now;
            tmp.id = id;
            runQueue.push(tmp);//放入运行时的优先级队列中
            if (sizeFreeM == Mem)
            {
                freeList.erase(iter);
            }
            else
            {
                iter->begin = tmp.end + 1;//修改空闲内存链表
            }
            //cout << now << "  " << tmp.begin << "---" << tmp.end << "  分配"  << id << endl;
            return true;
        }
        else
        {
            iter++;
        }
    }
    return false;
}

//释放内存
void ReleaseMem(running& r)
{
    int begin, end;
    ITEM tmp;
//如果空闲链表为空则直接插入链表中
    if (freeList.empty())
    {
        tmp.begin = r.begin;
        tmp.end = r.end;
        freeList.push_front(tmp);
        return;
    }
//插入链表头
    iter = freeList.begin();
    if (r.end + 1 == iter->begin)
    {
        iter->begin = r.begin;
        return;
    }
    else if (iter->begin > r.end + 1)
    {
        tmp.begin = r.begin;
        tmp.end = r.end;
        //freeList.insert(iter, tmp);
        freeList.push_front(tmp);
        return;
    }
//插入链表尾
    iter = freeList.end();
    iter--;
    if (r.begin -1 == iter->end)
    {
        iter->end = r.end;
        return;
    }
    else if (iter->end < r.begin - 1)
    {
        tmp.begin = r.begin;
        tmp.end = r.end;
        //freeList.insert(iter, tmp);//错误处：自以为插在最后一个位置上，实际上是插在了最后一个的前面了。
        freeList.push_back(tmp);
        return;
    }
//处理链表中间
    iter = freeList.begin();
    while (iter != freeList.end())
    {
        end = iter->end;
        iter++;
        begin = iter->begin;
        if (end + 1 < r.begin && r.end + 1 < begin)//直接插入链表
        {
            tmp.begin = r.begin;
            tmp.end = r.end;
            freeList.insert(iter, tmp);
            break;
        }
        else if(end + 1 == r.begin && r.end + 1 < begin)//合并左边
        {
            iter--;
            iter->end = r.end;
            break;
        }
        else if(end + 1 < r.begin && r.end + 1 == begin)//合并右边
        {
            iter->begin = r.begin;
            break;
        }
        else if (end + 1 == r.begin && r.end + 1 == begin)//合并两边
        {
            int ed = iter->end;//右边的end
            iter--;
            iter->end = ed;//左边的end扩展到右边的end
            iter++;
            freeList.erase(iter);//删除右边的空闲内存段
            break;
        }
    }
}
