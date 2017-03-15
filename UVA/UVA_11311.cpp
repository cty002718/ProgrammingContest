#include<iostream>
#include<set>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int num;
	cin >> num;
	while(num--)
	{
		int n,m,r,c;
		cin >> n >> m >> r >> c;
		int ans = r ^ c ^ (n-r-1) ^ (m-c-1);
		if(ans==0)
			cout << "Hansel" << endl;
		else
			cout << "Gretel" << endl;
	}

	return 0;
}
