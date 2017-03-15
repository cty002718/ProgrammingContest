#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;

int input[1000003];

int main()
{
	int i;
	int n;

	cin >> n;
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	set<int> s;
	for(i=0;i<n;i++)
		s.insert(input[i]);
	int num=s.size();
	
	int sum=0;
	int ans=1e9;
	int l=0,r=0;
	map<int,int> m;
	while(1)
	{
		while(r<n && sum<num)
			if(m[input[r++]]++==0)
				sum++;

		if(sum<num)
			break;
		ans=min(ans,r-l);
		if(m[input[l++]]--==1)
			sum--;
	}

	cout << ans << endl;
	return 0;
}
