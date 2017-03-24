#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> G[203];
map<string,int> m;

int dfs(int);

int main()
{
	int n;
	cin >> n;
	
	int co = 2;
	m["polycarp"] = 1;
	int i;
	for(i=0;i<n;i++)
	{
		string a,b,c;
		cin >> a >> b >> c;

		int j;
		for(j=0;j<a.size();j++)
			a[j] = tolower(a[j]);
		for(j=0;j<c.size();j++)
			c[j] = tolower(c[j]);

		if(m[a] == 0) m[a] = co++;
		if(m[c] == 0) m[c] = co++;
		
		G[m[c]].push_back(m[a]);
	}
	
	cout << dfs(1) << endl;
	return 0;
}

int dfs(int n)
{
	int i;
	int height = 1;
	for(i=0;i<G[n].size();i++)
	{
		height = max(height,dfs(G[n][i])+1);
	}

	return height;
}


