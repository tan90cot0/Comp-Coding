/*
Problem: 2220 - Counting Numbers                                                                                                                       
Link - https://cses.fi/problemset/task/2220
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

ll calc(ll n){
    vl arr;
    vl digits;
    ll n_copy = n;
    if(n==-1 or n==0)
        return n+1;
    for(; n; n/=10)
        digits.push_back( n%10 );
    ll num_digits = digits.size();
    if(num_digits==1)
        return n_copy+1;
    ll num = 1;
    for0(i, num_digits){
        arr.push_back(num);
        num*=9;
    }
    vl digit_less_than;
    digit_less_than.push_back(0);
    rofl(i, num_digits-2){
        if(digits[i]>=digits[i+1])
            digit_less_than.push_back(1);
        else
            digit_less_than.push_back(0);
    }
    ll s = 0;
    rofl(i, num_digits-1){
        ll val = (digits[i]-digit_less_than[num_digits-1-i]);
        ll power = arr[i];
        ll x;
        if(i==num_digits-1)
            x = (val-1)*power + (power*10)/9;
        else
            x = val*power;
        s+=x;
    }
    return s+2;
        
}

void solve()
{
    ll a = input_n();
    ll b = input_n();
    print(calc(b) - calc(a-1));
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
5 5
*/