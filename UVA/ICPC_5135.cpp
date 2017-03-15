#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

struct edge
{
	int x,y;
};

int c;
int bcc_count;
int low[100003];
int visit[100003];
int visit2[100003];
int bcc_id[100003];
bool isap[100003];

vector<int> BCC[100003];
vector<int> G[100003];
stack<int> s;

void dfs(int,int);
void addedge(int,int);

int main()
{
	int m;
	int co = 0;
	while(cin >> m && m!=0)
	{
		int i,j;
		for(i=0;i<50003;i++)
		{
			G[i].clear();
			BCC[i].clear();
		}
		
		for(i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		
		c = 0;
		bcc_count = 0;
		memset(visit,0,sizeof(visit));
		memset(visit2,0,sizeof(visit2));
		memset(isap,false,sizeof(isap));
		memset(bcc_id,0,sizeof(bcc_id));
		memset(low,0,sizeof(low));
		while(!s.empty()) s.pop();
		dfs(1,-1);
	
		long long sum1 = 0;
		long long sum2 = 1;
	/*	for(i=1;i<=10;i++)
			cout << visit2[i] << " ";
		cout << endl;
	*/	
		//for(i=1;i<=10;i++)
		//	if(isap[i])
		//		cout << i << " ";
		//cout << endl;
		for(i=1;i<=bcc_count;i++)
		{
			int count = 0;
			for(j=0;j<BCC[i].size();j++)
			{
			//	cout << BCC[i][j] << " ";
				if(isap[BCC[i][j]])
					count++;
			}
		//	cout << endl;
			if(count == 1)
			{
				sum1++;
				sum2*=(long long)(BCC[i].size() - 1);
			}
		}
		if(bcc_count == 1)
		{
			sum1 = 2;
			sum2 = (long long)BCC[1].size()*(BCC[1].size()-1)/2;
		}
		cout << "Case " << ++co << ": " << sum1 << " " << sum2 << endl;
	}
	return 0;
}

void addedge(int a,int b)
{
	G[a].push_back(b);
	G[b].push_back(a);
}

void dfs(int a,int f)
{
	low[a] = visit[a] = ++c;
	visit2[c] = a;
	s.push(a);
	int i;
	int child = 0;
	for(i=0;i<G[a].size();i++)
	{
		int b = G[a][i];
		if(b == f) continue;
		
		if(!visit[b])
		{
			//s.push((edge){a,b});
			child++;
			dfs(b,a);
			low[a] = min(low[a],low[b]);
			
			//edge tmp;
			if(low[b] >= visit[a])
			{
				isap[a] = true;	
				bcc_count++;
				int tmp;
				do{
					tmp = s.top();
					s.pop();
					BCC[bcc_count].push_back(tmp);
					bcc_id[tmp] = bcc_count;
				}while(tmp!=b);

				BCC[bcc_count].push_back(a);
				bcc_id[a] = a;
			}

		}
		else if(visit[a] > visit[b])
		{
			//s.push((edge){a,b});
			low[a] = min(visit[b],low[a]);
		}
	}

	if(f==-1 && child == 1)
		isap[a] = false;
}
