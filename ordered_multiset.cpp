#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
 
void Insert(ordered_set &s,int x){ //this function inserts one more occurrence of (x) into the set.
 
     s.insert(x);
 
}
 
 
bool Exist(ordered_set &s,int x){ //this function checks weather the value (x) exists in the set or not.
 
     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);
 
}
 
 
void Erase(ordered_set &s,int x){ //this function erases one occurrence of the value (x).
 
     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }
 
}
 
 
int FirstIdx(ordered_set &s,int x){ //this function returns the first index of the value (x)..(0 indexing).
 
    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));
 
}
 
 
int Value(ordered_set &s,int idx){ //this function returns the value at the index (idx)..(0 indexing).
 
   return (*s.find_by_order(idx));
 
}
 
 
int LastIdx(ordered_set &s,int x){ //this function returns the last index of the value (x)..(0 indexing).
 
    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;
 
}
 
 
int Count(ordered_set &s,int x){ //this function returns the number of occurrences of the value (x).
 
     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;
 
}
 
 
void Clear(ordered_set &s){ //this function clears all the elements from the set.
 
     s.clear();
 
}
 
 
int Size(ordered_set &s){ //this function returns the size of the set.
 
     return (int)(s.size());
 
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i = 0;i<n;i++)
            cin>>arr[i];
        ordered_set o_set; 
        int ans = INT_MAX;
        for(int i = n-1;i>=0;i--){
            int x = arr[i];
            Insert(o_set,x);
            int y = LastIdx(o_set,x);
            ans = min(ans, Size(o_set)-y-1 + i);
            // cout<<Size(o_set)-y-1<<" ";
            
    }
    cout<<ans<<endl;
}
}