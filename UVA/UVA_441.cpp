#include<iostream>
using namespace std;

int input[20];
int solution[20];
int num;

void dfs(int,int);

int main()
{
	int c = 0;
	while(cin >> num && num!=0)
	{
		if(c!=0)
			cout << endl;
		c = 1;
		int i;
		for(i=0;i<num;i++)
			cin >> input[i];
	
		dfs(0,6);
	}
	return 0;
}

void dfs(int n,int res)
{
	if(n==num)
	{
		if(res!=0)
			return;
		int i;
		int suc = 0;
		for(i=0;i<n;i++)
			if(solution[i])
			{
				if(suc!=0)
					cout << " ";
				suc = 1;
				cout << input[i];
			}
		cout << endl;
		return;
	}

	if(res)
	{
		solution[n] = 1;
		dfs(n+1,res-1);
	}
	solution[n] = 0;
	dfs(n+1,res);
	return;
}


