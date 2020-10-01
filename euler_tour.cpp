#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int ll
#define rep(i,n) for(int i=0;i<n;++i)
#define repa(i,a,n) for(int i=a;i<n;++i)
#define repr(i,n) for(int i=n-1;i>=0;--i)
#define repba(i,b,a) for(int i=b;i>=a;--i)
#define repab(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define pi pair<int,int> 
#define pii pair<pi,int>
#define ull unsigned long long
#define vi vector<int>
#define viip vector<pair<int,pair<int,int> > > 
#define mp make_pair
#define vip vector<pair<int,int> >
#define pb push_back 
#define fi first
#define sec second
#define all(v) v.begin(),v.end()
// #define s(v) v.size()
ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll fastexp(ll x,ll a){
    ll res = 1;
    while(a>0){
        if(a&1){
            res = (res*x)%mod;
        }
        a=a>>1;
        x=(x*x)%mod;
    }
    return res;
}
ll inverse(ll n){
    return fastexp(n,mod-2);
}
template <typename T>
void add(T &a, T b){
	a += b;
	if(a >= mod)a -= mod;
}
template <typename T>
void sub(T &a, T b){
	a -= b;
	if(a < 0)a += mod;
}
template <typename T>
void mul(T &a, T b){
	a *= b;
	if(a >= mod)a %= mod;
}
const int maxn = 1e5 + 2;
vi a;
vector<int> s(8*maxn);
int n;
void build(int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid,r);
	s[id] = s[2*id]+s[2*id+1];
}
int sum(int x,int y,int id = 1,int l = 0,int r = n){
	if(r <= x || y <= l)return 0;
	if(l >= x && y >= r)return s[id];
	int mid = (l+r)/2;
	return sum(x,y,2*id,l,mid) + sum(x,y,2*id+1,mid,r);
}
void modify(int x,int p,int id = 1,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = x;
		return;
	}
	int mid = (l+r)/2;
	if(p < mid)modify(x,p,2*id,l,mid);
	else modify(x,p,2*id+1,mid,r);
	s[id] = s[2*id]+s[2*id+1];
}
vi v[maxn];
int start[maxn];
int e[maxn];
int val[maxn];
void dfs(int u,int p){
	a.pb(val[u]);
	start[u] = a.size()-1;
	for(auto x:v[u]){
		if(x == p)continue;
		dfs(x,u);
	}
	a.pb(val[u]);
	e[u] = a.size()-1;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	rep(i,n-1){
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,n){
		cin>>val[i+1];
	}
	dfs(1,1);
	::n = a.size();
	// rep(i,::n){
	// 	cout<<a[i]<<" ";
	// }
	build();
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		if(x == 1){
			// change value
			int id;
			cin>>id;
			// id--;
			int val;cin>>val;
			modify(val,start[id]);
			modify(val,e[id]);
		}
		else{
			int x;
			cin>>x;
			cout<<sum(start[x],e[x]+1)/2<<"\n";
		}
	}
	return 0;
}
