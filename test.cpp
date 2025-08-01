#include <iostream>
#include<vector>
#include<map>
#include <unordered_map>
#include<math.h>
#include<stack>
#include<algorithm>
#include <limits.h>
#include<queue>
#include<cmath>
#include<set>


#define ll long long
#define MAXN 1000001
int spf[MAXN];
const int N = 1000000;   
const int MOD = 998244353;
ll tree[2 * N];

using namespace std;

// static bool cmp(pair<int, int> x, pair<int, int> y){
//     if(x.first==y.first)
//         return x.second>y.second;
//     else
//         return x.first<y.first;
// }

void build(vector<ll>& arr, int n) { 

    for (int i=0; i<n; i++)    
        tree[n+i] = arr[i];

    for (int i = n - 1; i > 0; --i)     
        tree[i] = tree[i<<1] & tree[i<<1 | 1];    
}

void updateTreeNode(ll p, ll value, ll n) { 
    tree[p+n] = value;
    p = p+n;

    for (int i=p; i > 1; i >>= 1)
        tree[i>>1] = tree[i] & tree[i^1];
}

int query(int l, int r, int n) { 
    ll res = 4294967295;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) 
            res = res & tree[l++];
      
        if (r&1) 
            res = res & tree[--r];
    }
      
    return res;
}

void sieve(){
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

ll calc_ceil(ll x,ll y){
    if(x%y==0)
        return x/y;
    else
        return 1+x/y;
}

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    vector<ll>b(m);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans = 0;
    for(ll i=0;i<n/2;i++){
        ans+=abs(a[i]-b[m-i-1]);
    }
    for(ll i=0;i<n/2;i++){
        ans+=abs(b[i]-a[n-i-1]);
    }
    if(n%2==1){
        ans+=max(abs(a[n/2]-b[m-n/2-1]),abs(a[n/2]-b[n/2]));
    }
    ll ans2 = 0;
    ll ans3 = 0;
    for(int i=0;i<n;i++){
        ans2+=abs(a[i]-b[m-n+i]);
    }
    for(int i=0;i<n;i++){
        ans3+=abs(a[i]-b[i]);
    }
    cout<<max(ans,max(ans2,ans3))<<endl;
}

int main(int argc, char *argv[]) {
	FILE* x;
    bool open = false;
	if(argc>1){
        x = freopen("test_input.txt", "r", stdin);
        open = true;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    bool t = true;
    if(t){
        int tc; cin>>tc;
        for(int i=1;i<=tc;i++){
            solve();
        }
            
    }
    else
        solve();
    if(open)
        fclose(x);

}

    
 