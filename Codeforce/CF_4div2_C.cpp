#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string,int> m;

	int i;
	for(i=0;i<n;i++)
	{
		string tmp;
		cin >> tmp;
		if(m[tmp]==0)
			cout << "OK" << endl;
		else
			cout << tmp << m[tmp] << endl;

		m[tmp]++;
	}

	return 0;
}
