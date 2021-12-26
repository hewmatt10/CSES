#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
int main(){
    int n; long long k; cin >> n >> k;
    for(int i = 1;i<=n;i++)s.insert(i);
    int i = k;
    while(!s.empty()){
        i %= s.size();
        int x = *s.find_by_order(i);
        cout << x << " ";
        s.erase(x);
        i += k;
    }
    return 0;
}