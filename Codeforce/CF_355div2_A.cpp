#include<iostream>
using namespace std;

int main()
{
	int n,h;
	cin >> n >> h;
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	{
		int tmp;
		cin >> tmp;
		if(tmp>h)
			sum+=2;
		else
			sum++;
	}

	cout << sum << endl;

	return 0;
}
