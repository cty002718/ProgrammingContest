#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	string input;
	cin >> input;

	int num = 0;
	int i;
	for(i=0;i<input.size()/2;i++)
		if(input[i] != input[input.size() - i - 1])
			num++;
	
	if(input.size() % 2 == 0)
	{
		if(num == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else
	{
		if(num == 0 || num == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
