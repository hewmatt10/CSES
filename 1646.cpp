#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<long long> v;
int main(){
    cin >> n >> q;
    v.resize(n+1);
    for(int i = 1; i <= n;i++){
        cin >> v[i];
        v[i] += v[i-1];
    }
    for(int _ = 0; _ < q; _++){
        int a,b; cin >> a >> b;
        cout << v[b] - v[a-1] << "\n";
    }
    return 0;
}