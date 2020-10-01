/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 
#define int ll
using namespace std;

const int N = 3e5 + 5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const long double eps = 1e-9 ;

using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

const int M = 1e3 + 1; 
int capacity[M][M] , s , t , n;
vector<int> g[M]; 

int get_next_flow(vector<int>& parent){
        parent.clear(); 
        parent.resize(n , -1);
        queue<pair<int , int>> q ;
        q.push(make_pair(s , inf));
        while(!q.empty()){
                pair<int ,int> u = q.front();
                q.pop();
                for(int v : g[u.ff]){
                        if(parent[v] == -1 && capacity[u.ff][v] > 0){
                                int new_flow = min(u.ss , capacity[u.ff][v]);
                                parent[v] = u.ff; 
                                if(v == t)
                                        return new_flow; 
                                q.push(mp(v , new_flow));

                        }
                }
        }
        return 0; 
}

int maxflow(){
        int new_flow , total = 0;
        vector<int> parent; 
        while(new_flow = get_next_flow(parent)){
                total += new_flow;
                int cur = t; 
                while(cur != s){
                        int p = parent[cur];
                        capacity[p][cur] -= new_flow;
                        capacity[cur][p] += new_flow;
                        cur = p;
                }
        }
        return total;
}

void solve()
{
}
     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}
