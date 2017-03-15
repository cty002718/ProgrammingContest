#include<iostream>
#include<cstdio>
using namespace std;

int dp[400][400];
int input[400][400];

int main()
{
	int n;
	int i,j;
	cin >> n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%d",&input[i][j]);

	for(i=1;i<=n;i++)	
		for(j=1;j<=i;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+input[i][j];
	
	int ans=0;
	for(i=1;i<=n;i++)
		ans=max(ans,dp[n][i]);
	cout << ans << endl;
	return 0;
}
