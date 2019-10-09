/*************************BALIGA***************************************/

//This is a sample code for segment tree. (Sum of range query)
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
#define INF64 1e18
#define INF32 1e9

//SEGMENT TREEE SUM QUERY SAMPLE

void constructSegment(vi &nums,vli &segment,int low,int high,int pos) {
	if(low==high) {
		segment[pos]=nums[low];
		return;
	}
	int mid= (high+low)/2;
	constructSegment(nums,segment,low,mid,2*pos);
	constructSegment(nums,segment,mid+1,high,2*pos+1);
	segment[pos]=(segment[2*pos]+segment[2*pos + 1]);
	return;
}

lli sumQuery(vli &segment,int qlow,int qhigh,int low,int high,int pos) {
	if(qlow<=low && qhigh>=high) return segment[pos];
	if(qlow>high || qhigh<low) return 0;
	int mid=(low+high)/2;
	return (sumQuery(segment,qlow,qhigh,low,mid,2*pos)+sumQuery(segment,qlow,qhigh,mid+1,high,2*pos+1));
}

void updateSegment(vli &segment,int low,int high,int diff,int idx,int pos) {
	if(idx<low || idx>high) return;
	segment[pos]+=diff;
	if(low!=high) {
		int mid=(low+high)/2;
		updateSegment(segment,low,mid,diff,idx,2*pos);
		updateSegment(segment,mid+1,high,diff,idx,2*pos+1);
	}
	return;
}

void solve() {
	int n,q1,q2;
	cin>>n>>q1>>q2;

	int N=1;
	while(N<n) N*=2; //Making size of array a power of 2
	
	vi nums(N+1,0);
	rep1(i,n) cin>>nums[i];

	//Creating the segment tree
	vli segment(2*N);
	constructSegment(nums,segment,1,N,1);
	// rep1(i,2*N-1) cout<<segment[i]<<'\n';
	//End of creating segment tree

	//Updating segment tree
	lli pos,val,diff; //pos is one indexed
	while(q1--) {
		cin>>pos>>val;
		diff=val-nums[pos];
		updateSegment(segment,1,N,diff,pos,1);
	}
	//End of updating segment tree

	//Getting sum queries in segment tree
	lli l,r,ans; //one-indexed
	while(q2--) {
		cin>>l>>r;
		ans=sumQuery(segment,l,r,1,N,1);
		cout<<ans<<'\n';
	}
	//End of queries
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
 	cin>>TC;
 	//
 	//FOR CODEFORCES
 	// TC=1;
 	for(int t=0;t<TC;t++) solve();
 	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}