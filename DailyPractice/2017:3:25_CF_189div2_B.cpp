#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct seg
{
	int index,l,r;
};

vector<seg> v;
vector<int> G[103];

int dfs(int,int);
int visit[103];

int main()
{
	int n;
	cin >> n;
	int i;
	int co = 0;
	for(i=0;i<n;i++)
	{
		int k;
		int a,b,c;
		cin >> a >> b >> c;
		if(a==1)
		{
			co++;
			int j;
			for(j=0;j<v.size();j++)
			{
				int tmpl = v[j].l;
				int tmpr = v[j].r;
				int tmpindex = v[j].index;
				//cout << tmpindex << " " << tmpl << " " << tmpr << endl;
				if((tmpl < c && tmpl > b) || (tmpr < c && tmpr > b))
					G[tmpindex].push_back(co);
				if((b < tmpr && b > tmpl) || (c < tmpr && c > tmpl))
					G[co].push_back(tmpindex);
			}
			v.push_back((seg){co,b,c});
		}
		else
		{
			memset(visit,0,sizeof(visit));
			if(dfs(b,c))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}

int dfs(int a, int obj)
{
	if(visit[a]) return 0;
	visit[a] = 1;
	if(a == obj) return 1;
	int i;
	for(i=0;i<G[a].size();i++)
		if(dfs(G[a][i],obj))
			return 1;
	
	return 0;
}
