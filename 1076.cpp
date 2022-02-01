#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
typedef long long ll;
int n, k;
ll x[MN];
multiset<ll> up;
multiset<ll> low;

void ins(ll v){
    ll a = *low.rbegin();
    if(a < v){
        up.insert(v);
        if(up.size() > k/2){
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else{
        low.insert(v);
        if(low.size() > (k + 1) / 2){
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(ll v){
    if(up.find(v) != up.end()){
        up.erase(up.find(v));
    }
    else low.erase(low.find(v));
    if(low.empty()){
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    }
}


int main() {
	cin >> n >> k;
    for(int i = 0; i < n; i++)cin >> x[i];
    low.insert(x[0]); for(int i = 1; i < k; i++) ins(x[i]);
    cout << *low.rbegin() << " ";
    for(ll i = k; i < n; i++){
        if(k == 1){
            ins(x[i]);
            er(x[i-k]);
        }
        else{
            er(x[i-k]);
            ins(x[i]);
        }
        cout << *low.rbegin() << " ";
    }
    cout << "\n";
}