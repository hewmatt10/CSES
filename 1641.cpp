#include<bits/stdc++.h>
using namespace std;
const int MN = 5e3;
int n,x;
vector<pair<int,int>> arr;
int main(){
    cin >> n >> x; arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		int l, r; l = 0; r = n-1;
		while(l < r){
			int target = x - arr[i].first;
			if(l != i && r != i && arr[l].first + arr[r].first == target){
				cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
				return 0;
			}
			(arr[l].first + arr[r].first < target) ? l++ : r--;
		}
	}
	cout << "IMPOSSIBLE\n";
    return 0;
}