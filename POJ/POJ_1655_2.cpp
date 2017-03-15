#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int son[20001];
int dp[20001];
int ans;
int y;
int n;
vector<int> list[20001];
void dfs(int,int);

int main()
{
    int num;
    cin >> num;
    while(num--)
    {
        cin >> n;
        memset(son,0,sizeof(son));
        memset(dp,0,sizeof(dp));
        int i;
        for(i=0;i<20001;i++)
            list[i].clear();
        for(i=0;i<n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            list[a].push_back(b);
            list[b].push_back(a);
        }
        ans=1e9;
        y=1e9;
        dfs(1,-1);
        
        cout << y << " " << ans << endl;
        
    }
    
    return 0;
}

void dfs(int a,int fa)
{
    int i;
    son[a]=1;
    int len=list[a].size();
    
    for(i=0;i<len;i++)
    {
        int b = list[a][i];
        if(b==fa)
            continue;
        dfs(b,a);
        son[a]+=son[b];
        if(son[b]>dp[a])
            dp[a]=son[b];
    }
    int tmp;
    tmp = max(dp[a],n-son[a]);
    if(tmp <= ans)
    {
        if(tmp==ans)
        {
            if(a<y)
                y=a;
        }
        
        else
            y=a;
        
        ans = tmp;
    }
    
}