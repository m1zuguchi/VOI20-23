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
const int N=2e3+5;
int n,d,a[N],res,m[N];
int main()
{
	//#ifdef Hyojin
    	freopen("pair.inp", "r", stdin);
    	freopen("pair.out", "w", stdout);
	//#endif //Hyojin
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	vector<array<ll,3>>f;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			f.pb({a[i]+a[j],i,j});
			f.pb({a[i]+a[j]+d,i,j});
		}
	}
	sort(f.begin(),f.end());
	for (int i=0;i<f.size();i++)
	{
		vector<int>idx;
		int j=i;
		while (j<f.size()&&f[j][0]==f[i][0])
		{
			idx.pb(f[j][1]);
			idx.pb(f[j][2]);
			j++;
		}
		i=j-1;
		sort(idx.begin(),idx.end(),[](int x,int y){return make_pair(a[x],x)<make_pair(a[y],y);});
		idx.erase(unique(all(idx)),idx.end());
		#define val(x) a[idx[x]]
		int cnt=0;
		int p=idx.size()-1;
		for (int k=0;k<p;k++)
		{
			while (k<p&&val(k)+val(p)>f[i][0]) p--;
			if (k<p&&abs(val(k)+val(p)-f[i][0])<=d)
			{
				cnt++;
				p--;
			}
		}
		res=max(res,cnt);
	}
	cout<<res;
	return 0;
}
