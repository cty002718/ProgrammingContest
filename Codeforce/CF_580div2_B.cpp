#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

int main()
{
	ll n,m;
	cin >> n >> m;
	
	pair<ll,ll> p[100003];
	ll sum[100003];
	memset(sum,0,sizeof(sum));
	int i;
	for(i=1;i<=n;i++)
		cin >> p[i].first >> p[i].second;	
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++)
		sum[i] = sum[i-1] + p[i].second;

	int left = 1;
	int right = 1;
	ll ans = 0;
	while(left<=n)
	{
		while(p[right].first - p[left].first < m && right <= n)
			right++;
		ans = max(ans,sum[right-1]-sum[left-1]);
		//cout << left << " " << right << " " << ans << endl;
		left++;
	}

	cout << ans << endl;
	return 0;
}
