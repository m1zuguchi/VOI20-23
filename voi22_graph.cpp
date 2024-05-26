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
const int MOD=1e9+7;
const int base=31;
const int N=2e3+1;
int n,f[N],maxDegree,res,dp[N][N],numKhuyet;
bool khuyet[N];
bool check()
{
	int cnt=0;
	int mx=0;
	for (int i=n;i;i--)
	{
		mx=max(mx,f[i]+cnt);
		if (f[i]>0) cnt++;
	}
	return mx<=maxDegree;
}
void backtrack(int pos)
{
	if (pos==n+1)
	{
		if (check()) res++;
		return;
	}
	if (!khuyet[pos]) backtrack(pos+1);
	else
	for (int i=0;i<pos;i++)
	{
		f[pos]=i;
		backtrack(pos+1);
		f[pos]=0;
	}
}
void sub1()
{
	backtrack(1);
	cout<<res;
}
void sub2()
{
	int pos=-1;
	for (int i=1;i<=n;i++) if (f[i]==-1) pos=i;
	if (pos!=-1)
	for (int i=0;i<pos;i++)
	{
		f[pos]=i;
		if (check()) res++;
	}
	cout<<res;
}
void sub34()
{
	/* f[i] + k <=b ; k = all j>i && f[j]>0
		DK de bai : f[i] < i && f[i] <= b-k
	*/
	for (int i=0;i<=n;i++) dp[0][i]=1;
	for (int i=1;i<=n;i++)
	{
		for (int k=0;k<=n-i;k++)
		{
			if (f[i]!=-1)
			{
				if (f[i]<i&&f[i]+k<=maxDegree) dp[i][k]=dp[i-1][k+(f[i]>0)];
			}
			else
			{
				if (k<=maxDegree) dp[i][k]=dp[i-1][k];
				int lim=min(i-1,maxDegree-k);
				if (lim>0) dp[i][k]=(dp[i][k]+1ll*lim*dp[i-1][k+1])%MOD;
			}
		}
	}
	cout<<dp[n][0];
}
int main()
{
	//#ifdef Hyojin
    	freopen("graph.inp", "r", stdin);
    	freopen("graph.out", "w", stdout);
//	#endif //Hyojin
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>maxDegree;
	for (int i=1;i<=n;i++)
	{
		cin>>f[i];
		if (f[i]==-1) khuyet[i]=1,numKhuyet++;
	}
	if (n<=6) sub1();
	else if (n<=200&&numKhuyet==1) sub2();
	else sub34();
	return 0;
}
