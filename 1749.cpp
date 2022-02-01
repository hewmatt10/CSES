#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MN = 2e5+5;
int n;
ordered_set<pair<int,int>> os;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        os.insert({i, x});
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x; x--;
        auto it = os.find_by_order(x);
        cout << (*(it)).second << " ";
        os.erase(it);
    }
    return 0;
}