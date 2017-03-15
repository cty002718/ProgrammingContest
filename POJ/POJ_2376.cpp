#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

pair<int,int> p[25001];

int main()
{
	int n,t;
	cin >> n >> t;
	int i;
	for(i=0;i<n;i++)
		scanf("%d%d",&p[i].first,&p[i].second);
	
	sort(p,p+n);
	int now=0;
	int right=0;
	int c=1;
	for(i=0;i<n && right<t;i++)
		if(p[i].first <= now+1)
			right=max(right,p[i].second);
		else
		{
			now=right;
			c++;
			if(p[i].first<=now+1)
				right=max(right,p[i].second);
		}

	if(right>=t)
		cout << c << endl;
	else
		cout << -1 << endl;

	return 0;
}
