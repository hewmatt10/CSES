#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 2e5+5;
int n; ll t[MN];
int main(){
    cin >> n;
    ll mx = 0;
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> t[i];
        tot += t[i];
        mx = max(mx, t[i]);
    }
    cout << max(tot, mx << 1) << "\n";
    return 0;
}