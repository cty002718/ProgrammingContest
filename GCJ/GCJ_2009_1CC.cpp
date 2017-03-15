#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[103][103];
int dfs(int,int);
int input[103];

int main()
{
	int c=0;
	int num;
	cin >> num;
	while(num--)
	{
		int p,q;
		int i,j;
		scanf("%d%d",&p,&q);
		for(i=1;i<=q;i++)
			scanf("%d",&input[i]);
		
		input[0]=0;
		input[q+1]=p+1;
		sort(input,input+q+2);
		memset(dp,-1,sizeof(dp));
		cout << "Case #" << ++c << ": " << dfs(0,q+1) << endl;
	}

	return 0;
}

int dfs(int left,int right)
{
	if(dp[left][right]!=-1)
		return dp[left][right];
	if(left+1==right)
		return 0;
	int i;
	int small=1e9;
	for(i=left+1;i<right;i++)
	{
		int sum=0;
		sum+=(input[right]-input[left]-2);
		sum+=dfs(left,i);
		sum+=dfs(i,right);
		small=min(small,sum);
	}
	return dp[left][right]=small;
}
