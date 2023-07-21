/*
Problem: 1130. Tree Matching
Link - https://cses.fi/problemset/task/1130/
Author - Aryan Dua
*/

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
#define vvi vector<vi>
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

template<typename... T>
    void printl(T&&... args) { 
        ((cout << args << " "), ...); 
        cout<<'\n';
    }

vl input_arr(ll n){
    vl arr(n,0);
    for0(i, n)
        cin>>arr[i];
    return arr;      
}


// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Write code here

int ans = 0;
vvi adj;
vb vis;

void dfs(int src, int par){
    for(auto nbr: adj[src]){
        if(nbr!=par){
            // Go max possible ahead and reach the leaf node
            dfs(nbr, src);
            // Then backtrack at every alternate pair
            if(vis[src]==0 && vis[nbr]==0){
                vis[src] = 1;
                vis[nbr] = 1;
                ans++;
            }
        }
    }
}

void solve() {
    int n; input(n);
    vi temp;
    adj.resize(n, temp);
    vis.resize(n, false);
    for0(i, n-1){
        int u, v; input(u, v);
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(0, 0);
    print(ans);
    

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
5
1 2
1 3
3 4
3 5
*/

/*
Output:
2
*/