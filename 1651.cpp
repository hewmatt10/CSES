#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 2e5+5;
int n, q;
ll arr[MN];
ll bit[MN];

ll query(int i){
    ll ans = 0;
    for(;i > 0; i-=(i&-i)){
        ans += bit[i];
    }
    return ans;
}
void update(int i, ll v){
    for(; i < MN; i+=(i&-i)){
        bit[i] += v;
    }
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= q; i++){
        int o; cin >> o;
        if(o == 1){
            int a, b, u; cin >> a >> b >> u;
            update(a, u);
            update(b + 1, -u);
        }
        else{
            int k; cin >> k;
            cout << query(k) + arr[k] << "\n"; 
        }
    }
    return 0;
}