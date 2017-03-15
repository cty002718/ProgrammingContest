#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m && n!=0)
	{
		vector<int> G[103];
		int din[103];
		memset(din,0,sizeof(din));
		
		int i;
		for(i=0;i<m;i++)
		{
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);
			din[b]++;
		}
		
		queue<int> q;
		for(i=0;i<n;i++)
			if(din[i]==0)
				q.push(i);
	
		int suc=1;
		for(i=0;i<n;i++)
		{
			if(q.empty())
			{
				suc=0;
				break;
			}

			int a=q.front();q.pop();

			int j;
			for(j=0;j<G[a].size();j++)
			{
				din[G[a][j]]--;
				if(din[G[a][j]]==0)
					q.push(G[a][j]);
			}
		}

		if(suc)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	

	return 0;
}
