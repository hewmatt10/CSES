#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n, k;
int arr[MN];
map<int,int> mp;
int main(){
    long long ans = 0;
    cin >> n >> k; for(int i = 0; i < n; i++){cin >> arr[i];}
    int l = 0;
    for(int r = 0; r < n; r++){
        if(mp.find(arr[r]) != mp.end()){
            mp[arr[r]]++;
        }
        else{
            mp.insert({arr[r],1});
        }
        while(mp.size() > k){
            if(mp[arr[l]] == 1){
                mp.erase(arr[l]);
            }
            else{
                mp[arr[l]]--;
            }
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << "\n";
    return 0;
}