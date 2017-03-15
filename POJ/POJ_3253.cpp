#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin >> n;

	priority_queue<ll,vector<ll>,greater<ll> > q;
	int i;
	ll tmp;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&tmp);
		q.push(tmp);
	}

	long long ans=0;
	while(q.size()>1)
	{
		long long a=q.top();q.pop();
		long long b=q.top();q.pop();
		long long c=a+b;
		q.push(c);
		ans+=c;
	}

	cout << ans << endl;
		

	return 0;
}
