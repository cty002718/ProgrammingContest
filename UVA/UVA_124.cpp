#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

vector<int> G[50];
vector<string> ans;
int c;
int din[50];
int solution[50];
char m2[300];

void dfs(int);

int main()
{
	string input;
	int co=0;
	while(getline(cin,input))
	{
		if(co!=0)
			cout << endl;
		co=1;
		stringstream ss(input);
		char tmp;
		int m[300];
		c=0;
		while(ss >> tmp)
		{
			m[tmp] = c;		
			m2[c++]=tmp;
		}
		int i;
		for(i=0;i<50;i++)
			G[i].clear();
		ans.clear();
		memset(din,0,sizeof(din));
		getline(cin,input);
		stringstream ss2(input);
		int in[50];
		char a;
		while(ss2 >> a)
		{
			char b;
			ss2 >> b;
			//cout << a << b << endl;
			G[m[a]].push_back(m[b]);
			din[m[b]]++;
		}
		/*for(i=0;i<c;i++)
			cout << din[i] << endl;
		*/dfs(0);
		sort(ans.begin(),ans.end());
		for(i=0;i<ans.size();i++)
			cout << ans[i] << endl;
		//cout << endl;
	}

	return 0;
}

void dfs(int n)
{
	if(n==c)
	{
		char tmpans[50];
		int i;
		for(i=0;i<c;i++)
			tmpans[i]=m2[solution[i]];
		tmpans[c]='\0';
		string tmp = tmpans;
		//cout << tmp << endl;
		ans.push_back(tmp);
		return;
	}

	int i;
	for(i=0;i<c;i++)
		if(din[i]==0)
		{
			int j;
			for(j=0;j<G[i].size();j++)
				din[G[i][j]]--;
			solution[n]=i;
			din[i]=-1;
			dfs(n+1);
			din[i]=0;
			for(j=0;j<G[i].size();j++)
				din[G[i][j]]++;
		}

}


