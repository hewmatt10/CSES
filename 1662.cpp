#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int MN = 2e5+5;
int n;
int arr[MN];
map<int,int> mp;
signed main(){
    cin >> n;
    ll ans = 0;
    mp.insert({0, 1});
    for(int i = 0; i < n; i++){
        cin >> arr[i]; arr[i] += arr[i-1];
        int m = arr[i] % n;
        while(m < 0) m += n;
        if(mp.find(m) != mp.end()){
            ans += mp[m];
            mp[m]++;
        }
        else{
            mp.insert({m,1});
        }
    }
    cout << ans << '\n';
    return 0;
}