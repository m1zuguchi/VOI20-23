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
const int N=1e6+5;
void setIO(const string &NAME)
{
	if (NAME.size())
	{
		freopen((NAME+".inp").c_str(),"r",stdin);
		freopen((NAME+".out").c_str(),"w",stdout);
	}
}
int add(int a,int b){return (a+b)%MOD;}
int sub(int a,int b){return (a-b+MOD)%MOD;}
int mul(int a,int b){return (1ll*a*b)%MOD;}
int power(int a,int b)
{
	int res=1;
	while (b)
	{
		if (b&1) res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
int fac[N],rfac[N];
int C(int n,int k)
{
	if (k>n||k<0) return 0;
	int ans=fac[n];
	ans=mul(ans,rfac[k]);
	ans=mul(ans,rfac[n-k]);
	return ans;
}
int n,a[N],k,L,R;
struct subtask1{
	void solve()
	{
		int ans=0;
		for (int mask=1;mask<(1<<n);mask++)
		{
			if (__builtin_popcount(mask)!=k) continue;
			int cur=0;
			for (int i=0;i<n;i++) if (bit(mask,i)) cur|=a[i];
			if (cur%3==0&&L<=cur&&cur<=R) ans++;
		}
		cout<<ans;
	}
} saptat1;
struct subtask2{
	int dp[230][230][300];
	void solve()
	{
		dp[0][0][0]=1;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<=min(i,k);j++)
			{
				for (int v=0;v<=255;v++)
				{
					if (dp[i][j][v]>0)
					{
						dp[i+1][j][v]=(dp[i+1][j][v]+dp[i][j][v])%MOD;
						if (j+1<=k) dp[i+1][j+1][v|a[i]]=(dp[i+1][j+1][v|a[i]]+dp[i][j][v])%MOD;
					}
				}
			}
		}
		int ans=0;
		for (int i=L;i<=R;i++) if (i%3==0) ans=(ans+dp[n][k][i])%MOD;
		cout<<ans;
	}
} saptat2;
struct subtask3{
	int dp[1<<20];
	void solve()
	{
		if (L%3!=0)
		{
			cout<<0;
			return;
		}
		for (int i=0;i<n;i++) dp[a[i]]++;
		int ans=0;
		for (int i=0;i<20;i++)
		{
			for (int mask=0;mask<(1<<20);mask++)
				if (bit(mask,i)) dp[mask]+=dp[mask^(1<<i)];
		}
		int cnt=__builtin_popcount(L);
		for (int mask=L;mask;mask=(mask-1)&L)
		{
			int x=C(dp[mask],k);
			if ((__builtin_popcount(mask)&1)==(cnt&1)) ans=add(ans,x);
			else ans=sub(ans,x);
		}
		cout<<ans;
	}
} saptat3;
struct subtask4{
	int dp[1<<20],f[1<<20];
	void solve()
	{
		for (int i=0;i<n;i++) dp[a[i]]++;
		for (int i=0;i<20;i++)
		{
			for (int mask=0;mask<(1<<20);mask++)
				if (bit(mask,i)) dp[mask]+=dp[mask^(1<<i)];
		}
		for (int mask=0;mask<(1<<20);mask++) 
		{
			int x=C(dp[mask],k);
			if (__builtin_popcount(mask)&1) f[mask]=add(f[mask],x);
			else f[mask]=sub(f[mask],x);
		}
		for (int i=0;i<20;i++)
		{
			for (int mask=0;mask<(1<<20);mask++)
				if (bit(mask,i)) f[mask]=add(f[mask],f[mask^(1<<i)]);
		}
		int ans=0;
		for (int i=L;i<=R;i++) 
		{
			if (i%3) continue;
			if (__builtin_popcount(i)&1) ans=add(ans,f[i]);
			else ans=sub(ans,f[i]);
		}
		cout<<ans;
	}
} saptat4;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef izumiShiho
    	setIO("input");
	#endif //izumiShiho
    cin>>n>>k>>L>>R;
    for (int i=0;i<n;i++) cin>>a[i];
    if (n<=20) saptat1.solve();
	else if (n<=200) saptat2.solve();
	else
	{
		fac[0]=1;
		for (int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
		rfac[n]=power(fac[n],MOD-2);
		for (int i=n-1;~i;i--) rfac[i]=mul(rfac[i+1],i+1);
		if (L==R) saptat3.solve();
		else saptat4.solve();
	}
	return 0;
}
