#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MN = 2e5+5;
const int MOD = 1000000007;

int n, q, a[MN];
ordered_set<pair<int,int>> os;

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        os.insert({a[i], i});
    }
    for(int i = 0; i < q; i++){
        char c; cin >> c;
        int x, y; cin >> x >> y;
        if(c == '!'){
            os.erase({a[x], x});
            a[x] = y;
            os.insert({y, x});
        }
        else{
            cout << os.order_of_key({y, MOD}) - os.order_of_key({x - 1, MOD}) << "\n";
        }
    }
    return 0;
}