#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

ll dp[5003][5003];
ll input[5003];

ll solve(int,int);

int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	int i;
	for(i=0;i<n;i++)
		cin >> input[i];		
	
	cout << solve(0,n-1) << endl;
	return 0;
}

ll solve(int left, int right)
{
	if(left > right)
		return 0;
	if(dp[left][right] != -1)
		return dp[left][right];

	int i;
	ll small = 1e9;
	for(i=left;i<=right;i++)
		small = min(small,input[i]);
	
	ll ans = 0;
	ans += small;
	
	int now = left;
	for(i=left;i<=right;i++)
	{
		input[i]-=small;
		if(input[i] == 0)
		{
			ans += solve(now,i-1);
			now = i + 1;
		}
	}
	
	ans += solve(now,right);
	for(i=left;i<=right;i++)
		input[i]+=small;
	
	return dp[left][right] = min(ans,(ll)right-left+1);

}	
