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
const int N=1e5+5;
const int M=1e6+5;
int n,L=1,R=M-5;
array<int,3>a[N];
ll res=-1e18;
vector<int>queries[M];
bool allNeg=true;
ll lazy[M*4],st[M*4];
void down(int id)
{
	if (lazy[id]!=0)
	{
		int val=lazy[id];
		lazy[id<<1]+=val;
		lazy[id<<1|1]+=val;
		st[id<<1]+=val;
		st[id<<1|1]+=val;
		lazy[id]=0;
	}
}
void update(int id,int l,int r,int u,int v,int val)
{
	if (v<l||r<u) return;
	if (u<=l&&r<=v)
	{
		st[id]+=val;
		lazy[id]+=val;
		return;
	}
	down(id);
	int mid=l+r>>1;
	update(id<<1,l,mid,u,v,val);
	update(id<<1|1,mid+1,r,u,v,val);
	st[id]=max(st[id<<1],st[id<<1|1]);
}
int main()
{
	//#ifdef Hyojin
    	freopen("sseq.inp", "r", stdin);
    	freopen("sseq.out", "w", stdout);
	//#endif //Hyojin
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if (a[i][2]>0) allNeg=0;
	}
	if (allNeg) return cout<<0,0;
	sort(a+1,a+n+1,[](array<int,3>x,array<int,3>y){return x[1]<y[1];});
	for (int i=1;i<=n;i++)
	{
		update(1,1,R,1,a[i][0],a[i][2]);
		res=max(res,st[1]);
	}
	cout<<res;
	return 0;
}
