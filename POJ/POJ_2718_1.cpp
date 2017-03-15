#include<iostream>
#include<sstream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int solution[20];
bool visit[20];
void dfs(int,vector<int>&,vector<int>&);

int main()
{
	int num;
	cin >> num;
	getchar();
	while(num--)
	{
		stringstream ss;
		vector<int> v;
		string a;
		getline(cin,a);
		ss << a;
		while(!ss.eof())
		{
			int tmp;
			ss >> tmp;
			v.push_back(tmp);
		}
		
		int i;
		int ans=1e9;
		for(i=1;i<(1<<v.size())-1;i++)
		{
			vector<int> v1;
			vector<int> v2;
			int j;
			for(j=0;j<v.size();j++)
				if(((i>>j)&1)==0)
					v1.push_back(v[j]);
				else
					v2.push_back(v[j]);
            
            if(v1.size()-v2.size()>1)
                continue;

			vector<int> a1;
			vector<int> a2;
			
			memset(visit,false,sizeof(visit));
			dfs(0,v1,a1);
			memset(visit,false,sizeof(visit));
			dfs(0,v2,a2);
			for(int i=0;i<a1.size();i++)
				for(int j=0;j<a2.size();j++)
					ans=min(ans,max(a1[i],a2[j])-min(a1[i],a2[j]));
				
		}
		cout << ans << endl;
	}
	return 0;
}

void dfs(int n,vector<int> &a,vector<int> &b)
{
	if(n==a.size())
	{
		int i;
		int sum=0;
		for(i=0;i<a.size();i++)
			if(n==1 && i==0 && a[solution[i]]==0)
			{
				b.push_back(0);
				return;
			}
			else if(i==0 && a[solution[i]]==0)
				return;
			else
			{
				sum*=10;
				sum+=a[solution[i]];
			}

		b.push_back(sum);
		return;
	}

	int i;
	for(i=0;i<a.size();i++)
		if(!visit[i])
		{
			visit[i]=true;
			solution[n]=i;
			dfs(n+1,a,b);
			visit[i]=false;
		}
}
