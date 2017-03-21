#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

vector<int> G[100003];
bool have_cat[100003];
int ans = 0;
int m;

void dfs(int,int,int);

int main()
{
	int n;
	cin >> n >> m;
	int i;
	for(i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if(tmp == 1) have_cat[i] = true;
		else have_cat[i] = false;
	}

	for(i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1,-1,0);

	cout << ans << endl;
	return 0;
}

void dfs(int n, int f, int con)
{
	if(have_cat[n] == true) con++;
	else con = 0;
	
	if(con > m) return;
	int i;
	int suc = 0;
	for(i=0;i<G[n].size();i++)
	{
		if(G[n][i] == f) continue;
		dfs(G[n][i],n,con);
		suc = 1;
	}

	if(suc == 0)
		ans++;
}
