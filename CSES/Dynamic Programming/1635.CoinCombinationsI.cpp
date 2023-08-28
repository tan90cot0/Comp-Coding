/*
Problem: 1635 - Coin Combinations I                                                                                                                                    
Link - https://cses.fi/problemset/task/1635/
Author - Aryan Dua
*/

#include<iostream> 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define forl(i, a, b) for(ll i = a; i < b; i++)
#define rofl(i, a, b) for(ll i = a; i > b; i--)
#define fors(i, a, b, c) for(ll i = a; i < b; i += c)
#define fora(x, v) for(auto x : v)
#define vl vector<ll>
#define ml map<ll, ll>
#define sl set<ll>
#define vb vector<bool>
#define pub push_back
#define pob pop_back
#define yesno(x) cout << ((x) ? "YES\n" : "NO\n")
#define all(v) v.begin(), v.end()
 
const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;
 
bool is_prime(ll n){
    forl(i, 2, (int)(sqrt(n)+1))
        if(n%i==0)
            return false;
    return true;
}
 
vl get_primes(ll n){
    vl primes;
    forl(i, 2, n)
        if(is_prime(i))
            primes.pub(i);
    return primes;
}
 
vl get_factorials(ll n){
    vl factorials;
    factorials.pub(1);
    factorials.pub(1);
    forl(i, 2, n)
        factorials.pub((factorials[i-1]*i)%mod);
    return factorials;
}
 
ll binary_search(vector<double> arr, ll low, ll high, ll x){
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
    vl arr;
    ll temp;
    forl(i, 0, n)
    {
        cin>>temp;
        arr.pub(temp);
    }
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
    forl(i, 0, arr.size())
        d[arr[i]] = 0;
    forl(i, 0, arr.size())
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
 
void print(double n)
{
    cout<<n<<endl;
}
 
void printarr(vl arr){
    forl(i, 0, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
void printarr(vector<string> arr){
    forl(i, 0, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
void printarr(vector<double> arr){
    forl(i, 0, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
void printmat(vector<vector<double> > arr){
    forl(i, 0, arr.size())
    {
        forl(j, 0, arr[0].size())
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
 
 
void solve()
{
    ll n = input_n();
    ll x = input_n();
    vl arr = input_arr(n);
    vl dp;
    forl(i,0,x+1)
        dp.pub(0);
    dp[0] = 1;
    forl(i, 0, x+1)
        forl(j, 0, n)
            if(i+arr[j]<=x)
                dp[i+arr[j]] = (dp[i+arr[j]]+dp[i])%mod;
    print(dp[x]);
    
}
 
int main(int argc, char *argv[]) {
	if(argc>1)
        freopen("test_case.txt", "r", stdin);
    bool t = false;
    if(t){
        int tc;
        cin>>tc;
        while(tc--)
            solve();
    }
    else
        solve();
 
}