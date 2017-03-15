#include<iostream>
using namespace std;

char map[4][4];
bool val();

int main()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		string tmp;
		cin >> tmp;
		for(j=0;j<tmp.size();j++)
			map[i][j] = tmp[j];
	}
	
	int suc = 0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(map[i][j] == '#')
			{
				map[i][j] = '.';
				if(val())
					suc = 1;
				map[i][j] = '#';
			}
			if(map[i][j] == '.')
			{
				map[i][j] = '#';
				if(val())
					suc = 1;
				map[i][j] = '.';
			}
		}
	
	if(suc) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

bool val()
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(map[i][j] == map[i][j+1] && 
				map[i][j+1] == map[i+1][j+1] &&
				map[i+1][j+1] == map[i+1][j])
					return true;
		}
	
	return false;
}
