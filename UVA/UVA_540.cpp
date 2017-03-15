#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int team[1000003];

int main()
{
	int n;
	int c = 0;
	while(cin >> n && n!=0)
	{
		printf("Scenario #%d\n",++c);
		queue<int> mainq;
		queue<int> q[1003];
		int i;
		for(i=0;i<n;i++)
		{
			int t;
			scanf("%d",&t);
			
			int j;
			for(j=0;j<t;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				team[tmp] = i;
			}
		}

		while(1)
		{
			char oper[10];
			scanf("%s",oper);
			if(oper[0]=='E')
			{
				int num;
				scanf("%d",&num);

				if(q[team[num]].empty())
					mainq.push(team[num]);
				
				q[team[num]].push(num);
			}
			else if(oper[0]=='D')
			{
				int tmp = mainq.front();
				int take = q[tmp].front();
				q[tmp].pop();
				printf("%d\n",take);
				if(q[tmp].empty())
					mainq.pop();
			}
			else
				break;
		}
		cout << endl;
	}

	return 0;
}	
