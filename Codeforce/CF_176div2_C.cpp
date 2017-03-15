#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if((n&1) && ((n-1)%4!=0))
	{
		cout << -1 << endl;
		exit(0);
	}
	if((n&1)==0 && (n%4!=0))
	{
		cout << -1 << endl;
		exit(0);
	}
	if(n == 1)
	{
		cout << 1 << endl;
		exit(0);
	}
	if(n < 4)
	{
		cout << -1 << endl;
		exit(0);
	}
	int i;
	int input[100003];
	if(n&1)
	{
		int mid = n/2 + 1;
		int dir = 1;
		for(i=1;i<=n/2;i++)
		{
			if(dir == 1)
			{
				input[mid+i] = i;
				input[mid-i] = n-i+1;
			}
			else
			{
				input[mid+i] = n-i+1;
				input[mid-i] = i;
			}
			dir = -dir;
		}
		input[mid] = mid;
	}
	else
	{
		int left = n/2;
		int right = n/2+1;
		int dir = 1;
		for(i=1;i<=n/2;i++)
		{
			if(dir == 1)
			{
				input[left--] = i;
				input[right++] = n-i+1;
			}
			else
			{
				input[left--] = n-i+1;
				input[right++] = i;
			}
			dir = -dir;
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(i!=1) cout << " ";
		cout << input[i];
	}
	cout << endl;
	return 0;
}
