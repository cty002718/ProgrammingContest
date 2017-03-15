#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int input1[20005];
int input2[20005];
string s[20005];
int parent[20005];
int din[20005];
int num;

int find(int a)
{
	if(a==parent[a])
		return a;
	return parent[a]=find(parent[a]);
}

void uni(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb)
	{
		parent[fa]=fb;
		num--;
	}
}

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		num=n;
		memset(din,0,sizeof(din));
		int i;
		for(i=0;i<n;i++)
			parent[i]=i;
		
		vector<int> G[20005];

		for(i=0;i<m;i++)
		{
			cin >> input1[i] >> s[i] >> input2[i];
			if(s[i]=="=")
				uni(input1[i],input2[i]);
		}
		
		for(i=0;i<m;i++)
		{
			if(s[i]=="=")
				continue;
			int a1 = find(input1[i]);
			int a2 = find(input2[i]);
			if(s[i]==">")
			{
				G[a2].push_back(a1);
				din[a1]++;
			}
			else
			{
				//cout << a1 << " " << a2 << endl;
				G[a1].push_back(a2);
				din[a2]++;
			}
		}
		
		queue<int> q;
		
		int con=0;
		int un=0;
		for(i=0;i<n;i++)
			if(parent[i]==i && din[i]==0)
				q.push(i);
				
		for(i=0;i<num;i++)
		{
			if(q.size()>1) un=1;
			if(q.empty())
			{
				con=1;
				break;
			}
			
			int a=q.front();q.pop();
			int j;
			for(j=0;j<G[a].size();j++)
				if(parent[G[a][j]]==G[a][j])
				{
					din[G[a][j]]--;
					if(din[G[a][j]]==0)
						q.push(G[a][j]);
				}
		}
	
		if(un!=1 && con!=1)
			cout << "OK" << endl;
		else if(con==1)
			cout << "CONFLICT" << endl;
		else
			cout << "UNCERTAIN" << endl;
	}
	
	return 0;
}
