#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef long long ll;

int main()
{
	int T;	
	int c = 0;
	cin >> T;
	while(T--)
	{
		string input;
		cin >> input;
		list<char> l;
		int i;
		l.push_front(input[0]);
		for(i=1;i<input.size();i++)
			if(input[i] >= l.front()) l.push_front(input[i]);
			else l.push_back(input[i]);

		printf("Case #%d: ",++c);
		for(list<char>::iterator i = l.begin();i!=l.end();i++)
			printf("%c",*i);
		puts("");
	}
	return 0;
}
