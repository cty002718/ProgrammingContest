#include<iostream>
using namespace std;

long long dp[2][3000];

int main()
{
	int cost[26][2];
	int n,m;
	string s;
	cin >> m >> n;
	cin >> s;
	int i,j;
	for(i=0;i<26;i++)
		cost[i][0] = cost[i][1] = 1e9;
	for(i=0;i<m;i++)
	{
		string tmp;
		int in,out;
		cin >> tmp;
		cin >> in >> out;
		cost[tmp[0]-'a'][0] = in;
		cost[tmp[0]-'a'][1] = out;
	}

	int state=0;
	for(i=n-1;i>=0;i--)
	{
		dp[1^state][i]=0;
		for(j=i+1;j<n;j++)
			if(s[i]==s[j])
				dp[1^state][j]=dp[state][j-1];
			else
			{
				long long small=1e9;
				small=min(small,dp[state][j]+cost[s[i]-'a'][0]);
				small=min(small,dp[state][j]+cost[s[i]-'a'][1]);
				small=min(small,dp[1^state][j-1]+cost[s[j]-'a'][0]);
				small=min(small,dp[1^state][j-1]+cost[s[j]-'a'][1]);
				dp[1^state][j] = small;
			}

		state^=1;
	}

	cout << dp[state][n-1] << endl;

	return 0;
}
