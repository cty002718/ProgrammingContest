#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int input[80003];
	int stack[80003];
	int top = 0;
	int i;

	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	long long sum = 0;
	for(i=n-1;i>=0;i--)
	{
		while(top > 0 && input[stack[top-1]] < input[i])
			top--;

		int tmp = top==0?n:stack[top-1];
		sum += (tmp-i-1);
		stack[top++] = i;
	}
	
	cout << sum << endl;
	return 0;
}
