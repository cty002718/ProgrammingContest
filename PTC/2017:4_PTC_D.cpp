#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
using namespace std;

int sum[100003];
int main()
{
	int n;
	while(cin >> n)
	{
		map<int,int> m;
		set<int> s;
		m[100001] = 1000003;
		s.insert(100001);
		int i;
		memset(sum,0,sizeof(sum));
		for(i=0;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			set<int>::iterator iter;
		/*	cout << "hi: ";
			for(iter = s.begin();iter!=s.end();iter++)
				cout << *iter << " ";
			cout << endl;
		*/	iter = s.upper_bound(b);
			m[*iter]--;
			b = *iter;
			if(m[*iter] == 0)
				s.erase(iter);
			sum[a] += 1;
			sum[b] -= 1;
			cout << a << " " << b << endl;
			s.insert(a);
			m[a]++;
			//cout << "ma: " << m[a] << endl;
		}

		for(i=1;i<100003;i++)
			sum[i] += sum[i-1];

		cout << sum[100000] << endl;
	}

	return 0;
}
