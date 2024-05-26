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
#define dbg(x) cerr<<#x<<' '<<x<<' '
const int base=31;
const int MOD=1e9+7;
const int N=5e3+5;
int n,m,a[N][N],s[N][N],f[N];
pair<bool,int>dp[N][N];
int id(int i,int j)
{
	return (i-1)*m+j;
}
int getSum(int x,int y,int u,int v)
{
	return s[u][v]-s[x-1][v]-s[u][y-1]+s[x-1][y-1];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef Shiho
    	freopen("izumi_shiho_supremacy.in","r", stdin);
    	freopen("izumi_shiho_supremacy.out","w", stdout);
	#endif
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=m;j++) 
		{
			cin>>a[i][j];
			s[i][j]+=(a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]);
		}
	}
	memset(dp,0,sizeof dp);
	for (int i=1;i<=m;i++)
	{
		dp[i][i]={1,getSum(1,i,n,i)};
	}
	for (int i=m;i;i--)
	{
		for (int j=i+1;j<=m;j++)
		{
			for (int k=i;k<j;k++)
			{
				if (dp[i][k].fi==1&&dp[k+1][j].fi==1&&dp[i][k].se==dp[k+1][j].se) 
				{
					dp[i][j]={1,dp[i][k].se+dp[k+1][j].se};
				}
			}
		}
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<i;j++) if (dp[j+1][i].fi==1) f[i]=min(f[i],f[j]+1);
	}
	int ans=f[m];
	memset(dp,0,sizeof dp);
	for (int i=1;i<=n;i++)
	{
		dp[i][i]={1,getSum(i,1,i,m)};
	}
	for (int i=n;i;i--)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=i;k<j;k++)
			{
				if (dp[i][k].fi==1&&dp[k+1][j].fi==1&&dp[i][k].se==dp[k+1][j].se) 
				{
					dp[i][j]={1,dp[i][k].se+dp[k+1][j].se};
				}
			}
		}
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<i;j++) if (dp[j+1][i].fi==1) f[i]=min(f[i],f[j]+1);
	}
	cout<<ans*f[n];
	return 0;	
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
