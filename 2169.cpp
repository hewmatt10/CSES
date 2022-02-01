#include<bits/stdc++.h>
#define l first.first
#define r first.second
#define id second
#define range pair<pair<int,int>,int>
using namespace std;
typedef long long ll;
const int MN = 4e5+5;
bool sortleft(const pair<pair<ll,ll>,ll> f, const pair<pair<ll,ll>,ll> s){
    if(f.l == s.l){
        return f.r > s.r;
    }
    else{
        return f.l < s.l;
    }
}
int n;
range arr[MN];
ll contained [MN];
ll contains [MN];
ll bit [MN];

void update(int i, ll v){
    for(;i < MN; i+=(i&-i)){
        bit[i] += v;
    }
}

ll query(int i){
    ll ans = 0;
    for(; i > 0; i-=(i&-i)){
        ans += bit[i];
    }
    return ans;
}
int sorted[MN];
int dis[MN];
map<int,int> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i].l >> arr[i].r;
        sorted[2*i - 1] = arr[i].l;
        sorted[2*i] = arr[i].r;
        arr[i].id = i;
    }
    sort(sorted + 1, sorted + 2 * n + 1);
    for(int i = 1; i <= 2 * n; i++){
        dis[i] = lower_bound(sorted + 1, sorted + 2 * n + 1, sorted[i]) - sorted;
        mp.insert({sorted[i], dis[i]});
    }
    sort(arr + 1,arr + n + 1, sortleft);
    for(int i = n; i > 0; i--){
        contains[arr[i].id] = query(mp[arr[i].r]);
        update(mp[arr[i].r], 1);
    }
    for(int i = 1; i <= n; i++){
        cout << contains[i] << " ";
    }
    cout << "\n";
    memset(bit, 0, sizeof(bit));
    for(int i = 1; i <= n; i++){
        contained[arr[i].id] = i - 1 - query(mp[arr[i].r] - 1);
        update(mp[arr[i].r], 1);
    }
    for(int i = 1; i <= n; i++){
        cout << contained[i] << " ";
    }
    return 0;
}