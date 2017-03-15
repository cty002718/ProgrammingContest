#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	int to,weight;
};

node v[10003][100];
int num[10003];
int sz[10003], max_subtree[10003],small,smallx;
bool visit[10003];
int dis[10003];
int cal2[10003];
int length;

int n,k;

void addedge(int,int,int);
int solve(int a);
int cal(int a,int nowweight);
void getarray(int a,int f);
int treecenter(int a,int f);
void dfs(int x,int p);

int main()
{
	while(cin >> n >> k && n!=0 && k!=0)
	{
		int i;
        for(i=1;i<=n;i++)
        {
			num[i] = 0;
        	visit[i] = false;
		}
		//memset(visit,false,sizeof(visit));

		for(i=0;i<n-1;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
		}
		//cout << 123 << endl;
        int newa = 1;//treecenter(1,-1);
		cout << solve(newa) << endl;
	}

	return 0;
}

void addedge(int a,int b,int c)
{
    v[a][num[a]].to = b;
    v[a][num[a]++].weight = c;
    v[b][num[b]].to = a;
    v[b][num[b]++].weight = c;
	//cout << "hihi";
}

int solve(int a)
{
	//cout << "fuck2";
    //int newa = treecenter(a,-1);
	//cout << newa << endl;
    int ans = cal(a,0);
   // cout << a << " : " << ans << endl;
	//cout << ans << endl;
	visit[a] = true;
    int i;
    for(i=0;i<num[a];i++)
    {
        if(visit[v[a][i].to] == true) continue;
		int tmp =  cal(v[a][i].to,v[a][i].weight);
     	ans -= tmp;
		//cout << " - " <<v[a][i].to << " : " << tmp << endl;  	 
        int newr = v[a][i].to;//treecenter(v[a][i].to,a);
        ans += solve(newr);
    }
    return ans;
}

int cal(int a,int nowweight)
{
    dis[a] = nowweight;
	length = 0;
    getarray(a,-1);
   	//cout << "haha" << endl; 
    sort(cal2,cal2+length);
    int i;
	//for(i=0;i<cal2.size();i++)
	//	cout << cal2[i] << " ";
	//cout << endl;
	int left = 0,right = length - 1;
    int ans = 0;
    while(left < right)
    {
        if(cal2[left] + cal2[right] <= k)
        {
			ans += (right - left + 1);
        	left++;
		}
    	right--;
	}
    
    return ans;
}

void getarray(int a,int f)
{
	//length = 0;
	//cout << a << " " << f << endl;
    cal2[length++] = dis[a];
    int i;
    for(i=0;i<num[a];i++)
    {
        if(v[a][i].to==f) continue;
        if(visit[v[a][i].to] == true) continue;
        
        dis[v[a][i].to] = dis[a] + v[a][i].weight;
        getarray(v[a][i].to,a);
	}
}

int treecenter(int a,int f)
{
	//cout << "fuck";
    small = 1e8;
    dfs(a,f);
    return smallx;
}

void dfs(int x,int p)
{
    sz[x] = 1;
    int i;
    for(int i = 0;i < num[x];i++)
    {
        node u = v[x][i];
        if(u.to != p && !visit[x])
        {
            dfs(u.to, x);
            sz[x] += sz[u.to];
            max_subtree[x] = max(max_subtree[x], sz[u.to]);
        }
    }
    max_subtree[x] = max(max_subtree[x], n - sz[x]);
    
    if(max_subtree[x] < small)
    {
        small = max_subtree[x];
        smallx = x;
    }
}

