#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<ll,ll>> v;
int main(){
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    ll time = 0, ans = 0;
    for(auto p : v){
        time += p.first;
        ans += p.second - time; 
    }
    cout << ans << "\n";
    return 0;
}