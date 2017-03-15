#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void build_fail(string &s);
vector<int> fail;
stack<pair<int,int> > ans;
int num[100003];

int main()
{
	string input;
	cin >> input;
	build_fail(input);

	int i;
	for(i=0;i<input.size();i++)
		cout << fail[i] << " ";
	cout << endl;
	for(i=0;i<input.size();i++)
		num[fail[i]+1]++;		
	
	ans.push(make_pair(input.size(),1));
	int now = input.size() - 1;
	
	int sum = 0;
	while(fail[now] != -1)
	{
		int tmp = sum + num[fail[now]+1];
		sum += tmp;
		ans.push(make_pair(fail[now]+1, tmp+1));
		now = fail[now];
	}
	
	cout << ans.size() << endl;
	while(!ans.empty())
	{
		printf("%d %d\n",ans.top().first,ans.top().second);
		ans.pop();
	}
	return 0;
}

void build_fail(string &s)
{
	fail.push_back(-1);
	int i;
	int j = -1;
	for(i=1;i<s.size();i++)
	{
		while(j!=-1 && s[j+1]!=s[i])
			j = fail[j];
		if(s[j+1] == s[i])
			j++;
		fail.push_back(j);
	}
}
