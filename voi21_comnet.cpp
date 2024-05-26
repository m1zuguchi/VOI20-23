#include <bits/stdc++.h>
using namespace std;
#define bit(n,i) ((n>>i)&1) 
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define ep emplace_back
#define pii pair<int,int>
#define piii pair<int,pii> 
#define fi first
#define se second
#define ll long long
#define debug(x) cerr << #x << ' ' << x << '\n'
const int base=31;
const int MOD=1e9+7;
const int N=1e3+5;
void setIO(const string &NAME)
{
	if (NAME.size())
	{
		freopen((NAME+".inp").c_str(),"r",stdin);
		freopen((NAME+".out").c_str(),"w",stdout);
	}
}
int n,sz[N],szEdge[N],k,a,b;
ll dp[N][10][N];
vector<int>adj[N];
void dfs(int u,int par)
{
	dp[u][0][0]=1;
	dp[u][1][0]=1;
	sz[u]=1;
	for (int v:adj[u])
	{
		if (v==par) continue;
		dfs(v,u);
		for (int i=min(k,sz[u]);~i;i--)
		{
			for (int j=min(k-i,sz[v]);j;j--)
			{
				for (int x=szEdge[u];~x;x--)
				{
					for (int y=szEdge[v];~y;y--)
					{
						int s1=i+j;
						int s2=(j<k)+x+y;
						/*
						Neu (j<k) nghia la viec chon tap cac dinh van chua ket thuc 
						Co the chon i hoac khong chon i vao tap cac dinh 
						*/
						dp[u][s1][s2]=dp[u][s1][s2]+1ll*dp[u][i][x]*dp[v][j][y];
					}
				}
			}
		}
		sz[u]+=sz[v];
		szEdge[u]+=szEdge[v]+1;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef Amon
    	setIO("Amon");
	#endif //Amon
    cin>>n>>k>>a>>b;
   	for (int i=1;i<n;i++)
   	{
   		int u,v;
   		cin>>u>>v;
   		adj[u].pb(v);
   		adj[v].pb(u);
   	}
   	dfs(1,1);
   	ll ans=0;
   	for (int i=a;i<=b;i++) ans+=dp[1][k][i];
   	cout<<ans;
	return 0;
}
