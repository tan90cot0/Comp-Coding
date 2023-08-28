// Author - Aryan Dua

#include<iostream> 
#include <bits/stdc++.h>

using namespace std;

#define for0(i, a) for(ll i = 0; i < a; i++)
#define for1(i, a) for(ll i = 1; i <= a; i++)
#define rofl(i, a) for(ll i = a; i > -1; i--)
#define forn(i, a, b, c) for(ll i = a; i < b; i += c)
#define fora(x, v) for(auto x : v)

#define ll long long
#define ld long double

#define vl vector<ll>
#define vi vector<int>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vvi vector<vi>
#define vvl vector<vl>
#define vvb vector<vb>

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

#define f first
#define s second

const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;

#define sort(v) sort(v.begin(), v.end())
#define reverse(v) reverse(v.begin(), v.end())
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

// Input Functions
template<typename... T>
    void input(T&... args) { 
        ((cin >> args), ...);
    }

vi input_arr(ll n){
    vi arr(n,0);
    for0(i, n)
        cin>>arr[i];
    return arr;      
}

// Output Functions
template <class T>
  void printarr (T arr)
  {
    for0(i, (ll)arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
  }

template<typename... T>
    void print(T&&... args) { 
        ((cout << args << " "), ...);
    }

template<typename... T>
    void println(T&&... args) { 
        ((cout << args << " "), ...);
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

// Helper functions

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
        if(high>=low){
            ll mid = (high+low)/2;
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

template<typename T>
inline void remove(vector<T> & v, const T & item){
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
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

// Set functions
template <class T>
    bool findInSet(set<T> s, T x){
        if(s.find(x)!=s.end())
            return true;
        else
            return false;
    }

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

template <class T1, class T2>
    bool findInMap(map<T1, T2> m, T1 x){
        if(m.find(x)!=m.end())
            return true;
        else
            return false;
    }

// Graph functions

class Graph {
    int V; // No. of vertices
 
public:
    Graph(int V); // Constructor
    list<int>* adj;
    void addEdge(int v, int w);
    void bfs();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::bfs() {

}

// Write code here
bool test_cases = true;

void solve() {
    int n; input(n);
}

// Initialiser Function

int main(int argc, char *argv[]) {
    IOS
	FILE* x;
    bool open = false;
	if(argc>1){
        x = freopen("test_case.txt", "r", stdin);
        open = true;
    }
    
    if(test_cases){
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

/*
Output:
*/