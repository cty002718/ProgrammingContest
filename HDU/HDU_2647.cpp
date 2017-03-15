#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		vector<int> G[10003];
		int i;
		int din[10003];
		memset(din,0,sizeof(din));
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&b,&a);
			G[a].push_back(b);
			din[b]++;
		}
		
		int money[10003];
		memset(money,0,sizeof(money));
		queue<int> q;
		for(i=1;i<=n;i++)
			if(din[i]==0)
			{
				q.push(i);
				money[i]=888;
			}

		ll ans=0;
		int suc=1;
		for(i=0;i<n;i++)
		{
			if(q.empty())
			{
				suc=0;
				break;
			}
			int x=q.front();q.pop();
			ans+=money[x];
			int j;
			for(j=0;j<G[x].size();j++)
			{
				money[G[x][j]]=max(money[G[x][j]],money[x]+1);
				din[G[x][j]]--;
				if(din[G[x][j]]==0)
					q.push(G[x][j]);
			}
			
		}

		if(suc)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
