#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
int n, k;
ll x[MN];
multiset<ll> up;
multiset<ll> low;
ll sLow, sUp;

void ins(ll v){
    ll a = *low.rbegin();
    if(a < v){
        up.insert(v); sUp += v;
        if(up.size() > k/2){
            ll moving = *up.begin();
            low.insert(moving); sLow += moving;
            up.erase(up.find(moving)); sUp -= moving;
        }
    }
    else{
        low.insert(v); sLow += v;
        if(low.size() > (k + 1) / 2){
            ll moving = *low.rbegin();
            up.insert(moving); sUp += moving;
            low.erase(low.find(moving)); sLow -= moving;
        }
    }
}

void er(ll v){
    if(up.find(v) != up.end()){
        up.erase(up.find(v));
        sUp -= v;
    }
    else {
        low.erase(low.find(v));
        sLow -= v;
    } 
    if(low.empty()){
        ll moving = *up.begin();
        low.insert(moving); sLow += moving;
        up.erase(up.find(moving)); sUp -= moving;
    }
}

ll med(){return (k % 2 == 0) ? 0 : *(low.rbegin()); }

int main() {
	cin >> n >> k;
    for(ll i = 0; i < n; i++)cin >> x[i];
    low.insert(x[0]); sLow += x[0];
    for(int i = 1; i < k; i++) ins(x[i]);
    cout << abs(sUp - sLow + med()) << " ";
    for(ll i = k; i < n; i++){
        if(k == 1){
            ins(x[i]);
            er(x[i-k]);
        }
        else{
            er(x[i-k]);
            ins(x[i]);
        }
        cout << abs(sUp - sLow + med()) << " ";
    }
    cout << "\n";
}