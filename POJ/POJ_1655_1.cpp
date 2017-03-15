#include<iostream>
#include<cstring>
using namespace std;

int son[20001];
int ans;
int y;
int n;
int adj[20001];
int visit[20002];
int no;
void dfs(int,int);

struct edge
{
    int b;
    int next;
}e[40010];

void addedge(int,int);

int main()
{
    int num;
    cin >> num;
    while(num--)
    {
        cin >> n;
        memset(son,0,sizeof(son));
        memset(adj,-1,sizeof(adj));
        memset(visit,0,sizeof(visit));
        no=0;
        int i;
        for(i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            addedge(a,b);
            addedge(b,a);
        }
        ans=1e9;
        y=1e9;
        dfs(1,-1);
        
        cout << y << " " << ans << endl;
        
    }
    
    return 0;
}

void addedge(int a,int b)
{
    e[no].b = b;
    e[no].next = adj[a];
    adj[a] = no++;
}

void dfs(int a,int fa)
{
    int i;
    son[a]=1;
    int ac=0;
    visit[a] = 1;
    
    for(i=adj[a];i!=-1;i = e[i].next)
    {
        int b = e[i].b;
        if(b==fa)
            continue;
        dfs(b,a);
        son[a]+=son[b];
        if(son[b]>ac)
            ac=son[b];
    }
    ac = max(ac,n-son[a]);
    if(ac <= ans)
    {
        if(ac==ans)
        {
            if(a<y)
                y=a;
        }
        
        else
            y=a;
        
        ans = ac;
    }
    
}