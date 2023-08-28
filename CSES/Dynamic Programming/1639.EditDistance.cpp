/*
Problem: 1639 - Edit Distance                                                                                                                               
Link - https://cses.fi/problemset/task/1639
Author - Aryan Dua
*/

#include<iostream> 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define for0(i, a) for(ll i = 0; i < a; i++)
#define for1(i, a) for(ll i = 1; i <= a; i++)
#define rofl(i, a) for(ll i = a; i > -1; i--)
#define fors(i, a, b, c) for(ll i = a; i < b; i += c)
#define fora(x, v) for(auto x : v)
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>
#define ml map<ll, ll>
#define sl set<ll>
#define pl pair<ll, ll>
#define pub push_back
#define pob pop_back
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define all(v) v.begin(), v.end()
 
const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;

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
            primes.pub(i+2);
    return primes;
}

vl get_factorials(ll n){
    vl factorials;
    factorials.pub(1);
    factorials.pub(1);
    for0(i, n-2)
        factorials.pub((factorials[i+1]*(i+2))%mod);
    return factorials;
}

ll binary_search(vd arr, ll low, ll high, ll x){
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

ll binary_search(vl arr, ll low, ll high, ll x){
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

map<ll, ll> frequency(vl arr){
    map<ll, ll> d;
    ll n = arr.size();
    for0(i, n)
        d[arr[i]] = 0;
    for0(i, n)
        d[arr[i]]+=1;
    return d;
}

void print(ll a){
    cout<<a<<endl;
}

void print(string s)
{
    cout<<s<<endl;
}

void printd(double n)
{
    cout<<n<<endl;
}

void printarr(vl arr){
    for0(i, (ll)arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printarr(vs arr){
    for0(i, (ll)arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printarr(vd arr){
    for0(i, (ll)arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}

void printarr(vector<pair<ll, ll>> arr){
    for0(i, (ll)arr.size())
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    cout<<endl;
}

void printmat(vector<vd > arr){
    for0(i, (ll)arr.size())
    {
        for0(j, (ll)arr[0].size())
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

void printmat(vvl arr){
    for0(i, (ll)arr.size())
    {
        for0(j, (ll)arr[0].size())
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

void sub(vl &arr, ll k){
    rofl(i, arr.size()-1){
        if(arr[i]-k>=0){
            arr[i]-=k;
            break;
        }
        else{
            arr[i]+=10-k;
            k = 1;
        }
    }
}

ll max(ll a, ll b){
    if(a>b)
        return a;
    else
        return b;
}

ll max(vl a){
    return *max_element(a.begin(), a.end());
}

double max(vd a){
    return *max_element(a.begin(), a.end());
}

ll getIndex(vl v, ll K)
{
    auto it = find(v.begin(), v.end(), K);
    ll ind = -1;
    if (it != v.end()) 
        ind = it - v.begin();
    return ind;
}

ll getIndex(vd v, double K)
{
    auto it = find(v.begin(), v.end(), K);
    ll ind = -1;
    if (it != v.end()) 
        ind = it - v.begin();
    return ind;
}

void update(vvl &dp, ll i, ll j){
    ll a = dp[i-1][j-1];
    ll b = dp[i-1][j];
    ll c = dp[i-1][j+1];
    dp[i][j] = (a+b+c)%mod;
}

double area(ll base, ll height){
    return (base*height*1.0)/2;
}

double sq(double a){
    return a*a*1.0;
}

void solve()
{
    string s1 = input_string();
    string s2 = input_string();
    ll n1 = s1.length();
    ll n2 = s2.length();
    vvl grid (n1+1, vl (n2+1, 0));
    for1(i, n1)
        grid[i][0] = i;
    for1(j, n2)
        grid[0][j] = j;
    for0(i, n1)
        for0(j, n2){
            // If the letters is the same, then the same letter wont cause any 'edits'
            if(s1[i]==s2[j])
                grid[i+1][j+1] = grid[i][j];
            else
                grid[i+1][j+1] = min(min(grid[i][j+1], grid[i+1][j]), grid[i][j])  + 1;
            // These are the 3 different ways of editing a word, add1/add2/edit letter
        }
    print(grid[n1][n2]);

    

}

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

/*
Input: 

SQTCKWAMFJEBV
IUWGGNJOMQFP

*/