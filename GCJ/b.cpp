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
using namespace std;

typedef long long ll;

int main()
{
	int T;	
	int c = 0;
	cin >> T;
	while(T--)
	{
		int num[2503];
		memset(num,0,sizeof(num));
		int n;
		cin >> n;
		int i,j;
		for(i=0;i<2*n-1;i++)
			for(j=0;j<n;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				num[tmp]++;
			}

		vector<int> v;
		for(i=0;i<2503;i++)
			if(num[i] & 1) v.push_back(i);

		sort(v.begin(),v.end());
		printf("Case #%d:",++c);
		for(i=0;i<v.size();i++)
			cout << " " << v[i];
		cout << endl;
	}
	return 0;
}
