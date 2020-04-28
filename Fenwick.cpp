/*************************BALIGA***************************************/

// FENWICK SAMPLE CODE FOR SUM QUERY//
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
#define mod 1000000007
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
#define MAX_SIZE 1000000
#define SIZE 1000000000
#define E5 100000
#define E6 1000000
#define E9 1000000000
#define INF64 1e18
#define INF32 1e9

//FENWICK TREE FOR THE SUM QUERY
void solve() {
	int n,q1,q2;
	cin>>n>>q1>>q2;
	vi nums(n);
	rep0(i,n) cin>>nums[i];
	vi fenwick(n+1);
	//Constructing the tree
	rep1(i,n) fenwick[i]=0;
	int idx,val,diff;
	for(int i=0;i<n;i++) {
		idx=i+1;
		while(idx<=n) {
			fenwick[idx]+=nums[i];
			idx+=(idx&(-idx));
		}
	}
	//end of constructing tree

	//Updating the tree
	while(q1--) {
		cin>>idx>>val;
		diff=val-nums[idx];
		idx++;
		while(idx<=n) {
			fenwick[idx]+=diff;
			idx+=(idx&(-idx));
		}
	}
	//End of Updating tree

	int sum;
	//Getting sum queries
	while(q2--) {
		sum=0;
		cin>>idx;
		idx++;
		while(idx>0) {
			sum+=fenwick[idx];
			idx-=(idx&(-idx));
		}
		cout<<sum<<'\n';
	}
	//End of getting sum queries
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