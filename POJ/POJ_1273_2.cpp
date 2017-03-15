#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
	int to,cap,rev;
};

vector<edge> G[300];
int level[300];
int iter[300];

void addedge(int,int,int);
void BFS(int);
int DFS(int,int,int);

int main()
{
	int n,m;
	while(cin >> m >> n)
	{
		int i;
        for(i=0;i<300;i++)
            G[i].clear();
		for(i=0;i<m;i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			addedge(a,b,c);
		}
		
		int ans=0;
		while(1)
		{
			BFS(1);
			if(level[n]<0)
				break;
			memset(iter,0,sizeof(iter));
			while(1)
			{
				int d=DFS(1,n,1e9);
				if(d==0)
					break;
				ans+=d;
			}
		}

		cout << ans << endl;
	}

	return 0;
}

void addedge(int a,int b,int c)
{
	G[a].push_back((edge){b,c,G[b].size()});
	G[b].push_back((edge){a,0,G[a].size()-1});
}

void BFS(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> q;
	level[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int a=q.front(); q.pop();
		for(int i=0;i<G[a].size();i++)
		{
			edge &e=G[a][i];
			if(e.cap>0 && level[e.to]<0)
			{
				level[e.to]=level[a]+1;
				q.push(e.to);
			}
		}	
	}
}

int DFS(int n,int t,int f)
{
	if(n==t)
		return f;
	
	for(int &i=iter[n];i<G[n].size();i++)
	{
		edge &e=G[n][i];
		if(e.cap>0 && level[e.to]>level[n])
		{
			int d=DFS(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}

	return 0;
}
