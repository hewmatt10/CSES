#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, k; cin >> n >> k;
    vector<pair<int,int>> v (n);
    for(int i = 0; i < n; i++){
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    int mx = 0;
    multiset<int> s;
    for(int i = 0; i < k; i++) s.insert(0);
    for(int i = 0; i < n; i++){
        auto it = s.upper_bound(v[i].second);
        if(it == s.begin())continue;
        s.erase(--it);
        s.insert(v[i].first);
        mx++;
    }
    cout << mx << "\n";
}