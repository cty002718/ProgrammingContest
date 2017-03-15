#include<iostream>
using namespace std;

long long dp[50];
long long e[50];

void dfs(int,int,int,int);
long long c(long long,long long);

int main()
{
	int i;
	int j;
	dp[1]=1;
	dp[2]=1;
	for(i=3;i<=40;i++)
		dfs(1,0,i-1,0);
	
	int n;
	while(cin >> n)
		cout << dp[n] << endl;

	return 0;
}

long long c(long long n,long long m)
{
	int i;
	long long ans=1;
	long long a=min(n,m);

	for(i=1;i<=a;i++)
		ans=ans*(n-i+1)/i;
	
	return ans;
}

void dfs(int a,int step,int num,int sum)
{
	int i,j,k;
	if(sum>num)
		return;
	if(sum==num)
	{
		long long s=1;
		int k=1;
		for(i=1;i<step;i++)
		{
			if(e[i]!=e[i-1])
			{
				s*=c(dp[e[i-1]]+k-1,k);
				k=0;
			}
			k++;
		}
		
		s*=c(dp[e[step-1]]+k-1,k);
		dp[sum+1]+=s;
		return;
	}

	for(i=a;i<=num;i++)
	{
		e[step]=i;
		dfs(i,step+1,num,sum+i);
	}
}
