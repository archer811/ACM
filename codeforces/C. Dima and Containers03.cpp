#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
const int INF = 1000000007;

int a[100005],v[100005];

const char* tag[]= {"Stack","Queue","Front"};

int main()
{
    int n,cnt[3]= {};
    scanf("%d",&n);
    priority_queue<PII> q;
    for(int i=0; i<n; i++) scanf("%d",a+i);
    for(int i=0; i<n; i++) if(!a[i])
        {
            if(q.size()) v[q.top().second]=1,q.pop();
            if(q.size()) v[q.top().second]=1,q.pop();
            if(q.size()) v[q.top().second]=1,q.pop();
            //q=priority_queue<PII>();
            while(q.size())q.pop();
        }
        else
        {
            q.push(PII(a[i],i));
        }
    for(int i=0; i<n; i++) if(!a[i])
        {
            string ans;
            for(int x=0; x<3; x++) if(cnt[x]>0)
                {
                    cnt[x]--;
                    ans+=" pop";
                    ans+=tag[x];
                }
            printf("%d%s\n",ans.size()/9,ans.c_str());
        }
        else
        {
            if(!v[i])
            {
                puts("pushBack");
            }
            else
            {
                int x=min_element(cnt,cnt+3)-cnt;
                cnt[x]++;
                printf("push%s\n",tag[x]);
            }
        }
}
