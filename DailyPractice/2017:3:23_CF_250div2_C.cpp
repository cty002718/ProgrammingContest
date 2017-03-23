#include<iostream>
using namespace std;

int main()
{
	int v[1003];
	int n,m;
	cin >> n >> m;
	int i;
	for(i=1;i<=n;i++)
		cin >> v[i];
	
	int ans = 0;
	for(i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		int tmp = min(v[a],v[b]);
		ans += tmp;
	}

	cout << ans << endl;

	return 0;
}
