#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n,m;
	cin >> n >> m;

	int ans = 0;
	while(n <= m)
	{
		n*=3;
		m*=2;
		ans++;
	}

	cout << ans << endl;


	return 0;
}
