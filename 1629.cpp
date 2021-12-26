#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
vector<pair<int,int>> v;
int cnt;
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    int last = 0;
    for(pair<int,int> p : v){
        if(p.second >= last){
            cnt++;
            last = p.first;
        }
    }
    cout << cnt << "\n";
    return 0;
}