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
const int N=1e6+5;
int n;
ll dp[N];
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//#ifdef Shiho
    	freopen("ADN.inp","r", stdin);
    	freopen("ADN.out","w", stdout);
	//#endif
	cin>>s;
	n=(int)s.size();
	for (int i=0;i<n;i++)
	{
		if (s[i]=='?')
		{
			int j=i;
			while (j<n&&s[j]==s[i]) j++;
			if (i==0)
			{
				if (j==n) return cout<<0,0;
				for (int _=i;_<j;_++) s[_]=s[j];
			}
			else if (j==n||s[i-1]==s[j])
			{
				for (int _=i;_<j;_++) s[_]=s[i-1];
			}
			i=j-1;
		}
	}
	vector<int>a;
	for (int i=0;i<n;i++)
	{
		int j=i;
		while (j<n&&s[i]==s[j]) j++;
		a.pb(i);
		if (j==n) break;
		i=j-1;
	}
	a.pb(n);
	int m=(int)a.size()-1;
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for (int i=0;i<m;i++)
	{
		bool diff=0;
		for (int j=i;j<m;j++)
		{
			if (s[a[j]]!='?')
			{
				if (diff) break;
				diff=1;
			}
			dp[j+1]=min(dp[j+1],dp[i]+1ll*a[i]*(a[j+1]-a[i]));
		}
	}
	cout<<dp[m];
	return 0;	
}
