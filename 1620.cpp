#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
ll n, t;
ll k[MN];

ll calc(ll u){
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += u/k[i];
        if(ans >= t) break;
    }
    return ans;
}

int main(){
    cin >> n >> t;
    for(ll i = 0; i < n; i++) cin >> k[i];
    ll l = 0, r = (ll)1e18, ans;
    while(l <= r){
        ll mid = l + (r - l)/2;
        if(calc(mid) < t){
            l = mid + 1;
        }
        else{
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}