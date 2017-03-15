#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int n;
int low[103];
int visit[103];
int which[103];
int t;
int ans;
vector<int> v[103];

void dfs(int,int);
void addedge(int,int);

int main()
{
	int c = 0;
	while(cin >> n && n!=0)
	{
		if(c!=0)
			cout << endl;
		map<string,int> m;
		string rem[103];
		int i;
		for(i=0;i<n;i++)
		{
            v[i].clear();
			cin >> rem[i];
			m[rem[i]] = i;
			//cout << rem[i] << endl;
		}
		
		memset(which,0,sizeof(which));
		memset(visit,0,sizeof(visit));
		int k;
		cin >> k;
		for(i=0;i<k;i++)
		{
			string tmp1,tmp2;
			cin >> tmp1 >> tmp2;
			int a = m[tmp1];
			int b = m[tmp2];
            addedge(a,b);
			//cout << tmp1 << " " << tmp2 << endl;
		}
		
		t = 0;
		ans = 0;
        for(i=0;i<n;i++)
            if(!visit[i])
                dfs(i,i);
		
		vector<string> v2;
		printf("City map #%d: %d camera(s) found\n",++c,ans);
		for(i=0;i<n;i++)
			if(which[i])
				v2.push_back(rem[i]);
		sort(v2.begin(),v2.end());
		for(i=0;i<v2.size();i++)
			cout << v2[i] << endl;
		
	}

	return 0;
}

void addedge(int a, int b)
{
    v[a].push_back(b);
    v[b].push_back(a);
}

void dfs(int a, int f)
{
	visit[a] = low[a] = ++t;

	int i;
	int child = 0;
	int ap = 0;
	for(i=0;i<v[a].size();i++)
		if(v[a][i]!=f)
		{
            int j = v[a][i];
			if(visit[j])
				low[a] = min(low[a],visit[j]);
			else
			{
				child++;
				dfs(j,a);

				low[a] = min(low[a],low[j]);
				if(low[j] >= visit[a]) ap = 1;
			}
		}

	if((a==f && child > 1) || (a!=f && ap))
	{
		ans++;
		which[a] = 1;
	}
}
