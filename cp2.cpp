#include <iostream>
#include<vector>
#include<map>
#include <unordered_map>
#include <unordered_set>
#include<math.h>
#include<stack>
#include<algorithm>
#include <limits.h>
#include<queue>
#include <deque>
#include<cmath>
#include<set>

#define ll long long
using namespace std;

void solve() {
    
}

int main(int argc, char *argv[]) {
	FILE* x;
    bool open = false;
	if(argc>1){
        x = freopen("test_case.txt", "r", stdin);
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

    
 