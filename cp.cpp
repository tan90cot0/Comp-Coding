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

#define vvii vector<vii>
#define vvll vector<vll>

#define f first
#define s second

const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll inf = LLONG_MAX;

// #define reverse(v) reverse(v.begin(), v.end())
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")

// Input Functions
template<typename... T>
    void input(T&... args) { 
        ((cin >> args), ...);
    }

vi input_arr(int n){
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

vl get_factorials(ll n){
    vl factorials;
    factorials.push_back(1);
    factorials.push_back(1);
    for0(i, n-2)
        factorials.push_back((factorials[i+1]*(i+2))%mod);
    return factorials;
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

ll mex(vector<ll> &a) {
    vector<bool> f(a.size() + 1, 0);
    for (ll i : a) if (i <= (ll) a.size()) f[i] = 1;
    ll mex = 0;
    while (f[mex]) {
        ++mex;
    }
    return mex;
}

random_device rd; 
mt19937_64 gen(rd());

// Write code here
bool test_cases = true;

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& parent, vector<vector<int>>& children) {
    parent[node] = par;
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            children[node].push_back(neighbor);
            dfs(neighbor, node, adj, parent, children);
        }
    }
}

ll calc_n2(ll k){
    ll k1 = 1+8*k;
    ll n2 = (-1+sqrt(k1))/2;
    return n2+1;
}


void solve() {
    ll n, k; cin >> n >> k;
    ll nc2 = (n*(n-1))/2;
    if(k>nc2)
        cout<<-1<<endl;
    else{
        vector<ll> primes (2e6+1, 1);
        for(ll i=2; i<=2e6; i++){
            if(primes[i]==1){
                for(ll j=2*i; j<=2e6; j+=i)
                    primes[j] = 0;
            }
        }
        vector<ll> primes2;
        for(ll i=2; i<=2e6; i++){
            if(primes[i]==1)
                primes2.push_back(i);
        }
        ll p = primes2.size();
        vector<ll> pref (p);
        pref[0] = 2;
        for(ll i=1; i<primes2.size(); i++){
            pref[i] = pref[i-1]*primes2[i];
        }
        vector<ll> arr (n, 0);
        ll n2 = calc_n2(k);
        ll rem = k - (n2*(n2-1))/2;
        for(ll i=0;i<n2;i++){
            cout<<primes2[i]<<" ";
        }
        for(ll i = n2; i<n; i++){
            cout<<pref[n2-rem-1]<<" ";
        }
        cout<<endl;
    }

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