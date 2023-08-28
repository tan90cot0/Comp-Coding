/*
Problem: 1637 - Removing Digits                                                                                                                                  
Link - https://cses.fi/problemset/task/1637
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
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>
#define ml map<ll, ll>
#define sl set<ll>
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
 
void printd(double n)
{
    cout<<n<<endl;
}
 
void printarr(vl arr){
    forl(i, 0, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
void printarr(vs arr){
    forl(i, 0, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
void printarr(vd arr){
    forl(i, 0, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
}
 
void printmat(vector<vd > arr){
    forl(i, 0, arr.size())
    {
        forl(j, 0, arr[0].size())
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
 
void sub(vl &arr, ll k){
    rofl(i, arr.size()-1, -1){
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
 
 
void solve()
{
    ll n = input_n();
    vl arr;
    while(n>0){
        arr.pub(n%10);
        n/=10;
    }
    reverse(arr.begin(), arr.end());
    ll cnt = 0;
    ll k = *max_element(arr.begin(), arr.end());
    while(k>0){
        sub(arr, k);
        k = *max_element(arr.begin(), arr.end());
        cnt+=1;
    }
    print(cnt);
 
    
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