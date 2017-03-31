#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<cstdio>
using namespace std;

int adj[1003][1003];
char map[1003][13][13];
int main()
{
	int n,m,num,w;
	cin >> n >> m >> num >> w;
	int i,j,k;
	for(k=1;k<=num;k++)
		for(i=0;i<n;i++)
		{
			getchar();
			for(j=0;j<m;j++)
				scanf("%c",&map[k][i][j]);
		}
	
	for(i=1;i<=num;i++)
		for(j=i+1;j<=num;j++)
		{
			int sum = 0;
			int a,b;
			for(a=0;a<n;a++)
				for(b=0;b<m;b++)
					if(map[i][a][b] != map[j][a][b])
						sum++;

			adj[i][j] = adj[j][i] = sum*w;
		}

	for(i=1;i<=num;i++)
		adj[0][i] = adj[i][0] = n*m;
	
	int d[1003];
	bool visit[1003];
	int p[1003];
	memset(visit,false,sizeof(visit));
	for(i=1;i<1003;i++)
	{
		d[i] = n*m;
		p[i] = 0;
	}
	d[0] = 0;
	visit[0] = true;
	
	vector<pair<int,int> > ans;
	int count = num;
	int sum = 0;

	while(count--)
	{
		int small = 1e9;
		int x;
		for(i=1;i<=num;i++)
			if(d[i] <= small && !visit[i])
			{
				small = d[i];
				x = i;
			}

		visit[x] = true;
		sum += d[x];
		ans.push_back(make_pair(x,p[x]));
		for(i=1;i<=num;i++)
			if(adj[x][i] < d[i] && !visit[i])
			{
				d[i] = adj[x][i];
				p[i] = x;
			}
	}
	cout << sum << endl;
	for(i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}
