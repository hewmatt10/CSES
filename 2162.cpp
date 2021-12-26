#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int n; cin >> n;
    for(int i = 0;i<n;i++)s.insert(i);
    int i = 1;
    while(!s.empty()){
        set<int> temp;
        for(int x : s){
            if(i == 0){
                cout << x + 1 << " ";
            }
            else{
                temp.insert(x);
            }
            i = (i+1)%2;
        }
        s = temp;
    }
    return 0;
}