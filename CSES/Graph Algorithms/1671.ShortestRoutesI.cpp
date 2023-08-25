/*
Problem: 1671 - Shortest Routes I                                                                                                                        
Link - https://cses.fi/problemset/task/1671
Author - Aryan Dua
*/

#include<iostream> 
#include <bits/stdc++.h>
using namespace std;

#define for0(i, a) for(ll i = 0; i < a; i++)
#define for0int(i, a) for(ll i = 0; i < a; i++)
#define for1(i, a) for(ll i = 1; i <= a; i++)
#define for1int(i, a) for(int i = 1; i <= a; i++)
#define rofl(i, a) for(ll i = a; i > -1; i--)
#define roflint(i, a) for(ll i = a; i > -1; i--)
#define forn(i, a, b, c) for(ll i = a; i < b; i += c)
#define fornint(i, a, b, c) for(ll i = a; i < b; i += c)
#define fora(x, v) for(auto x : v)
#define printarr(a, n) for1(i, n) print(a[i])

#define ll long long
#define ld long double

#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vl >
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

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Write code here

void solve() {
    int n, m; input(n, m);
    ll dist[100005];
    int vis [100005];
    vll adj [100005];
    for0(i, m){
        ll u, v, wt; input(u, v, wt);
        adj[u].push_back({v,wt});
    }
    for1(i, n-1) dist[i+1] = inf;
    // Dijkstra's algo - find the node at the minimum distance from source and proceed towards its neighbours
    priority_queue<pl,vll,greater<pl>> q;
    q.push({0, 1});
    while (!q.empty()) {
        ll u = q.top().s;  q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto [v, wt]: adj[u]) 
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                q.push({dist[v], v});
            }
    }
    printarr(dist, n);
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
        int tc;
        cin>>tc;
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
10 20
8 5 1
9 10 2
7 9 8
9 8 8
10 9 9
7 8 10
8 9 2
7 10 10
4 5 8
5 6 1
4 2 1
5 3 6
10 7 3
3 5 2
5 4 7
1 2 9
2 3 2
6 7 5
3 4 10
3 2 10

*/