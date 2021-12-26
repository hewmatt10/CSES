#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MN = 7e4+4;
bool vis[MN];
 
int main(){
    ll n;
    cin >> n;
    vector<string> ans = {"0","1"};
    for(int i = 1;i<n;i++){
        int k = 1<<i;
        for(int j = k-1;j>=0;j--){
            ans.push_back("1"+ans[j]);
            ans[j] = "0" + ans[j];
        }
    }
    for(string s : ans){
        cout << s << "\n";
    }
    return 0;
}