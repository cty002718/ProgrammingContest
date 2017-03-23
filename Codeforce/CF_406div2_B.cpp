#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

int main()
{
	int n,m;
	cin >> n >> m;
	int i;
	int suc = 0;
	for(i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		int j;
		map<int,int> m;
		int suc2 = 0;
		for(j=1;j<=tmp;j++)
		{
			int a;
			scanf("%d",&a);
			if(m[-a] == 1)
			{
				suc2 = 1;
			}
			m[a] = 1;
		}

		if(suc2 == 0) suc = 1;
	}

	if(suc) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
