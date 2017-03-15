#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

void dfs(int,int);
int r[300][300];

int main()
{
	int n,p;
	int c = 0;
	while(cin >> n >> p && n!=0 && p!=0)
	{
		int i;
		int input[300];
		for(i=1;i<=n;i++)
			cin >> input[i];

		int dp[300][300];
		int num[300][300];
		memset(dp,0,sizeof(dp));
		memset(r,0,sizeof(r));
		for(i=1;i<=n;i++)
			dp[0][i] = 1e9;
		cout << "Chain " << ++c << endl;

		int j;
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
			{
				int mid = (i+j)/2;		
				int sum = 0;
				int k;
				for(k=i;k<=j;k++)
					sum+=abs(input[k]-input[mid]);

				num[i][j] = sum;
			}

		for(i=1;i<=p;i++)
			for(j=1;j<=n;j++)
			{
				int k;
				int m = 1e9;
				for(k=i-1;k<=j-1;k++)
					if(m > dp[i-1][k] + num[k+1][j])
					{
						m = dp[i-1][k] + num[k+1][j];
						r[i][j] = k;
					}

				dp[i][j] = m;
				//cout << i << " " << j << ":" << m << endl;
			}

		dfs(n,p);	
	
		cout << "Total distance sum = " << dp[p][n] << endl;
		cout << endl;
	}

	return 0;
}

void dfs(int n,int level)
{
	if(level == 0)
		return;
	
	dfs(r[level][n],level-1);
	
	printf("Depot %d at restaurant %d serves restaurant",level,(n+r[level][n]+1)/2);
	if(n == r[level][n]+1)
		cout << " " << n << endl;
	else
		cout << "s " << r[level][n]+1 << " to " << n << endl;
}
