#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int input[100003];

int main()
{
	int n,h,k;
	cin >> n >> h >> k;
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);

	i=0;
	long long sum=0;
	int now=input[0];
	int left=h-input[0];
	for(i=1;i<n;i++)
	{
		int tmp=ceil((double)(input[i]-left)/k);
		if(tmp<0)
			tmp=0;
		sum+=tmp;
		if(h-left-tmp*k<0)
			left=h;
		else
			left+=tmp*k;
		left-=input[i];
		//cout << left << endl;
	}
	int tmp=ceil((double)(h-left)/k);
	
	sum+=tmp;
	cout << sum << endl;
	return 0;
}
