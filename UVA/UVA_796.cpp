#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[1003];
vector<pair<int,int> > ans;
int low[1003];
int visit[1003];
int t;

void dfs(int,int);

int main()
{
	int n;	
	while(cin >> n)
	{
		int i;
		for(i=0;i<1003;i++)
			v[i].clear();

		memset(low,0,sizeof(low));
		memset(visit,0,sizeof(visit));
		ans.clear();

		for(i=0;i<n;i++)
		{
			int a;
			cin >> a;
			int m;
			scanf(" (%d)",&m);
			int j;
			for(j=0;j<m;j++)
			{
				int c;
				cin >> c;
				//cout << a << " " << c << endl;
				v[a].push_back(c);
			}
		}

		t = 0;
		for(i=0;i<n;i++)
			if(!visit[i])
				dfs(i,i);
		
		sort(ans.begin(),ans.end());
		
		cout << ans.size() << " critical links" << endl;
		for(i=0;i<ans.size();i++)
			cout << ans[i].first << " - " << ans[i].second << endl;
		cout << endl;

	}
	return 0;
}

void dfs(int a, int f)
{
	low[a] = visit[a] = ++t;

	int i;
	for(i=0;i<v[a].size();i++)
	{
		int b = v[a][i];
		if(b == f) continue;
		
		if(visit[b])
			low[a] = min(low[a],visit[b]);
		else
		{
			dfs(b,a);
			low[a] = min(low[a],low[b]);
			
			if(low[b] > visit[a])
			{
				int tmp1 = a;
				int tmp2 = b;
				if(tmp2 < tmp1)
					swap(tmp1,tmp2);
				
				ans.push_back(make_pair(tmp1,tmp2));
			}
		}
	}
}
