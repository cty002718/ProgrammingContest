#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int num;
	int c=0;
	cin >> num;
	while(num--)
	{
		int n;
		cin >> n;
		int i;
		int input1[1000];
		int input2[1000];
		for(i=0;i<n;i++)
			cin >> input1[i];
		for(i=0;i<n;i++)
			cin >> input2[i];
		sort(input1,input1+n);
		sort(input2,input2+n);

		long long sum=0;
		for(i=0;i<n;i++)
			sum+=((long long)input1[i]*input2[n-i-1]);

		cout << "Case #" << ++c << ": " << sum << endl;
	}

	return 0;
}
