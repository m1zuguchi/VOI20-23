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
const int N=3e5+5;
const int M=sqrt(N)+5;
const int maxN=1e5+5;
void setIO(const string &NAME)
{
	if (NAME.size())
	{
		freopen((NAME+".inp").c_str(),"r",stdin);
		freopen((NAME+".out").c_str(),"w",stdout);
	}
}
struct trie{
	trie *child[26];
	ll val;
	trie()
	{
		memset(child,0,sizeof child);
		val=0ll;
	}
} root;
int cur,a[N],out[N],n,m;
ll heavy[maxN],light[maxN];
string s[N];
ll dp[N];
vector<int>adj[maxN],adj_heavy[maxN];
void update(const string &s,ll val)
{
	trie *p=&root;
	for (int i=0;i<s.size();i++)
	{
		int c=s[i]-'A';
		if (!p->child[c]) p->child[c]=new trie();
		if (i<s.size()-1) p->child[c]->val=max(p->child[c]->val,val);
		p=p->child[c];
	}
}
ll get(const string &s)
{
	trie *p=&root;
	for (int i=0;i<s.size();i++)
	{
		int c=s[i]-'A';
		if (!p->child[c]) p->child[c]=new trie();
		p=p->child[c];
	}
	return p->val;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef Amon
    	setIO("Amon");
	#endif //Amon
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
    	cin>>s[i]>>a[i];
    }
    for (int i=1;i<=m;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    for (int u=1;u<=1e5;u++)
    {
    	for (int v:adj[u])
    	{
    		if (adj[v].size()>=M) 
    		{
    			adj_heavy[u].pb(v);
    		}
    	}
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
    {
    	dp[i]=max(light[a[i]],get(s[i]));
    	for (int v:adj_heavy[a[i]]) dp[i]=max(dp[i],heavy[v]);
    	dp[i]+=a[i];
    	update(s[i],dp[i]);
    	if (adj[a[i]].size()<M)
    	{
    		for (int v:adj[a[i]]) light[v]=max(light[v],dp[i]);
    	}
    	else heavy[a[i]]=max(heavy[a[i]],dp[i]);
    	ans=max(ans,dp[i]);
    }
    cout<<ans;
	return 0;
}
