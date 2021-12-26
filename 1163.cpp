#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n,x;

int main(){
    cin >> x >> n;
    set<int> s;
    map<int,int> mp;
    s.insert(0);
    s.insert(x);
    mp[x] = 1;
    for(int i = 0;i<n;i++){
        int p; cin >> p;
        auto it = s.lower_bound(p);
        int r = *it;
        it--;
        int l = *it;
        mp[r-l]--;
        if(mp[r-l] == 0){
            mp.erase(r-l);
        }
        s.insert(p);
        mp[r-p]++;
        mp[p-l]++;
        cout << ((--mp.end())->first) << " ";
    }
    return 0;
}