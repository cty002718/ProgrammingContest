#include<iostream>
#include<cstdio>
using namespace std;

int dfs(int);

int main()
{
	int n;
	while(cin >> n && n!=0)
		cout << dfs(n) << endl;
	return 0;
}

int dfs(int n)
{
	if(n<10)
		return n;
	else
	{
		int sum = 0;
		while(n)
		{
			sum += (n%10);
			n/=10;
		}
		return dfs(sum);
	}
}

