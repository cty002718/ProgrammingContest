#include<iostream>
using namespace std;

int input[2000003];

int main()
{
	int n;
	cin >> n;

	int i,j;
	for(i=1;i<=n;i++)
		input[i] = i;
	
	int now = 1;
	for(i=2;i<=n;i++)
	{
		int pre = input[now];
		int index = now;
		while(index + i <= now + n - 1)
		{
			int tmp = pre;
			pre = input[index + i];
			input[index + i] = tmp;
			index += i;
		}
		input[now + n] = pre;
		now++;
	}	
	
	for(j=now;j<now+n;j++)
	{
		if(j!=now) cout << " ";
		cout << input[j];
	}
	cout << endl;
	
	return 0;
}
