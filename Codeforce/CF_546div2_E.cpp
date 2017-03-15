#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

// 表示邊的結構（目標，容量，相反邊）
struct edge { int to, cap, rev; };
int residual[1000][1000];

vector<edge> G[1000]; // 圖的相鄰串列表現方式
int level[1000];      // 到 t 的距離
int iter[1000];       // 調查到哪裡了呢，在此之前的邊已無作用

void addedge(int from, int to, int cap);
int max_flow(int s, int t);
int dfs(int v, int t, int f);
void bfs(int s);

int main()
{
    int n,m;
    cin >> n >> m;
    
    memset(residual,-1,sizeof(residual));
    int init[1000];
    int after[1000];
    int i;
    int sum1=0,sum2=0;
    for(i=1;i<=n;i++)
    {
        cin >> init[i];
        addedge(0,i,init[i]);
        sum1+=init[i];
    }
    for(i=1;i<=n;i++)
    {
        cin >> after[i];
        addedge(i+n,2*n+1,after[i]);
        sum2+=after[i];
    }
    
    for(i=1;i<=n;i++)
        addedge(i,i+n,init[i]);
    
    for(i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        addedge(a,b+n,init[a]);
        addedge(b,a+n,init[b]);
    }
    
    int f = max_flow(0,2*n+1);
	
//	cout << f << endl;
    if(sum1!=sum2)
        cout << "NO" << endl;
    else
    {
        if(f!=sum1)
            cout << "NO" << endl;
        else
        {
			cout << "YES" << endl;
            int j;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(j!=1)
                        cout << " ";
                    if(residual[i][j+n]==-1)
                        cout << "0";
                    else
                        cout << init[i]-residual[i][j+n];
                }
                cout << endl;
            }
        }
    }
	
//	cout << sum1 << " " << sum2 << endl;
	return 0;
}

// 將從 from 到 to 且容量為 cap 的邊新增至途中
void addedge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
    residual[from][to] = cap;
}
              
// 以 BFS 計算到 t 的最短距離
void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

// 以 DFS 尋找增加路徑
int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                residual[v][e.to]-=d;
                residual[e.to][v]+=d;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// 求取從 s 到 t 的最大流量
int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, 1e9)) > 0) {
            flow += f;
        }
    }
}


              

