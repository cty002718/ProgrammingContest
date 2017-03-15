#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct oil
{
	int dis;
	int fuel;
}o[10003];

int compare(oil a,oil b)
{
	return a.dis < b.dis;
}

int main()
{
	int n;
	int p,l;
	cin >> n;
	int i;
	for(i=0;i<n;i++)
		cin >> o[i].dis >> o[i].fuel;
	
	cin >> l >> p;
	for(i=0;i<n;i++)
		o[i].dis = l - o[i].dis;
	
	sort(o,o+n,compare);

	priority_queue<int> q;
	o[n].dis = l;
	o[n].fuel = 0;

	int ans=0;
	for(i=0;i<=n;i++)
	{
		while(p < o[i].dis)
		{
			if(q.empty())
			{
				cout << -1 << endl;
				return 0;
			}

			p+=q.top();
			q.pop();
			ans++;
		}
		
		q.push(o[i].fuel);
	}

	cout << ans << endl;
	return 0;
}
