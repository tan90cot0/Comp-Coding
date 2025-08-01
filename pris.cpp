/*hare krishna*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define sorta(x) sort(x.begin(),x.end())
#define sortd(x) sort(x.rbegin(),x.rend())
#define read(arr) for(auto &x : arr) cin>>x;
#define print(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
#define printmap(arr) for(auto &x: arr) cout<<x.first<<" "<<x.second<<endl; cout<<endl;
#define printpair(arr) for(auto &x: arr) cout<<x.first<<" "<<x.second<<endl; cout<<endl;
#define printset(arr) for(auto &x: arr) cout<<x<<" "; cout<<endl;
#define pb push_back
// ll lcm(ll a,ll b) { return a/__gcd(a,b)*b; }
bool is_prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() {cout<<"NO\n";}
void yes() {cout<<"YES\n";}

ll max(int a,ll b) { if (a>b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll min(ll a,int b) { if (a<b) return a; return b; }

void readinput(){
    #ifndef ONLINE_JUDGE
    freopen("test_case.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
}

void fast_io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



int cn(int node, int parent, vector<int> adj[]) {
    int count = 1;
    for (int child : adj[node]) {
        if (child != parent) {
            count += cn(child, node, adj);
        }
    }
    return count;
}

int cln(int node, int parent, vector<int> adj[]) {
    bool isLeaf = true;
    int leafCount = 0;
    for (int child : adj[node]) {
        if (child != parent) {
            isLeaf = false;
            leafCount += cln(child, node, adj);
        }
    }
    return isLeaf ? 1 : leafCount;
}

pair<int, int> dfsForDiameter(int node, int parent, vector<int> adj[]) {
    int maxDepth1 = 0, maxDepth2 = 0; 
    int diameter = 0;
    
    for (int child : adj[node]) {
        if (child != parent) {
            pair<int, int> result = dfsForDiameter(child, node, adj);
            int depth = result.first + 1;
            diameter = max(diameter, result.second); 
            
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }
    }
    diameter = max(diameter, maxDepth1 + maxDepth2);
    return {maxDepth1, diameter};
}

int td(vector<int> adj[], int root = 1) {
    return dfsForDiameter(root, -1, adj).second;
}
int main() {
    fast_io();
    
    ll t;
    cin>>t;
    while(t--){
        ll n,d,l;
        cin>>n>>d>>l;
        if(d>=n){
            cout<<-1<<endl;
            continue;
        }
        vector<int>adj[n+1000];
        adj[1].pb(2);
        int node = 2;
        int cnt = 1;
        if(cnt<d){
            adj[1].pb(3);
            cnt++;
            node++;
        }
        int a = 2, b= 3;
        while(cnt<d&&node<n){
            adj[a].pb(b+1);
            cnt++;
            node++;
            if(cnt<d){
                adj[b].pb(b+2);
                cnt++;
                node++;
            }
            a = b+1;
            b = b+2;
        }
        a = b+1;
        int maxi = d/2;
        if(d&1) maxi++;
        int leaf = 2;
        while(leaf<l&&node<n){
            adj[1].pb(a);
            a++;
            leaf++;
            node++;
        }
        for(auto it:adj[1]){
            if(it!=2&&it!=3){
                int len = 1;
                int num = it;
                while(len<maxi&&node<n){
                    adj[num].pb(a);
                    num = a;
                    a++;
                    len++;
                    node++;
                }
            }
        }
        int gn= cn(1,-1,adj);
        int gl = cln(1,-1,adj);
        int gd = td(adj,1);
        if(n!=gn || l!=gl || gd!=d) cout<<-1<<endl;
        else {
            for(int i =1;i<=n;i++){
                for(auto x:adj[i]){
                    cout<<i<<" "<<x<<endl;
                }
            }
        }
    }
    
    return 0;
}
/*
check for constraints!!
n =1?
think diff if stuck on one!!
diff algo or ds?
see all questions and move on...
*/