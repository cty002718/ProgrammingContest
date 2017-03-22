#include<iostream>
using namespace std;

typedef long long ll;

ll toy[100003];
ll sum[100003];

int main()
{
	ll take[2];
	ll spend[2];
	ll n;
	cin >> n >> take[0] >> take[1] >> spend[0] >> spend[1];

	int i;
	for(i=1;i<=n;i++)
		scanf("%lld",&toy[i]);
	
	for(i=1;i<=n;i++)
		sum[i] = sum[i-1] + toy[i];

	int now = 0;
	ll ans1 = 1e15;
	ll ans2 = 0;
	int left = 1;
	int right = n;
	while(left <= right)
	{
		if(now == 0)
		{
			ans2 += take[now] * toy[left];
			ans1 = min(ans1, ans2 + (sum[right]-sum[left])*take[0]+spend[0]*(right-left));
			now = 1;
			left++;
		}
		else
		{
			ans2 += take[now] * toy[right];
			ans1 = min(ans1,ans2+(sum[right-1]-sum[left-1])*take[1]+spend[1]*(right-left));
			right--;
			now = 0;
		}

	//	cout << left << " " << right << " " << ans1 << " " << ans2 << endl;
	}

	now = 1;
	ll ans3 = 1e15;
	ll ans4 = 0;
	left = 1;
	right = n;
	
	while(left <= right)
	{
		if(now == 0)
		{
			ans4 += take[now] * toy[left];
			ans3 = min(ans3, ans4 + (sum[right]-sum[left])*take[0]+spend[0]*(right-left));
			now = 1;
			left++;
		}
		else
		{
			ans4 += take[now] * toy[right];
			ans3 = min(ans3,ans4+(sum[right-1]-sum[left-1])*take[1]+spend[1]*(right-left));
			right--;
			now = 0;
		}

	//	cout << left << " " << right << " " << ans1 << " " << ans2 << endl;
	}
	cout << min(min(min(ans1,ans2),ans3),ans4) << endl;
	return 0;
}
