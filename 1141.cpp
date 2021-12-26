#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
map<int,int> mp;
int main(){
    cin >> n;
    int ans = 0;
    int l = 1;
    for(int r = 1;r<=n;r++){
        int x;
        cin >> x;
        if(mp[x]){
            ans = max(ans, r-l);
            l = max(l, mp[x]+1);
            mp[x] = r;
        } else {
            ans = max(ans, r-l+1);
            mp[x] = r;
        }
    }
    cout << max(ans, n - l + 1) << "\n";
    return 0;
}