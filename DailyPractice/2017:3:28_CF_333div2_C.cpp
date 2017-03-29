#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int adj[403][403];

int main()
{
	int n,m;
	cin >> n >> m;
	int i,j;
	int suc = 1;
	memset(adj,0,sizeof(adj));
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a][b] = adj[b][a] = 1;
		if(a == 1 && b == n)
			suc = 0;
		if(a == n && b == 1)
			suc = 0;
	}

	queue<pair<int,int> > q;
	q.push(make_pair(1,0));
	bool visit[403];
	memset(visit,false,sizeof(visit));
	visit[1] = true;
	int ans = 0;
	while(!q.empty())
	{
		pair<int,int> tmp = q.front();
		if(tmp.first == n)
		{
			ans = tmp.second;
			break;
		}
		q.pop();
		int i;
		for(i=1;i<=n;i++)
		{
			if(tmp.first == i) continue;
			if(adj[tmp.first][i] == suc && visit[i] == false)
			{
				visit[i] = true;
				q.push(make_pair(i,tmp.second+1));
			}
		}
	}

	if(ans == 0) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
