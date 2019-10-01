//SAMPLE CODE TEMPLATE FOR DIJKSTRA'S ALGORITHM
//MODIFY AS NEEDED



/*************************BALIGA***************************************/
#include <bits/stdc++.h>
// use gp_hash_table<int,int,custom_hash> m;
// in place of map
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//use rng()%n for numbers in range [0,n-1]
// This custom_hash is for unordered_map 
// use map<int, int, custom_hash> mp;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define lli long long int
#define ll long long
#define ull unsigned long long
#define ulli unsigned long long int
#define MP make_pair
#define PB push_back
#define MT make_tuple
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define reprev1(i,n) for(ll i=n;i>0;i--)
#define reprev0(i,n) for(ll i=n-1;i>=0;i--)
#define reprev(i,x,y) for(ll i=x;i>=y;i--)
#define ff first
#define ss second
#define pii pair <int,int>
#define piii pair <pii,int>
#define vi vector<int>
#define vli vector<long long int>
#define vipair vector<pair<int,int>>
#define vlipair vector<pair<lli,lli>>
#define all(c) c.begin(),c.end()
#define print(c) for(int i=0;i<c.size();i++) cout<<c[i]<<' '
#define mod 1000000007
#define MAX_SIZE 1000000
#define SIZE 1000000000
#define E5 100000
#define E6 1000000
#define E9 1000000000
#define div 4294967295
#define INF64 1e18-1
#define INF32 1e9

void solve() {
	lli n,m,l,s,t,u,v,w;
	cin>>n>>m>>l>>s>>t;
	vipair edges[n];
	vi visited(n,0);
	set <pair<lli,lli>> heap;
	vli dist(n,INF64);
	dist[s]=0;
	rep0(i,m) {
		cin>>u>>v>>w;
		edges[u].PB(MP(v,w));
		edges[v].PB(MP(u,w));
	}
	int current,wt;
	heap.insert(MP(0,s));
	while(!heap.empty()) {
		auto tmp = *(heap.begin());
		heap.erase(heap.begin());
		int vertex=tmp.second;
		// cout<<vertex<<'\n';
		rep0(i,edges[vertex].size()) {
			int v = edges[vertex][i].first;
			if(!visited[v]) {
				int weight = edges[vertex][i].second;
				if(dist[v]>dist[vertex]+weight) {
					if(dist[v]!=INF64) heap.erase(heap.find(MP(dist[v],v)));
					dist[v]=dist[vertex]+weight;
					heap.insert(MP(dist[v],v));
				}
			}
		}
		visited[tmp.second]=1;
	}
	for(int i=0;i<n;i++) cout<<i<<' '<<dist[i]<<'\n';
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int TC;
    //FOR CODECHEF
    // cin>>TC;
    //
    //FOR CODEFORCES
    TC=1;
    for(int t=0;t<TC;t++) solve();
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}