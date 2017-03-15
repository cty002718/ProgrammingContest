#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
	int to,cap,rev;
};

vector<edge> G[150];
int level[150];
int iter[150];

void addedge(int,int,int);
int makeflow(int,int,int);
void BFS(int);

int main()
{
	int cn,cs,ct,m;
	while(cin >> cn >> cs >> ct >> m)
	{
		int i;
		for(i=0;i<150;i++)
			G[i].clear();
		for(i=0;i<m;i++)
		{
			char tmp;
			while(cin >> tmp)
				if(tmp=='(')
					break;
			int a,b,c;
			scanf("%d,%d)%d",&a,&b,&c);
			addedge(a,b,c);
		}

		for(i=0;i<cs;i++)
		{
			char tmp;
			while(cin >> tmp)
				if(tmp=='(')
					break;
			int b,c;
			scanf("%d)%d",&b,&c);
			addedge(cn,b,c);
		}

		for(i=0;i<ct;i++)
		{	
			char tmp;
			while(cin >> tmp)
				if(tmp=='(')
					break;
			int a,c;
			scanf("%d)%d",&a,&c);
			addedge(a,cn+1,c);
		}


		int ans=0;
		
        while(1)
        {
            
            BFS(cn);
            if(level[cn+1]<0)
                break;
            memset(iter,0,sizeof(iter));
            while(1)
            {
                int d=makeflow(cn,cn+1,1e9);
                if(d<=0)
                    break;
                ans+=d;
            }
        }
		cout << ans << endl;
	}

	return 0;
}

void addedge(int a,int b,int c)
{
	G[a].push_back((edge){b,c,G[b].size()});
	G[b].push_back((edge){a,0,G[a].size()-1});
}

void BFS(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> q;
    level[s]=0;
    q.push(s);
    
    while(!q.empty())
    {
        int a=q.front(); q.pop();
        int i;
        for(i=0;i<G[a].size();i++)
        {
            edge &b=G[a][i];
            if(b.cap > 0 && level[b.to]==-1)
            {
                level[b.to] = level[a] + 1;
                q.push(b.to);
            }
        }
    }
    
}
int makeflow(int n,int t,int f)
{
	if(n==t)
		return f;
	
	for(int &i=iter[n] ;i<G[n].size();i++)
	{
		edge &tmp=G[n][i];
		if(tmp.cap!=0 && level[tmp.to] > level[n])
		{
			int d=makeflow(tmp.to,t,min(f,tmp.cap));
			if(d>0)
			{
				tmp.cap-=d;
				G[tmp.to][tmp.rev].cap+=d;
				return d;
			}
		}
	}

	return 0;
}
