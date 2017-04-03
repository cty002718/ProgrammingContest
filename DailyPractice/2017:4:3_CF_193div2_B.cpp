#include<iostream>
using namespace std;

typedef long long ll;

int input[200003];
ll sum[200003];
pair<ll,int> big[200003];

int main()
{
	int n,k;
	cin >> n >> k;
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	for(i=0;i<k;i++)
		sum[0] += input[i];
	for(i=k;i<n;i++)
		sum[i-k+1] = sum[i-k] - input[i-k] + input[i];
	
	big[n-k].first = sum[n-k];
	big[n-k].second = n-k;
	for(i=n-k-1;i>=0;i--)
	{
		big[i] = big[i+1];
		if(big[i].first <= sum[i])
		{
			big[i].first = sum[i];
			big[i].second = i;
		}
	}

	ll ans = 0;
	int x,y;
	for(i=0;i<n-k+1;i++)
	{
		if(ans < sum[i] + big[i+k].first)
		{
			x = i;
			y = big[i+k].second;
			ans = sum[i] + big[i+k].first;
		}
	}

	cout << x+1 << " " << y+1 << endl;
	return 0;
}
