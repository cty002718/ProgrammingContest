#include<cstring>
#include<iostream>
#include<sstream>
using namespace std;

int n;
int adj[103][103];
int low[103];
int visit[103];
int ans;
int t;

void dfs(int,int);
int main()
{
	while(cin >> n && n!=0)
	{
		getchar();
		memset(adj,-1,sizeof(adj));
		memset(visit,0,sizeof(visit));
		memset(low,0,sizeof(low));
		while(1)
		{
			string tmp;
			getline(cin,tmp);
			//cout << tmp << endl;
			stringstream ss(tmp);

			int a;
			ss >> a;
			if(a==0)
				break;
			
			int b;
			while(ss >> b)
				adj[a][b] = adj[b][a] = 1;	
		}
		
		t = 0;
		ans = 0;
		dfs(1,1);
		cout << ans << endl;
	}
	
	
	return 0;
}

void dfs(int a, int f)
{
	visit[a] = low[a] = ++t;

	int i;
	int child = 0;
	int ap = 0;
	for(i=1;i<=n;i++)
		if(adj[a][i]!=-1 && i!=f)
		{
			if(visit[i] <= visit[a] && visit[i] && visit[i] <= low[a])
				low[a] = visit[i];
			else if(!visit[i]) 
			{
				child++;
				dfs(i,a);
				
				low[a] = min(low[a],low[i]);
				if(low[i] >= visit[a]) ap = 1;
			}
		}

	if((a == f && child > 1) || (a != f && ap))
		ans++;
}
