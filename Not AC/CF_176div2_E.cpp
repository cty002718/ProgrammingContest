#include<iostream>
#include<stack>
using namespace std;

int input[1000003];
stack<int> s;
pair<int,int> stmp[1000003];

int main()
{
	int n;
	cin >> n;
	int q;
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&input[i]);
	
	cin >> q;
	for(i=0;i<q;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		tmp--;
		input[tmp] = -input[tmp];
	}

	int top = 0;
	for(i=0;i<n;i++)
	{
		if(top == 0)
			stmp[top++] = make_pair(input[i],i);
		else
		{
			if(input[i] + stmp[top-1].first == 0)
				top--;
			else
				stmp[top++] = make_pair(input[i],i);
		}
	}
	
	int suc = 1;
	for(i=0;i<top;i++)
	{
		int m = stmp[i].second;
		if(s.empty())
		{
			if(input[m] < 0)
			{
				suc = 0;
				break;
			}
			else s.push(input[m]);
		}
		else
		{
			if(input[m] == s.top())
			{
				input[m] = -input[m];
				s.pop();
			}
			else if(input[m] == -s.top())
				s.pop();
			else if(input[m] < 0)
			{
				suc = 0;
				break;
			}
			else
				s.push(input[m]);				
		}
	}
	
	if(suc)
	{
		if(s.empty())
		{
			int i;
			cout << "YES" << endl;
			for(i=0;i<n;i++)
			{
				if(i!=0) cout << " ";
				printf("%d",input[i]);
			}
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;

	return 0;
}
