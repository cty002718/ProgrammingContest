#include<iostream>
#include<cstdio>
using namespace std;

int input[100003];

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

		long long sum=0;
		int ans=1e9;
		int l=0,r=0;
		while(1)
		{
			while(r<n && sum<s)
				sum+=input[r++];
			
			if(sum<s)
				break;

			ans=min(ans,r-l);
			sum-=input[l++];
		}

		if(ans==1e9)
			cout << 0 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
