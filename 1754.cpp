#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int main(){
    ll n;
    cin >> n;
    for(int i = 0,a,b;i<n;i++){
        cin >> a >> b;
        if((2*a-b) % 3 != 0 || (2*b-a) % 3 != 0){
            cout << "NO\n";
        }
        else if(2*a-b < 0|| 2*b-a < 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}