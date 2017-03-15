#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct edge
{
	int to,flow,rev;
};

vector<edge> G[300];
bool used[300];

void addedge(int,int,int);
int getflow(int,int,int);

int main()
{
	int m,n;
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
			memset(used,false,sizeof(used));
			int tmp=getflow(1,n,1e9);
			ans+=tmp;
			if(tmp==0)
				break;
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

int getflow(int n,int t,int f)
{
	if(n==t)
		return f;
	if(used[n])
		return 0;
	used[n]=true;
	
	int i;
	for(i=0;i<G[n].size();i++)
	{
		edge tmp=G[n][i];
		if(tmp.flow==0)
			continue;
		int d=getflow(tmp.to,t,min(f,tmp.flow));
		if(d>0)
		{
			G[n][i].flow-=d;
			G[G[n][i].to][G[n][i].rev].flow+=d;
			return d;
		}
	}

	return 0;
}
