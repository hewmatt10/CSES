#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n,x;
vector<int> a;
vector<pair<int,pair<int,int>>> v;
map<int,pair<int,int>> mp;
int main(){
    cin >> n >> x; a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--) {
		for(int j = i - 1; j >= 0; j--) {
			int idx = x - a[i] - a[j];
			if(mp.find(idx) != mp.end()) {
				cout << i + 1 << " " << j + 1 << " " << mp[idx].f + 1 << " " << mp[idx].s + 1;
				return 0;
			}
		}

		for(int j = i + 1; j < n; j++) mp[a[i] + a[j]] = {i, j};
	}
    cout << "IMPOSSIBLE\n";

    return 0;
}