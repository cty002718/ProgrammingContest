#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	while(cin >> n && n!=0)
	{
		priority_queue<int,vector<int>,greater<int> > q;
		int i;
		for(i=0;i<n;i++)
		{
			int tmp;
			cin >> tmp;
			q.push(tmp);
		}

		int ans = 0;
		while(q.size() >= 2)
		{
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			ans += (a + b);
			q.push(a+b);
		}

		cout << ans << endl;
	}
	return 0;
}
