#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int n;
vector<int> v;
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        int a; cin >> a;
        int p = upper_bound(v.begin(),v.end(),a) - v.begin();
        if(p < v.size()){
            v[p] = a;
        }
        else{
            v.push_back(a);
        }
    }
    cout << v.size();
    return 0;
}