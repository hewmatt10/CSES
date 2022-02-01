#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
int n;
ll x, arr [MN], psa[MN];
map<ll, ll> mp;
int main(){
    cin >> n >> x;
    ll ans = 0;
    mp.insert({0,1});
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        psa[i] = psa[i-1] + arr[i];
        if(mp.find(psa[i] - x) != mp.end()){
            ans += mp[psa[i] - x];
        }
        if(mp.find(psa[i]) != mp.end()){
            mp[psa[i]]++;
        }
        else{
            mp.insert({psa[i], 1LL});
        }
    }
    cout << ans << "\n";
    return 0;  
}