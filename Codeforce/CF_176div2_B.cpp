#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n,k;
	cin >> n >> k;
	if(n == 1){
		cout << 0 << endl;
		exit(0);
	}
	n--;
	ll left = 1, right = k-1;
	while(left < right)
	{
		ll mid = (left + right) / 2;
		ll tmp = (2 * k - 1 - mid) * mid / 2;
		if(tmp >= n)
			right = mid;
		else
			left = mid + 1;
	}

	ll tmp = (2 * k - 1 - right) * right / 2;
	if(tmp >= n) cout << right << endl;
	else cout << -1 << endl;
	return 0;
}
