#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 2e5+5;
int n, q;
ll arr [MN], bit[MN];

ll query(int i){
    ll ans = 0;
    for(;i > 0; i-=(i&-i)){
        ans += bit[i];
    }
    return ans;
}

void update(int i, ll v){
    for(int j = i; j < MN; j += (j&-j)){
        bit[j] = bit[j] - arr[i] + v;
    }
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        update(i, x);
        arr[i] = x;
    }
    for(int i = 0;i < q; i++){
        int o, a, b;
        cin >> o >> a >> b;
        if(o == 1){
            update(a, (ll)b);
            arr[a] = b;
        }
        else{
            cout << query(b) - query(a - 1) << "\n";
        }
    }
    return 0;
}