#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
set<pair<int,int>> s;
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int a, b;
        cin >> a >> b;
        s.insert({a,1});
        s.insert({b,-1});
    }
    int ans = 0, cur = 0;
    for(pair<int,int> p : s){
        cur += p.second;
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}