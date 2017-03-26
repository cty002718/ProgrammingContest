#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;

vector<int> G[26];
bool visit[26];
int in[26];

int main()
{
	int n;
	cin >> n;
	int i;
	string input[103];
	for(i=0;i<n;i++)
		cin >> input[i];
	
	for(i=0;i<n-1;i++)
	{
		string tmp1 = input[i];
		string tmp2 = input[i+1];

		int j;
		int size = min(tmp1.size(),tmp2.size());
		int suc = 0;
		for(j=0;j<size;j++)
		{
			if(tmp1[j] != tmp2[j])
			{
				G[tmp1[j]-'a'].push_back(tmp2[j]-'a');
				in[tmp2[j]-'a']++;
				suc = 1;
				break;
			}
		}
		if(suc == 0 && tmp1.size() > tmp2.size())
		{
			cout << "Impossible" << endl;
			exit(0);
		}
	}
	
	queue<int> q;
	for(i=0;i<26;i++)
		if(in[i] == 0)
		{
			visit[i] = true;
			q.push(i);
		}		
	
	vector<int> ans;
	for(i=0;i<26;i++)
	{
		if(q.empty())
		{
			cout << "Impossible" << endl;
			exit(0);
		}
		int a = q.front();
		ans.push_back(a);
		q.pop();
		int j;
		for(j=0;j<G[a].size();j++)
		{
			in[G[a][j]]--;
			if(in[G[a][j]] == 0 && visit[G[a][j]] == false)
			{
				visit[G[a][j]] = true;
				q.push(G[a][j]);
			}
		}
	}

	for(i=0;i<26;i++)
		printf("%c",ans[i]+'a');
	cout << endl;
	

	return 0;
}
