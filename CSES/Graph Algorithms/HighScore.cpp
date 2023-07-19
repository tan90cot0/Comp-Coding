#include<iostream> 
#include <bits/stdc++.h>
using namespace std;

#define for0(i, a) for(ll i = 0; i < a; i++)
#define for1(i, a) for(ll i = 1; i <= a; i++)
#define rofl(i, a) for(ll i = a; i > -1; i--)
#define forn(i, a, b, c) for(ll i = a; i < b; i += c)
#define fora(x, v) for(auto x : v)
#define printarr(arr, a, b) for(ll i = a; i < b; i++) print(arr[i])

#define ll long long
#define ld long double

#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vl>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define ml map<ll, ll>
#define mi map<int, int>
#define ms map<string, string>

#define sl set<ll>
#define si set<int>
#define ss set<string>

#define pl pair<ll, ll>
#define pi pair<int, int>

#define vii vector<pi>
#define vll vector<pl>

#define vvii vector<vii>
#define vvll vector<vll>


#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define f first
#define s second

#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Helper Functions
template<typename... T>
    void input(T&... args) { 
        ((cin >> args), ...);
    }

template<typename... T>
    void print(T&&... args) { 
        ((cout << args << " "), ...);
    }

template<typename... T>
    void printl(T&&... args) { 
        ((cout << args << " "), ...); 
        cout<<'\n';
    }

void bellmanFord(ll V, vvll adj){
    vl dist (V, 1e13);
    dist[0] = 0;
    
    // Bellman ford runs n-1 times
    for0(i, V-1)
        for0(u, V) 
            for(auto [v, wt]: adj[u])
                if(dist[u] != 1e13 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
    queue<ll> changed;
    // Check which vertices change in the nth iteration, they are a part of a negative cycle
    for0(u, V) 
        for(auto [v, wt]: adj[u])
            if(dist[u] != 1e13 && dist[u] + wt < dist[v])
                changed.push(v);
            
    // Check if the negative cycle vertices affect the nth node
    vector<bool> visited (V, false);
    while(!changed.empty()){
        ll elem = changed.front();
        changed.pop();
        if(elem==V-1){
            print(-1);
            return;
        }
        for(auto [v, wt] : adj[elem]){
            if(!visited[v]){
                changed.push(v);
                visited[v] = true;
            }
        }
    }

    print(-dist[V-1]);
}

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Write code here

void solve() {
    ll n, m; input(n, m);
    vll temp;
    vvll adj (n, temp);

    for0(i, m){
        ll u, v, wt; input(u, v, wt);
        adj[u-1].push_back({v-1, -wt});
    }
    bellmanFord(n, adj);
}

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Initialiser Function

int main(int argc, char *argv[]) {
    IOS
	FILE* x;
    bool open = false;
	if(argc>1){
        x = freopen("test_case.txt", "r", stdin);
        open = true;
    }
    bool t = false;
    if(t){
        int tc; cin>>tc;
        while(tc--)
            solve();
    }
    else
        solve();
    if(open)
        fclose(x);
}

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
/*
Input:
*/