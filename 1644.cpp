#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
int n, a, b;
ll c[MN];
int main(){
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        cin >> c[i]; c[i] += c[i-1];
    }
    set<pair<ll,ll>> s;
    ll ans = -1e18;
    for(int i = 0; i <= n; i++){
        if(i >= a) s.insert({c[i-a], i-a});
        if(s.size()) ans = max(c[i] - (*s.begin()).first, ans);
        if(i >= b) s.erase({c[i-b], i-b});
    }
    cout << ans << "\n";
    return 0;
}