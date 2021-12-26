#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    for(int i = 0;i<n;i++){
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}