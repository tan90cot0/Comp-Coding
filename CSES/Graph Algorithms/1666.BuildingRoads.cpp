/*
Problem: 1666 - Building Roads                                                                                                                                          
Link - https://cses.fi/problemset/task/1666
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

#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define f first
#define s second

#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define mp make_pair
 
const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Helper Functions

ll input_n(){
    ll n;
    cin>>n;
    return n;
}

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----


// Vector functions

template <class T>
    void print(T a){
        cout<<a<<endl;
    }

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Map functions

template <class T1, class T2>
    vector<T1> getKeys(map<T1, T2> m){
        vector<T1> keys;
        fora(elem, m)
            keys.push_back(elem.first);
        return keys;
    }


// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Graph functions

class Graph {
    int V; // No. of vertices
    int curr;
    list<int>* adj;
    void dfs(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    map<int, vector<int> > components;
    void addEdge(int v, int w);
    void connectedComponents();
};

Graph::Graph(int V) {
    this->V = V;
    this->curr = 0;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::connectedComponents() {
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            curr = v;
            dfs(v, visited);
            // cout << "\n";
        }
    }
    delete[] visited;
}
 
void Graph::dfs(int v, bool visited[]) {
    visited[v] = true;
    components[curr].push_back(v);
    // cout << v << " ";
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited);
}

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Write code here

void solve() {
    ll n = input_n();  
    ll m = input_n();

    //Make a graph
    Graph g(n);   
    for0(i, m){
        ll u = input_n();  
        ll v = input_n();
        g.addEdge(u-1, v-1);
    }

    // Find the connected components
    g.connectedComponents();

    // Get a representative node for each connected component
    vi keys = getKeys(g.components);

    // Now make a Minimum Spanning Tree for these nodes
    print(keys.size()-1);
    for1int(i, (int)keys.size()-1)
        cout<<keys[i-1]+1<<" "<<keys[i]+1<<endl;

}


// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----
// Initialiser Function

int main(int argc, char *argv[]) {
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
