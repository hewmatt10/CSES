#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> v;
vector<int> ans;
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first == b.first)return a.second > b.second;
    return a.first < b.first;
}
int main(){ 
    cin >> n; v.resize(n+1); ans.resize(n+1);
    v[0] = {0,0};
    for(int i = 1;i <= n; i++){
        int a; cin >> a;
        v[i] = {a,i};
    }
    sort(v.begin(), v.end(), cmp);
    set<int> s;
    s.insert(0);
    for(int i = 1; i <= n; i++){
        auto it = s.lower_bound(v[i].second);
        ans[v[i].second] = *(--it);
        s.insert(v[i].second);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}