#include<iostream>
using namespace std;

int main()
{
	long long dp[50][50];
	int i,j;
	for(i=0;i<50;i++)
		dp[1][i]=1;
	for(i=1;i<50;i++)
		dp[i][0]=i;
	for(i=2;i<50;i++)
		for(j=1;j<50;j++)
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]+1;

	int g,l;
	int c=0;
	while(cin >> g >> l && g!=0)
		cout << "Case " << ++c << ": " << dp[g][l] << endl;

	return 0;
}
