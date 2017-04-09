#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int C = 0;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		priority_queue<int> q;
		q.push(n);
		
		int b,c;
		while(k--)
		{
			int a = q.top(); q.pop();
			if(a & 1)
				b = c = a/2;
			else
			{
				b = a/2 - 1;
				c = a/2;
			}

			q.push(b);
			q.push(c);
		}	

		printf("Case #%d: %d %d\n",++C,max(b,c),min(b,c));
	}

	return 0;
}
