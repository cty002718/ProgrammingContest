#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

char s[100003];
bool mark[100003];
int dp[100003];
vector<int> v[100003];
vector<int> fail;
void build_fail(int);
int dfs(int);


int main()
{
	string input;
	cin >> input;
	int i;	
	for(i=0;i<input.size();i++)
		s[i+1] = input[i];
	build_fail(input.size());	
	int c = input.size();
	int a = c;
	int sum = 0;
	while(a)
	{
		sum++;
		mark[a] = true;
		a = fail[a];
	}
	
	for(i=1;i<=c;i++)
		v[fail[i]].push_back(i);		
	
	cout << sum << endl;
	dfs(0);
	for(i=1;i<=c;i++)
		if(mark[i]) cout << i << " " << dp[i] << endl;
}

int dfs(int n)
{
	int i;
	int sum = 1;
	for(i=0;i<v[n].size();i++)
		sum += dfs(v[n][i]);
	
	if(mark[n]) dp[n] = sum;
	return sum;
}	

void build_fail(int n)
{
	fail.push_back(0);
	fail.push_back(0);
	int i;
	int j = 0;
	for(i=2;i<=n;i++)
	{
		while(j!=0 && s[j+1]!=s[i])
			j = fail[j];
		if(s[j+1] == s[i])
			j++;
		
		//cout << s[j+1] << " " << s[i] << endl;
		fail.push_back(j);
	}
}
