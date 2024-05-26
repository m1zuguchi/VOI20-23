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
int cur,n,a[N],d[N*3];
vector<pii>adj[N*3];
array<int,2>st[N*3];
void addEdge(int u,int v,int w)
{
	adj[u].pb({v,w});
}
array<int,2>build(int l,int r)
{
	if (l==r) return {l,l};
	int mid=l+r>>1;
	int id1=++cur;
	int id2=++cur;
	auto Left=build(l,mid);
	auto Right=build(mid+1,r);
	st[id1]={Left[0],Right[0]};
	st[id2]={Left[1],Right[1]};
	addEdge(id1,st[id1][0],0);
	addEdge(id1,st[id1][1],0);
	addEdge(st[id2][0],id2,0);
	addEdge(st[id2][1],id2,0);
	return {id1,id2};
}
void add(int id,int l,int r,int u,int v,int pos,bool type)
{
	if (v<l||r<u) return;
	if (u<=l&&r<=v)
	{
		addEdge(id,pos,1);
		return;
	}
	int mid=l+r>>1;
	add(st[id][0],l,mid,u,v,pos,type);
	add(st[id][1],mid+1,r,u,v,pos,type);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//#ifdef Shiho
    	freopen("income.inp","r", stdin);
    	freopen("income.out","w", stdout);
	//#endif
	cin>>n;
	cur=n;
	auto [root1,root2]=build(1,n);
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		add(root2,1,n,l,r,i,1);
	}
	vector<int>f;
	for (int i=1;i<=n;i++) f.pb(i);
	sort(all(f),[&](int x,int y){
		return a[x]>a[y];
	});
	fill(d+1,d+cur+1,-1);
	deque<int>dq;
	for (int i=0;i<n;i++)
	{
		int j=i;
		while (j<n&&a[f[j]]==a[f[i]])
		{
			if (d[f[j]]==-1)
			{
				dq.pb(f[j]);
				d[f[j]]=0;
			}
			j++;
		}
		i=j-1;
		while (dq.size())
		{
			int u=dq.front();
			dq.pop_front();
			for (auto [v,w]:adj[u])
			{
				if (d[v]==-1)
				{
					d[v]=d[u]+w;
					if (w) dq.pb(v);
					else dq.push_front(v);
				}
			}
		}
	}
	cout<<*max_element(d+1,d+n+1)+1;
	return 0;	
}
