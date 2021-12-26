#include<bits/stdc++.h>
using namespace std;
int n,m;
set<pair<int,int>>s;
int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int a;
        cin >> a;
        s.insert({a,i});
    }
    for(int i = 0;i<m;i++){
        int t; cin >> t;
        auto it = s.lower_bound({t+1,0});
        if(it == s.begin()){
            cout << "-1\n";
        }
        else{
            it--;
            cout << (*it).first << "\n";
            s.erase(it);
        }
    }
    return 0;
}