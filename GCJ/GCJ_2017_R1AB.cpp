#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

typedef long long ll;

int main()
{
	int T;	
	int c = 0;
	cin >> T;
	while(T--)
	{
		int n,p;
		cin >> n >> p;
		double weight[53];
		int i,j;
		for(i=1;i<=n;i++)
			cin >> weight[i];

		vector<double> v[53];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=p;j++)
			{
				double tmp;
				cin >> tmp;
				v[i].push_back(tmp);
			}
		}

		for(i=1;i<=n;i++)
			sort(v[i].begin(), v[i].end());

		int start[53];
		for(i=1;i<=n;i++)
			start[i] = 0;
		
		int ans = 0;
		while(1)
		{
			int s = 0;
			for(i=1;i<=n;i++)
				if(start[i] >= p)
				{
					s = 1;
					break;
				}
			if(s == 1) break;
			int left = 0, right = 1e6;
			int everright[53];
			for(i=1;i<=n;i++)
			{
				double tmp = v[i][start[i]] / weight[i];
				int tmpl = ceil(tmp*10/11);
				int tmpr = floor(tmp*10/9);
				everright[i] = tmpr;

				left = max(left, tmpl);
				right = min(right, tmpr);
			}
			
			if(left <= right)
			{
				ans++;
				for(i=1;i<=n;i++)
					start[i]++;
			}
			else
			{
				for(i=1;i<=n;i++)
				{
					if(everright[i] == right)
						start[i]++;
				}
			}

		}

		printf("Case #%d: %d\n",++c,ans);
	}
	return 0;
}
