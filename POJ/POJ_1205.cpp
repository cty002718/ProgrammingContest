#include<iostream>
using namespace std;

long long dp[101];

int main()
{
	int i,j;
	dp[1]=1;
	dp[2]=3;
	dp[3]=8;
	for(i=4;i<=100;i++)
		dp[i]=3*dp[i-1]-dp[i-2];
	int tmp;
	while(cin >> tmp)
		cout << dp[tmp] << endl;
}
