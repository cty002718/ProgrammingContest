#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int input[100003];
long long sum[100003];

int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		int n,s;
		int i;
		cin >> n >> s;
		for(i=0;i<n;i++)
			scanf("%d",&input[i]);

		memset(sum,0,sizeof(sum));
		
		for(i=0;i<n;i++)
			sum[i+1]=input[i]+sum[i];
		
		int ans=1e9;
		for(i=0;sum[i]+s<=sum[n];i++)
		{
			int tmp=lower_bound(sum,sum+n+1,sum[i]+s) - sum;
			tmp-=i;
			ans=min(ans,tmp);
		}

		if(ans==1e9)
			cout << 0 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
