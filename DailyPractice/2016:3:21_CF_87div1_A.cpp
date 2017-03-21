#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

vector<int> G[2003];

int dfs(int);

int main()
{
	int n;
	cin >> n;
	int i;
	for(i=1;i<=n;i++)
	{
		int tmp;
		cin >> tmp;
		if(tmp!=-1) G[tmp].push_back(i);
	}
	
	int ans = 0;
	for(i=1;i<=n;i++)
		ans = max(ans,dfs(i));

	cout << ans << endl;

	return 0;
}

int dfs(int n)
{
	int height = 1;
	int i;
	for(i=0;i<G[n].size();i++)
		height = max(height,dfs(G[n][i])+1);
	return height;
}
