#include<iostream>
using namespace std;

int main()
{
	int k,d;
	cin >> k >> d;

	if(d == 0)
	{
		if(k > 1) cout << "No solution";
		else cout << 0;
	}
	else
	{
		cout << d;
		int i;
		for(i=0;i<k-1;i++)
			cout << 0;
	}
	cout << endl;

	return 0;
}
