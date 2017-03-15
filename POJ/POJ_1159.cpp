#include<iostream>
using namespace std;

int dp[2][5003];

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;

	int i,j;
	int state=0;
	for(i=n-1;i>=0;i--)
	{
		dp[1^state][i]=0;
		for(j=i+1;j<n;j++)
			if(s[i]==s[j])
				dp[1^state][j]=dp[state][j-1];
			else
				dp[1^state][j]=min(dp[state][j],dp[1^state][j-1])+1;

		state^=1;
	}

	cout << dp[state][n-1] << endl;
	return 0;
}
