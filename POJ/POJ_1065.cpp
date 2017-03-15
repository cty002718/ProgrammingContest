#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		pair<int,int> p[5003];
		int n;
		int i;
		cin >> n;
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].first,&p[i].second);

		sort(p,p+n);

		vector<int> v;
		v.push_back(p[0].second);
		for(i=1;i<n;i++)
		{
			if(p[i].second<v.back())
				v.push_back(p[i].second);
			else
			{
				int left=-1,right=v.size()-1;
				while(right-left>1)
				{
					int mid=(left+right)/2;
					if(v[mid]>p[i].second)
						left=mid;
					else
						right=mid;
				}
				v[right]=p[i].second;
			}
		}
		
		cout << v.size() << endl;
	}
	return 0;
}
