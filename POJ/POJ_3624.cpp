#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int w[4000];
int v[4000];
int dp[13000];

int main()
{
	int n,m;
	int i,j;
	cin >> n >> m;
	
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
		scanf("%d%d",&w[i],&v[i]);
		
	for(i=0;i<n;i++)
		for(j=m;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
   
	cout << dp[m] << endl;
	
	return 0;
}
