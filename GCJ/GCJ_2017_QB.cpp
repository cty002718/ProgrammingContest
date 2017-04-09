#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	int T;
	int c = 0;
	int i,j;
	cin >> T;
	while(T--)
	{
		string input;
		cin >> input;

		while(1)
		{
			int suc = 1;
			for(i=0;i<input.size()-1;i++)
				if(input[i] > input[i+1])
				{
					suc = 0;
					input[i]--;
					for(j=i+1;j<input.size();j++)
						input[j] = '9';
				}
			if(suc == 1) break;
		}
		
		printf("Case #%d: ",++c);
		int tmp = 0;
		while(input[tmp] == '0') tmp++;
		for(i=tmp;i<input.size();i++)
			cout << input[i];
		cout << endl;
	}

	return 0;
}
