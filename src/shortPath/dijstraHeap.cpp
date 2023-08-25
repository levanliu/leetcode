#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

constexpr int N = 1e6+5;
int e[N],w[N],h[N],ne[N],idx;
int n,m;
bool st[N];
int dist[N];
typedef pair<int,int> PII;

void add(int a,int b,int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({1,0});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int index = t.first;
        int distance = t.second;

        if(st[index]) continue;
        st[index] = true;

        for (int i = h[index]; i != -1; i=ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[index]+w[i]){
                dist[j] = dist[index]+w[i];
                heap.push({dist[j],j});
            }
        }
        
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
    
}

int main()
{
    cin >> n>> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    cout << dijstra() << endl;
    return 0;
} 