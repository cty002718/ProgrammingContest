#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		int i;
		int din[503];
		memset(din,0,sizeof(din));
		vector<int> G[503];
		for(i=0;i<m;i++)
		{
			int a,b;
			cin >> a >> b;
			G[a].push_back(b);	
			din[b]++;
		}
		
		priority_queue<int,vector<int>,greater<int> > q;
		for(i=1;i<=n;i++)
			if(din[i]==0)
				q.push(i);

		int j;
		for(i=0;i<n;i++)
		{
			int x=q.top();q.pop();
		
			if(i!=0)
				cout << " ";
			cout << x;
			
			for(j=0;j<G[x].size();j++)
			{
				din[G[x][j]]--;
				if(din[G[x][j]]==0)
					q.push(G[x][j]);
			}
		}
		cout << endl;
	}
	return 0;
}
