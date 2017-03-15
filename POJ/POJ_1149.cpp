#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct edge
{
	int to,cap,rev;
};

vector<edge> G[10003];
int level[103];
int iter[103];

void addedge(int,int,int);
void BFS(int);
int DFS(int,int,int);

int main()
{
	int former[1003];
	memset(former,-1,sizeof(former));
	int m,n;
	cin >> m >> n;
	int i;
	int input[1003];
	for(i=1;i<=m;i++)
		cin >> input[i];
	
	for(i=1;i<=n;i++)
	{
		int tmp;
		int num;
		cin >> num;
		int sum=0;
		while(num--)
		{
			cin >> tmp;
			if(former[tmp]==-1)
			{
				sum+=input[tmp];
				former[tmp]=i;
			}
			else
				addedge(former[tmp],i,1e9);
		}

		if(sum!=0)
			addedge(0,i,sum);
		cin >> tmp;
		addedge(i,n+1,tmp);
	}

	int ans=0;
	while(1)
	{
		memset(iter,0,sizeof(iter));
		BFS(0);
		if(level[n+1]==-1)
			break;
		while(1)
		{
			int d=DFS(0,n+1,1e9);
			if(d==0)
				break;
			ans+=d;
		}
	}

	cout << ans << endl;

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
	level[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int a=q.front(); q.pop();
		int i;
		for(i=0;i<G[a].size();i++)
		{
			edge e=G[a][i];
			if(e.cap>0 && level[e.to]<0)
			{
				level[e.to]=level[a]+1;
				q.push(e.to);
			}
		}
	}
}

int DFS(int a,int t,int f)
{
	if(a==t)
		return f;
	
	for(int &i=iter[a];i<G[a].size();i++)
	{
		edge &e=G[a][i];
		if(e.cap>0 && level[e.to]>level[a])
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
