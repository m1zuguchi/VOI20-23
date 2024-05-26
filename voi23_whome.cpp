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
const int N=1e5+5;
void setIO(const string &NAME)
{
	if (NAME.size())
	{
		freopen((NAME+".inp").c_str(),"r",stdin);
		freopen((NAME+".out").c_str(),"w",stdout);
	}
}
int n,m,P,C,a[N],s[6];
ll dp[N][1<<6];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//#ifdef Shiho
    	freopen("whome.inp","r", stdin);
    	freopen("whome.out","w", stdout);
	//#endif
    cin>>n>>m>>P>>C;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<m;i++) cin>>s[i];
    memset(dp,-0x3f,sizeof dp);
	sort(a+1,a+n+1);
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int mask=0;mask<(1<<m);mask++)
		{
			dp[i][mask]=max(dp[i-1][mask],dp[i][mask]);
			for (int j=0;j<m;j++)
			{
				if (i+s[j]-1>n) continue;
				int nxt=i+s[j]-1;
				ll cost=P-1ll*(a[nxt]-a[i])*(a[nxt]-a[i])*C;
				dp[nxt][mask|(1<<j)]=max(dp[nxt][mask|(1<<j)],dp[i-1][mask]+cost);
			}
		}
	}
	cout<<dp[n][(1<<m)-1];
	return 0;
}
