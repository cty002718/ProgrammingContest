#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int i;
		pair<double,double> input[103];
		for(i=0;i<n;i++)
			cin >> input[i].first >> input[i].second;
		
		sort(input,input+n);
		int high = 0;
		double ans = 0;
		for(i=n-2;i>=0;i--)
			if(input[i].second > high)
			{
				double x = input[i].first - input[i+1].first;
				double y = input[i].second - input[i+1].second;
				double len1 = input[i].second - input[i+1].second;
				double len2 = input[i].second - high;
				double length = sqrt(x*x+y*y);

				ans += length*(len2/len1);	
				high = input[i].second;
			}
		
		printf("%.2lf\n",ans);
	}
	return 0;
}
