#include<bits/stdc++.h>
using namespace std;
int n,x;
vector<pair<int,int>> v;
int main(){
    cin >> n >> x;
    for(int i = 1;i<=n;i++){
        int a;
        cin >> a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end());
    int l = 0, r = n - 1;
    while(l < r){
        if(v[l].first + v[r].first > x){
            r--;
        }
        else if(v[l].first + v[r].first < x){
            l++;
        }
        else{
            cout << v[l].second << " " << v[r].second << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}