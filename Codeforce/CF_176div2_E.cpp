#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;

int input[1000003];
int main()
{
	int n,t;
	cin >> n;

	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&input[i]);
	
	cin >> t;
	for(i=0;i<t;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		input[tmp] = -input[tmp];
	}

	stack<int> s;
	for(i=n;i>=1;i--)
	{
		if(s.empty())
		{
			if(input[i] > 0)
				input[i] = -input[i];
			s.push(input[i]);
		}
		else
		{
			if(input[i] < 0) s.push(input[i]);
			else
			{
				if(input[i] + s.top() == 0)
					s.pop();
				else
				{
					input[i] = -input[i];
					s.push(input[i]);
				}
			}
		}
	}

	if(s.empty())
	{
		cout << "YES" << endl;
		int i;
		for(i=1;i<=n;i++)
		{
			if(i!=1) cout << " ";
			cout << input[i];
		}
		cout << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
