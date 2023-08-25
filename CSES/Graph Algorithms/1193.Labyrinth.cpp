/*
Problem: 1193 - Labyrinth
Link - https://cses.fi/problemset/task/1193/
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
#define f first
#define s second
#define mp make_pair
 
const ll N = 2e5 + 4;
const ll mod = 1e9 + 7;
vs grid;
vvl prevCoord (1000, vl (1000, -1));
vvl vis (1000, vl (1000, 0));

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

void print(ll a){
    cout<<a<<endl;
}

void print(string s)
{
    cout<<s<<endl;
}

void bfs(pl coord, ll m, ll n){
    queue<pl> q;
    q.push(coord);
    vl di = {1, -1, 0, 0};
    vl dj = {0, 0, 1, -1};
    while (!q.empty()){
        pl p = q.front();
        q.pop();
        if(grid[p.f][p.s]=='B')
            return;
        for0(k, 4){
            ll row = p.f+di[k];
            ll col = p.s+dj[k];
            bool cond1 = row<m && col<n && row>=0 && col>=0;
            bool cond2 = grid[row][col]=='.' || grid[row][col]=='B';
            if(cond1 && cond2 && !vis[row][col]){
                q.push(make_pair(row, col));
                prevCoord[row][col] = k;
                vis[row][col] = 1;
            }
        }   
    }
    return;
}

void solve()
{
    ll m = input_n();
    ll n = input_n();
    for0(i, m)
        grid.push_back(input_string());
    string path;
    pl end;
    pl start;
    // make pair is a standard function to make a pair of the given types
    for0(i, m)
        for0(j, n)
        {
            if(grid[i][j]=='A')
                start = make_pair(i, j);
            if(grid[i][j]=='B')
                end = make_pair(i, j);
        }
    bfs(start, m, n);
    // prevCoord stores the direction it took to reach the i, j
    while(end!=start){
        ll dir = prevCoord[end.first][end.second];
        if(dir==0){
            end.first = end.first-1;
            path+="D";
        }
        else if(dir==1){
            end.first = end.first+1;
            path+="U";
        }
        else if(dir==2){
            end.second = end.second-1;
            path+="R";
        }
        else if(dir==3){
            end.second = end.second+1;
            path+="L";
        }  
        else{
            path = "";
            break;
        } 
    }
    // the path will be in reverse order
    reverse(path.begin(), path.end());
    ll sz = path.size();
    if(sz==0){
        print("NO");
    }  
    else{
        print("YES");
        print(sz);
        print(path);
    }         
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
