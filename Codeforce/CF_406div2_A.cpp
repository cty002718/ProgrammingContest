#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

typedef long long ll;

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	int i,j;
	int suc = 0;
	int ans = 1e9;
	for(i=0;i<=1000;i++)
		for(j=0;j<=1000;j++)
		{
			if(a*i+b == c*j+d)
			{
				suc = 1;
				ans = min(ans,a*i+b);
			}
		}
	
	if(suc) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}


