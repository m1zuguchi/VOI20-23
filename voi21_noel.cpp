#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
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
const int N=2e3+5;
int n,d,a[2005],res,m[2050],ft[N];
int get(int x)
{
	int s=0;
	for (;x;x-=x&-x) s=max(s,ft[x]);
	return s;
}
void update(int x,int val)
{
	for (;x<=N-5;x+=x&-x) ft[x]=max(ft[x],val);
}
int main()
{
	#ifdef Hyojin
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif //Hyojin
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	for (int i=1;i<=n*2;i++)
	{
		cin>>a[i];
		m[a[i]]=i;
	}
	for (int k=1;k<=2*n;k++)
	{
		memset(ft,0,sizeof ft);
		vector<int>p;
		for (int i=1;i<=k;i++)
		{
			vector<int>pos;
			for (int j=a[i]-d;j<=a[i]+d;j++)
			{
				if (m[j]>k) pos.pb(m[j]);
			}
			sort(pos.begin(),pos.end(),greater<int>());
			for (int x:pos) p.pb(x);
		}
		for (int x:p)
		{
			int ans=get(x-1)+1;
			res=max(res,ans);
			update(x,ans);
		}
	}
	cout<<res;
	return 0;
}
