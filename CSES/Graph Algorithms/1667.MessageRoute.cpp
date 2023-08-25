/*
Problem: 1667 - Message Route                                                                                                                                         
Link - https://cses.fi/problemset/task/1667
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

ll mul(ll a, ll b){
    return (a*b)%mod;
}

ll add(ll a, ll b){
    return (a+b)%mod;
}

bool is_prime(ll n){
    for0(i, (int)(sqrt(n)-1))
        if(n%(i+2)==0)
            return false;
    return true;
}

vl get_primes(ll n){
    vl primes;
    for0(i, n-2)
        if(is_prime(i+2))
            primes.push_back(i+2);
    return primes;
}

vl get_factorials(ll n){
    vl factorials;
    factorials.push_back(1);
    factorials.push_back(1);
    for0(i, n-2)
        factorials.push_back((factorials[i+1]*(i+2))%mod);
    return factorials;
}

template <class T>
    ll binary_search(vector<T> arr, ll low, ll high, T x){
        ll mid = (high+low)/2;
        if(high>=low){
            mid = (high+low)/2;
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]>=x)
                return binary_search(arr, low, mid-1, x);
            else
                return binary_search(arr, mid+1, high, x);
        }
        else
            return -1;  
    }

string input_string(){
    string s;
    cin>>s;
    return s;
}

ll input_n(){
    ll n;
    cin>>n;
    return n;
}

vl input_arr(ll n){
    vl arr(n,0);
    for0(i, n)
        cin>>arr[i];
    return arr;
        
}

ll modinverse(ll a) {
	ll m = mod, y = 0, x = 1;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += mod;
	return x;
}

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

bool checkpoweroftwo(ll n) {
	return !(n & (n - 1));
}

ll power(ll a, ll b, ll md = mod) {
	ll product = 1;
	a %= md;
	while (b) {
		if (b & 1) product = (product * a) % md;
		a = (a * a) % md;
		b /= 2;
	}
	return product % md;
}

ll inv(ll x){
    return power(x, mod-2);
}

ll ncr_modp(ll n, ll r, ll p){
    if(n<=0 || r<=0 || (n-r)<=0)
        return 1;
    
    vl factorials = get_factorials(1+max(n, n-r));
    ll inv1 = inv(factorials[r]);
    ll inv2 = inv(factorials[n-r]);
    ll inv = (inv1*inv2)%p;

    return (factorials[n]*inv)%p;
}

string decimalToBinary(ll n)
{
    string s = bitset<64>(n).to_string();
    const auto loc1 = s.find('1');
    if(loc1 != string::npos)
        return s.substr(loc1);
    return "0";
}

ll binaryToDecimal(string s){
    int i,N,decimal_number=0,p=0;
    N=s.size();
    for(i=N-1;i>=0;i--)
    {
        if(s[i]=='1')
            decimal_number+=pow(2,p);
        p++;
    }
    return decimal_number;
}

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----


// Vector functions
template <class T>
    map<T, ll> frequency(vector<T> arr){
        map<T, ll> d;
        ll n = arr.size();
        for0(i, n)
            d[arr[i]] = 0;
        for0(i, n)
            d[arr[i]]+=1;
        return d;
    }

template <class T>
    void print(T a){
        cout<<a<<endl;
    }

template <class T>
  void printarr (T arr)
  {
    for0(i, (ll)arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
  }

void printarr(vector<pair<ll, ll>> arr){
    for0(i, (ll)arr.size())
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    cout<<endl;
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

template <class T>
    T max(vector<T> a){
        return *max_element(a.begin(), a.end());
    }

template <class T>
    ll getIndex(vector<T> v, T K)
    {
        auto it = find(v.begin(), v.end(), K);
        ll ind = -1;
        if (it != v.end()) 
            ind = it - v.begin();
        return ind;
    }

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Set functions
template <class T>
    bool findInSet(set<T> s, T x){
        if(s.find(x)!=s.end())
            return true;
        else
            return false;
    }

// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Map functions
template <class T1, class T2>
    void printMapOfVectors(map<T1, T2> m){
        fora(elem, m){
            cout<<"Key: "<<elem.first<<" Value: ";
            printarr(elem.second);
        }
    }

template <class T1, class T2>
    void printMap(map<T1, T2> m){
        fora(elem, m)
            cout<<"Key: "<<elem.first<<", Value: "<<elem.second<<endl;
    }

template <class T1, class T2>
    vector<T1> getKeys(map<T1, T2> m){
        vector<T1> keys;
        fora(elem, m)
            keys.push_back(elem.first);
        return keys;
    }

template <class T1, class T2>
    vector<T2> getVals(map<T1, T2> m){
        vector<T2> vals;
        fora(elem, m)
            vals.push_back(elem.second);
        return vals;
    }


// -----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X-----X----

// Graph functions

class Graph {
    int V; // No. of vertices
    int curr;
    list<int>* adj;
    
 
public:
    Graph(int V); // Constructor
    ~Graph();
    map<int, vector<int> > components;
    void addEdge(int v, int w);
    void connectedComponents();
    map<int, int > prevVertex;
    void dfs(int v, bool visited[]);
    void bfs(int v);
};

Graph::Graph(int V) {
    this->V = V;
    this->curr = 0;
    adj = new list<int>[V];
}

Graph::~Graph() { 
    delete[] adj; 
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

void Graph::bfs(int v) {
    vector<bool> visited;
    visited.resize(V, false);
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);
 
    while (!queue.empty()) {
        v = queue.front();
        // cout << v << " ";
        queue.pop_front();
        for (auto adjacent : adj[v]) 
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                prevVertex[adjacent] = v;
                queue.push_back(adjacent);
            }
    }
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
    // do a bfs traversal to find the shortest path
    g.bfs(0);

    // maintain a prev vector to trace back the correct path
    mi prev = g.prevVertex;
    vi ans;
    if(prev.find(n-1)!=prev.end()){
        int curr = n-1;
        while(curr!=0){
            ans.push_back(curr+1);
            curr = prev[curr];
        }
        ans.push_back(1);
        reverse(ans);
        print(ans.size());
        printarr(ans);
    }
    else
        print("IMPOSSIBLE");
    
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
