/*
Problem: 1672 - Shortest Routes I  I                                                                                                                      
Link - https://cses.fi/problemset/task/1672
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

template <class T>
    void printmat(T arr){
        for0(i, (ll)arr.size())
        {
            for0(j, (ll)arr[0].size())
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Write code here

void solve() {
    ll n, m, q; input(n, m, q);
    // this initial value needs to be more than n*weight of edge
    vvl dist (n, vl (n, 1000*mod));
    for0(i, m){
        ll u, v, wt; input(u, v, wt);
        dist[u-1][v-1] = min(wt, dist[u-1][v-1]);
        dist[v-1][u-1] = min(wt, dist[v-1][u-1]);
    }
    // Floyd Warshall Algo
    for0(i, n)  dist[i][i] = 0;
    for0(k, n)
        for0(i, n)
            for0(j, n)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for0(i, q){
        ll u, v; input(u, v);
        ll temp = dist[u-1][v-1];
        if(temp==1000*mod)
            printl(-1);
        else
            printl(temp);
    }

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
10 20 10
2 4 5
2 7 8
1 2 3
9 10 6
8 9 6
8 10 9
1 6 6
2 5 7
6 9 7
3 4 9
4 8 2
5 6 2
7 8 5
5 9 8
7 9 7
4 6 8
2 3 6
6 7 10
4 9 3
4 5 4
3 2
9 8
10 4
5 9
6 10
8 9
4 10
1 2
10 2
6 10

*/