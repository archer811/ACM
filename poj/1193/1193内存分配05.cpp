#include
#include
#include
using namespace std;
struct ITEM
{
    int begin;
    int end;
};
struct running//�����е��ڴ�
{
    int id;//���ڲ���
    int begin;
    int end;
    int releaseT;
    bool operator<(const running& r) const//����С�ڷ��ţ��Դ��ڵĹ���ȥ��С��
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
list freeList;//��������ڴ������
queue waitQueue;//�ȴ�����
priority_queue runQueue;//����С����
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
        //���ͷ��ڴ棬�ٷ���ȴ������еĽ��̣������ǰ������
        while (!runQueue.empty() && runQueue.top().releaseT <= T)
        {
            releaseAllocate();
        }
        if (!AllocateMem(T, M, P, id))//����ǰ����Ľ��̷����ڴ�
        {
            waitSum++;
            waiting tmp;
            tmp.memory = M;
            tmp.spendT = P;
            tmp.id = id;
            //cout << T << "  ����ȴ����У�" << id << endl;
            waitQueue.push(tmp);
        }
        time = T;
    }
    while (!(runQueue.empty() && waitQueue.empty()))//��ͬʱΪ��
    {
        if (!runQueue.empty())//�ͷ��������еĽ���
        {
            releaseAllocate();
        }
    }
    cout << time << endl << waitSum << endl;
    return 0;
}

//�ͷ������еĽ��̺�Ϊ�ȴ����з���
void releaseAllocate()
{
    int timeTmp = time = runQueue.top().releaseT;
    while (time == timeTmp && !runQueue.empty())//��ʾ����ͬһʱ��
    {
        //cout << time  << "  " << runQueue.top().begin << "---" << runQueue.top().end
        // << "  �ͷ�" << runQueue.top().id << endl;
        ReleaseMem(runQueue.top());
        runQueue.pop();
        if (!runQueue.empty())
        {
            timeTmp = runQueue.top().releaseT;//Ҫ��ĳ��ʱ�̶��ϸ��ͷŵ��ͷ���Ÿ��ȴ����з���
        }
    }
    AllocateForWaitQ(time);
}
//���ȴ����з����ڴ�
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

//�����ڴ�
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
            runQueue.push(tmp);//��������ʱ�����ȼ�������
            if (sizeFreeM == Mem)
            {
                freeList.erase(iter);
            }
            else
            {
                iter->begin = tmp.end + 1;//�޸Ŀ����ڴ�����
            }
            //cout << now << "  " << tmp.begin << "---" << tmp.end << "  ����"  << id << endl;
            return true;
        }
        else
        {
            iter++;
        }
    }
    return false;
}

//�ͷ��ڴ�
void ReleaseMem(running& r)
{
    int begin, end;
    ITEM tmp;
//�����������Ϊ����ֱ�Ӳ���������
    if (freeList.empty())
    {
        tmp.begin = r.begin;
        tmp.end = r.end;
        freeList.push_front(tmp);
        return;
    }
//��������ͷ
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
//��������β
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
        //freeList.insert(iter, tmp);//���󴦣�����Ϊ�������һ��λ���ϣ�ʵ�����ǲ��������һ����ǰ���ˡ�
        freeList.push_back(tmp);
        return;
    }
//���������м�
    iter = freeList.begin();
    while (iter != freeList.end())
    {
        end = iter->end;
        iter++;
        begin = iter->begin;
        if (end + 1 < r.begin && r.end + 1 < begin)//ֱ�Ӳ�������
        {
            tmp.begin = r.begin;
            tmp.end = r.end;
            freeList.insert(iter, tmp);
            break;
        }
        else if(end + 1 == r.begin && r.end + 1 < begin)//�ϲ����
        {
            iter--;
            iter->end = r.end;
            break;
        }
        else if(end + 1 < r.begin && r.end + 1 == begin)//�ϲ��ұ�
        {
            iter->begin = r.begin;
            break;
        }
        else if (end + 1 == r.begin && r.end + 1 == begin)//�ϲ�����
        {
            int ed = iter->end;//�ұߵ�end
            iter--;
            iter->end = ed;//��ߵ�end��չ���ұߵ�end
            iter++;
            freeList.erase(iter);//ɾ���ұߵĿ����ڴ��
            break;
        }
    }
}
