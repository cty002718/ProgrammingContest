#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

pair<int,int> cow[3000];
pair<int,int> lotion[3000];

int main()
{
	int c,l;
	int i,j;
	cin >> c >> l;
	
	for(i=0;i<c;i++)
		scanf("%d%d",&cow[i].first,&cow[i].second);
	for(i=0;i<l;i++)
		scanf("%d%d",&lotion[i].first,&lotion[i].second);
	
	sort(cow,cow+c);
	sort(lotion,lotion+l);

	priority_queue<int,vector<int>,greater<int> > q;
	int co=0;
	int ans=0;
	for(i=0;i<l;i++)
	{
		while(co<c && cow[co].first<=lotion[i].first)
		{
			q.push(cow[co].second);
			co++;
		}

		int num=lotion[i].second;
		for(j=0;j<num;j++)
		{
			while(!q.empty())
			{
				int tmp=q.top();
				q.pop();
				if(tmp>=lotion[i].first)
				{
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
